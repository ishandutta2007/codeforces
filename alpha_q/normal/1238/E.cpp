#include <bits/stdc++.h>

using namespace std;

const int M = 22;
const int N = 100010;
const int MASK = (1 << 20) + 5;

char s[N]; int n, m, d[M], cnt[M][M], f[MASK];

int main() {
  scanf("%d %d %s", &n, &m, s + 1);
  for (int i = 1; i < n; ++i) {
    char x = s[i] - 'a', y = s[i + 1] - 'a';
    if (x ^ y) ++cnt[x][y], ++cnt[y][x], ++d[x], ++d[y];
  }
  int done = (1 << m) - 1; f[done] = 0;
  for (int mask = done - 1; mask >= 0; --mask) {
    f[mask] = INT_MAX;
    int cur = __builtin_popcount(mask);
    for (int i = 0; i < m; ++i) if (~mask & 1 << i) {
      int cost = 0;
      for (int j = 0; j < m; ++j) if (mask & 1 << j) cost += cnt[i][j];
      cost = cur * (cost + cost - d[i]);
      f[mask] = min(f[mask], cost + f[mask | 1 << i]);
    }
  }
  cout << f[0] << '\n';
  return 0;
}