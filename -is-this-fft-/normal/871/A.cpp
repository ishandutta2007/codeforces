#include <iostream>

using namespace std;

void solve () {
  int x;
  cin >> x;

  if (x == 1 || x == 2 || x == 3 || x == 5 || x == 7 || x == 11) {
    cout << -1 << '\n';
    return;
  }
  
  if (x % 4 == 0) {
    cout << x / 4 << '\n';
    return;
  }

  if (x % 4 == 1) {
    cout << 1 + (x - 9) / 4 << '\n';
    return;
  }

  if (x % 4 == 2) {
    cout << 1 + (x - 6) / 4 << '\n';
    return;
  }

  if (x % 4 == 3) {
    cout << 2 + (x - 6 - 9) / 4 << '\n';
    return;
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}