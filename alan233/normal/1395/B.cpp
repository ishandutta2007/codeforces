#pragma GCC target("avx", "avx2")
#include <bits/stdc++.h>
using namespace std;

int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}

int n, m, sx, sy;

inline int go(int where, int dist, int lim) {
  where += dist;
  while (where >= lim) where -= lim;
  return where;  
}

int main() {
  n = read(), m = read(), sx = read(), sy = read();
  sx--, sy--;
  for (int i = 0; i < n; i++) {
    if (~i & 1) {
      for (int j = 0; j < m; j++)
        printf("%d %d\n", go(sx, i, n) + 1, go(sy, j, m) + 1);
    } else {
      for (int j = 0; j < m; j++)
        printf("%d %d\n", go(sx, i, n) + 1, go(sy, m - 1 - j, m) + 1);
    }
  }
}