#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int t, n, m;
bitset <N> vis, ind;

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= 3 * n; ++i) vis[i] = 0;
    for (int i = 1; i <= m; ++i) ind[i] = 0;
    int sz = 0;
    for (int i = 1, u, v; i <= m; ++i) {
      scanf("%d %d", &u, &v);
      if (vis[u] or vis[v]) continue;
      vis[u] = vis[v] = ind[i] = 1, ++sz;
    }
    if (sz >= n) {
      puts("Matching");
      for (int i = 1, j = n; i <= m and j > 0; ++i) {
        if (ind[i]) printf("%d ", i), --j;
      }
      puts(""); continue;
    }
    puts("IndSet");
    for (int i = 1, j = n; i <= 3 * n and j > 0; ++i) {
      if (!vis[i]) printf("%d ", i), --j;
    }
    puts("");
  }
  return 0;
}