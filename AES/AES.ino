/*
 Name:		AES.ino
 Created:	3/9/2016 10:02:17 AM
 Author:	reysd
*/


#include <AESLib.h>

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
	uint8_t key[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
  uint8_t iv[] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
	char data[] = "3135136217"; //16 chars == 16 bytes
  char cs;
  char tmp[sizeof(data)];
	//aes128_enc_single(key, data);
  aes128_cbc_enc(key, iv, data, 16);
	Serial.print("encrypted:");
	Serial.println(data);
  saveData(data, tmp);
  //cs = checksum(data);
  //Serial.print("Checksum : "); Serial.println(cs, HEX);
  //saveData(data, copy);
  printChar(data, sizeof(data));
	//aes128_dec_single(key, data);
  aes128_cbc_dec(key, iv, tmp, 16);
	Serial.print("decrypted:");
	Serial.println(tmp);

 delay(10000);
}

void printChar(char *data, int dataSize) {
  for (int i = 0; i < dataSize; i++) {
    Serial.print(" ");
    Serial.print(data[i]);
  }
  Serial.println();
}

char checksum(char *data) {
  char sum = data[0];
  for (int i = 1; i < 16; i++) {
    sum = sum ^ data[i];
  }
}

void saveData (char *data, char *tmp) {
  for (int i = 0; i < 16; i++) {
    tmp[i] = data[i];
  }
}

