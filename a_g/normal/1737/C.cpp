#include <bits/stdc++.h>
using namespace std;

int r[3], c[3];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int d[4] = {0, 0, 0, 0};
    for (int i = 0; i < 3; i++) {
      cin >> r[i] >> c[i];
      d[2*(r[i]&1)+(c[i]&1)] = 1;
    }
    int cx = (r[0] == r[1] ? r[0] : r[2]);
    int cy = (c[0] == c[1] ? c[0] : c[2]);
    bool cornered = ((cx == 1 || cx == n) && (cy == 1 || cy == n));
    int x, y;
    cin >> x >> y;
    bool ok = d[2*(x&1)+(y&1)];
    if (cornered) {
      ok = (x == cx || y == cy);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}