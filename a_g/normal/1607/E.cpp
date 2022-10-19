#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    string s;
    cin >> n >> m >> s;
    int l = 0, r = 0, d = 0, u = 0, x = 0, y = 0;
    for (char c: s) {
      if (c == 'L') x--;
      if (c == 'R') x++;
      if (c == 'U') y--;
      if (c == 'D') y++;
      int nl = min(l, x);
      int nr = max(r, x);
      int nu = min(u, y);
      int nd = max(d, y);
      if (nr - nl >= m || nd - nu >= n) break;
      l = nl;
      r = nr;
      u = nu;
      d = nd;
    }
    cout << 1-u << " " << 1-l << '\n';
  }
}