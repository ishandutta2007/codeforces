#include <iostream>

using namespace std;

void solve () {
  int st, in, ex;
  cin >> st >> in >> ex;

  st -= in;

  int mx = st + ex;
  int mn = max(st - ex, 1);
  if (mn > mx) cout << 0 << '\n';
  else cout << (mx - mn + 2) / 2 << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int i = 0; i < testc; i++) {
    solve();
  }
}