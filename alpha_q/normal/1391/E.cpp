#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

bitset <N> vis;
int t, n, m, mx, p[N];
vector <int> g[N], layer[N];

void go (int u = 1, int pr = -1, int far = 0) {
  mx = max(mx, far), vis[u] = 1;
  p[u] = pr, layer[far].emplace_back(u);
  for (int v : g[u]) if (!vis[v]) go(v, u, far + 1);
}

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; ++i) {
      g[i].clear(), layer[i].clear(), vis[i] = 0;
    }
    while (m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    mx = 0; go();
    if (mx + 1 >= (n + 1) / 2) {
      puts("PATH");
      printf("%d\n", mx + 1);
      assert(!layer[mx].empty());
      int u = layer[mx][0];
      while (u != -1) {
        printf("%d ", u);
        u = p[u];
      }
      puts("");
    } else {
      puts("PAIRING");
      vector <pair <int, int>> ans;
      for (int i = 0; i <= mx; ++i) {
        for (int j = 0; j + 1 < layer[i].size(); j += 2) {
          ans.emplace_back(layer[i][j], layer[i][j + 1]);
        }
      }
      assert(ans.size() * 2 >= (n + 1) / 2);
      printf("%d\n", (int) ans.size());
      for (auto it : ans) printf("%d %d\n", it.first, it.second);
    }
  }
  return 0;
}