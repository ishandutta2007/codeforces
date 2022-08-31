#include <iostream>

using namespace std;

int main () {
  int even, odd;
  cin >> even >> odd;

  if (even == 0 && odd == 0) {
    cout << "NO" << endl;
  } else if (even - odd <= 1 && even - odd >= -1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}