#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int t, n;
bitset <N> vis;
vector <int> g[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      int sz, x; 
      scanf("%d", &sz);
      g[i].clear();
      while (sz--) {
        scanf("%d", &x);
        g[i].emplace_back(x);
      }
      vis[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      for (int x : g[i]) if (!vis[x]) {
        vis[x] = 1; break;
      }
    }
    int tot = 0;
    for (int i = 1; i <= n; ++i) {
      if (vis[i]) ++tot;
    }
    if (tot == n) {
      puts("OPTIMAL");
      continue;
    }
    int at = 1;
    while (vis[at]) ++at;
    for (int i = 1; i <= n; ++i) {
      vis[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      bool ok = 0;
      for (int x : g[i]) if (!vis[x]) {
        vis[x] = 1; ok = 1; break;
      }
      if (ok) continue;
      printf("IMPROVE\n%d %d\n", i, at);
      break;
    }
  }
  return 0;
}