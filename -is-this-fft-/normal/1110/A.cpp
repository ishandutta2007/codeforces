#include <iostream>

using namespace std;

const int maxn = 1000005;
int arr [maxn];

int main () {
  int base, length;
  cin >> base >> length;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }

  if (base % 2 == 0) {
    if (arr[length - 1] % 2 == 0) {
      cout << "even" << endl;
    } else {
      cout << "odd" << endl;
    }
  } else {
    int parity = 0;
    for (int i = 0; i < length; i++) {
      parity += arr[i];
      parity %= 2;
    }

    cout << (parity ? "odd" : "even") << endl;
  }
}