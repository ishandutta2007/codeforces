#include <iostream>

using namespace std;

const int INF = 2e9 + 15;

void solve () {
  int n, x, y, d;
  cin >> n >> x >> y >> d;
  x--;y--;

  if (x % d == y % d) {
    cout << abs((x - y) / d) << '\n';
    return;
  }

  int vl = INF;
  if (y % d == 0) {
    vl = (x + d - 1) / d + y / d;
  }
  int vr = INF;
  if (y % d == (n - 1) % d) {
    vr = (n - 1 - x + d - 1) / d + (n - 1 - y) / d;
  }

  int ans = min(vl, vr);
  if (ans == INF) cout << -1 << '\n';
  else cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int t = 0; t < testc; t++) {
    solve();
  }
}