#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; ++i)
#define Y second

int n, m, k, a[256][256];
char s[1<<18], c;
std::map<int, char> d;

int main() {
  scanf("%d%d%d%s", &n, &m, &k, s);
  REP(i, n-1) if (s[i] != s[i+1]) {
    ++a[s[i]][s[i+1]];
    d[i+1] = s[i];
  }
  d[n] = s[n-1];

  REP(u, m) {
    int o, l, r;
    scanf("%d", &o);
    if (o == 1) {
      scanf("%d%d%c%c", &l, &r, &c, &c);
      auto il = d.lower_bound(--l), ir = d.lower_bound(r+1);
      char t = il->Y;
      if (il == ir) {
        if (t != c) ++a[c][t], d[r] = c;
      } else {
        for (auto it = il; ++it != ir; --a[t][it->Y], t = it->Y);
        if (ir != d.end()) --a[t][ir->Y];
        for (t = il->Y; il != ir; ) {
          auto it = il;
          ++il;
          d.erase(it);
        }
        if (ir != d.end() && ir->Y != c) ++a[c][ir->Y];
        if (ir == d.end() || ir->Y != c) d[r] = c;
      }
      if (l && t != c) ++a[t][c], d[l] = t;
    } else {
      scanf("%s", s);
      int ans = n;
      REP(i, k) REP(j, k-i) ans -= a[s[i]][s[i+j+1]];
      printf("%d\n", ans);
    }
  }
  return 0;
}