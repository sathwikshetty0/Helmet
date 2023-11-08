const int numMicrophones = 6;
const int microphonePins[numMicrophones] = {0,1,2,3,4,5};
const int vibratorPins[numMicrophones] = {7,8,9,10,11,6};

int microphoneValues[numMicrophones];

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < numMicrophones; i++) {
    pinMode(vibratorPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < numMicrophones; i++) {
    microphoneValues[i] = analogRead(microphonePins[i]);
  }

  int greatestValue = 0;
  int secondGreatestValue = 0;
  int greatestIndex = -1;
  int secondGreatestIndex = -1;

  for (int i = 0; i < numMicrophones; i++) {
    if (microphoneValues[i] > greatestValue) {
      secondGreatestValue = greatestValue;
      secondGreatestIndex = greatestIndex;
      greatestValue = microphoneValues[i];
      greatestIndex = i;
    } else if (microphoneValues[i] > secondGreatestValue) {
      secondGreatestValue = microphoneValues[i];
      secondGreatestIndex = i;
    }
  }

  for (int i = 0; i < numMicrophones; i++) {
    if (i == greatestIndex || i == secondGreatestIndex) {
      digitalWrite(vibratorPins[i], HIGH);  
    } else {
      digitalWrite(vibratorPins[i], LOW);  
    }
  }

  Serial.print("Microphone values: ");
  for (int i = 0; i < numMicrophones; i++) {
    Serial.print(microphoneValues[i]);
    Serial.print(" ");
  }
  Serial.println();

  Serial.print("Two greatest values: ");
  Serial.print(greatestValue);
  Serial.print(" ");
  Serial.println(secondGreatestValue);

  Serial.println("------");

  delay(50);  
}