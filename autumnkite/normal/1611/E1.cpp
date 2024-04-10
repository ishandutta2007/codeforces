#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> x(m);
    for (int i = 0; i < m; ++i) {
      std::cin >> x[i];
      --x[i];
    }
    std::vector<std::vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      std::cin >> u >> v;
      --u, --v;
      E[u].push_back(v);
      E[v].push_back(u);
    }

    int lg = std::__lg(n) + 1;
    std::vector<std::vector<int>> fa(n, std::vector<int>(lg, -1));
    std::vector<int> dep(n);

    auto dfs = [&](auto &self, int u) -> void {
      for (int i = 1; i < lg && fa[u][i - 1] != -1; ++i) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
      }
      for (int v : E[u]) {
        if (v != fa[u][0]) {
          fa[v][0] = u;
          dep[v] = dep[u] + 1;
          self(self, v);
        }
      }
    };

    dfs(dfs, 0);

    std::vector<int> cnt(n);
    for (int i = 0; i < m; ++i) {
      int u = x[i], k = dep[u] / 2;
      for (int j = 0; j < lg; ++j) {
        if (k >> j & 1) {
          u = fa[u][j];
        }
      }
      ++cnt[u];
    }

    int ans = 0;

    auto calc = [&](auto &self, int u) -> bool {
      if (cnt[u]) {
        ++ans;
        return true;
      }
      if (E[u].size() == 1 && u != 0) {
        return false;
      }
      for (int v : E[u]) {
        if (v != fa[u][0]) {
          if (!self(self, v)) {
            return false;
          }
        }
      }
      return true;
    };

    std::cout << (calc(calc, 0) ? "NO" : "YES") << "\n";
  }
}