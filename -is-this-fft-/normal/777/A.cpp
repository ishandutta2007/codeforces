#include <iostream>

using namespace std;

int main () {
  int movec, loc;
  cin >> movec >> loc;

  movec %= 6;
  if (loc == 0) {
    if (movec == 0 || movec == 5) {
      cout << 0 << endl;
    } else if (movec == 1 || movec == 2) {
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
    }
  } else if (loc == 1) {
    if (movec == 1 || movec == 4) {
      cout << 0 << endl;
    } else if (movec == 0 || movec == 3) {
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
    }
  } else {
    if (movec == 2 || movec == 3) {
      cout << 0 << endl;
    } else if (movec == 4 || movec == 5) {
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
    }
  }
}