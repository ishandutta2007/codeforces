#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

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

  std::vector<int> d(n);
  std::vector<std::vector<int>> f(n), g(n);

  auto dfs = [&](auto &self, int u, int fa) -> void {
    d[u] = 0;
    for (int v : E[u]) {
      if (v != fa) {
        self(self, v, u);
        ++d[u];
      }
    }
    f[u].resize(d[u]);
    for (int v : E[u]) {
      if (v != fa) {
        f[u].resize(std::max(f[u].size(), f[v].size()));
        for (int k = 0; k < (int)f[v].size(); ++k) {
          f[u][k] += f[v][k] - 1;
        }
      }
    }
    g[u] = f[u];
    for (int k = 0; k < (int)f[u].size(); ++k) {
      f[u][k] += d[u] - k;
    }
    while (!f[u].empty() && f[u].back() <= 0) {
      f[u].pop_back();
    }
  };

  dfs(dfs, 0, -1);
  
  int q;
  std::cin >> q;
  while (q--) {
    int v, k;
    std::cin >> v >> k;
    --v;
    std::cout << (k < (int)g[v].size() ? g[v][k] + d[v] : d[v]) << "\n";
  }
}