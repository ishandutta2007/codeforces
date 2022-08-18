#include <iostream>

const int MAX_DMG = 10105;

using namespace std;

bool possib [MAX_DMG];

int main () {
  int ivory, ebony, target;
  cin >> ivory >> ebony >> target;

  possib[0] = true;
  for (int i = 0; i < target; i++) {
    if (possib[i]) {
      possib[i + ivory] = true;
      possib[i + ebony] = true;
    }
  }

  cout << (possib[target] ? "Yes" : "No") << endl;
}