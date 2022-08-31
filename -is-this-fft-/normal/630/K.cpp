#include <iostream>

const long long LCM = 2520;

using namespace std;

bool bonus [LCM];
int bonusc [LCM];

int main () {
  for (int i = 0; i < LCM; i++) {
    bonus[i] = true;
    for (int j = 2; j <= 10; j++) {
      bonus[i] &= (i % j != 0);
    }
  }

  for (int i = 1; i < LCM; i++) {
    bonusc[i] = bonusc[i - 1] + bonus[i];
  }

  long long peoplec;
  cin >> peoplec;
  cout << (peoplec / LCM) * bonusc[LCM - 1] + bonusc[peoplec % LCM] << endl;
}