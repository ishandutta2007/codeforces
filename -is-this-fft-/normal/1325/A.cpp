#include <iostream>

using namespace std;

void solve () {
  int x;
  cin >> x;

  cout << 1 << " " << x - 1 << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}