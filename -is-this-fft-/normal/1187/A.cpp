#include <iostream>

using namespace std;

void solve () {
  int eggc, stickerc, toyc;
  cin >> eggc >> stickerc >> toyc;

  int bothc = stickerc + toyc - eggc;
  stickerc -= bothc;
  toyc -= bothc;

  cout << max(stickerc, toyc) + 1 << '\n';
}

int main () {
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}