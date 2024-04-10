#include <iostream>

typedef long long llong;

const int MAX_LEN = 90;

using namespace std;

llong fib [MAX_LEN];

int main () {
  fib[0] = 1;
  fib[1] = 1;
  for (int i = 2; i < MAX_LEN; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  llong playerc;
  cin >> playerc;
  for (int i = 2; i < MAX_LEN; i++) {
    if (fib[i] > playerc) {
      cout << i - 2 << endl;
      break;
    }
  }
}