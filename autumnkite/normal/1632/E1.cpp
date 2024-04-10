#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      std::cin >> u >> v;
      --u, --v;
      E[u].push_back(v);
      E[v].push_back(u);
    }

    std::vector<int> dep(n), max(n), sec(n), dis(n);

    auto dfs1 = [&](auto &self, int u, int fa) -> void {
      max[u] = sec[u] = 0;
      dis[u] = 0;
      for (int v : E[u]) {
        if (v != fa) {
          dep[v] = dep[u] + 1;
          self(self, v, u);
          if (max[v] + 1 > max[u]) {
            sec[u] = max[u];
            max[u] = max[v] + 1;
          } else if (max[v] + 1 > sec[u]) {
            sec[u] = max[v] + 1;
          }
          dis[u] = std::max(dis[u], dis[v]);
        }
      }
      dis[u] = std::max(dis[u], max[u] + sec[u]);
    };

    dfs1(dfs1, 0, -1);

    std::vector<int> f(n + 1, max[0]), g(n + 1, max[0]);

    auto dfs2 = [&](auto &self, int u, int fa, int out) -> void {
      if (fa != -1) {
        int a = out, b = (dis[u] + 1) / 2;
        int x = std::max(a - b, 0);
        f[x] = std::min(f[x], a);
        g[x] = std::min(g[x], b);
      }
      for (int v : E[u]) {
        if (v != fa) {
          int tmp;
          if (max[v] + 1 == max[u]) {
            tmp = dep[u] + sec[u];
          } else {
            tmp = dep[u] + max[u];
          }
          self(self, v, u, std::max(tmp, out));
        }
      }
    };

    dfs2(dfs2, 0, -1, 0);

    for (int i = n - 1; i >= 1; --i) {
      f[i] = std::min(f[i], f[i + 1]);
    }
    for (int i = 1; i <= n; ++i) {
      g[i] = std::min(g[i], g[i - 1]);
    }
    for (int i = 1; i <= n; ++i) {
      std::cout << std::min(f[i], g[i] + i) << " \n"[i == n];
    }
  }
}