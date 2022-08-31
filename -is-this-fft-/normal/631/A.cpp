#include <iostream>

using namespace std;

int main () {
  int aor = 0, bor = 0;
  
  int length;
  cin >> length;
  for (int i = 0; i < length; i++) {
    int el;
    cin >> el;
    aor |= el;
  }

  for (int i = 0; i < length; i++) {
    int el;
    cin >> el;
    bor |= el;
  }

  cout << aor + bor << endl;
}