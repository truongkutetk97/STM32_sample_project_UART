// Example 2 - Receive with an end-marker

const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data
int ledstate=0;
boolean newData = false;

void setup() {
    Serial.begin(9600);
    //Serial.println("<Arduino is ready>");
    pinMode(13,OUTPUT);
    digitalWrite(13,ledstate%2);
    ledstate++;
}

void loop() {
    recvWithEndMarker();
    showNewData();
}

void recvWithEndMarker() {
    static byte ndx = 0;
    char endMarker = '\n';
    char rc;
    
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (rc != endMarker) {
            receivedChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
        }
        else {
            receivedChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }
}

void showNewData() {
    if (newData == true) {
        //Serial.print("This just in ... ");
        Serial.println("231");
        //Serial.print("abc");
        newData = false;
        digitalWrite(13,ledstate%2);
         ledstate++;
    }
}
