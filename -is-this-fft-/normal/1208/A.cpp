#include <iostream>

using namespace std;

int main () {
  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    int a, b, n;
    cin >> a >> b >> n;

    if (n % 3 == 0) {
      cout << a << '\n';
    } else if (n % 3 == 1) {
      cout << b << '\n';
    } else {
      cout << (a ^ b) << '\n';
    }
  }
}