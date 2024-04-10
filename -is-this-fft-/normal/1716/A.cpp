#include <iostream>

using namespace std;

void solve () {
  int n;
  cin >> n;

  if (n == 1) cout << 2 << '\n';
  else cout << (n + 2) / 3 << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}