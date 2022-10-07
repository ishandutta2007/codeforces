#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int p;
    std::cin >> p;
    int n = 1 << p;
    std::vector<std::pair<int, int>> edge;
    std::vector<std::vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      std::cin >> u >> v;
      --u, --v;
      edge.emplace_back(u, v);
      E[u].push_back(v);
      E[v].push_back(u);
    }

    std::vector<int> dep(n);

    auto dfs = [&](auto &self, int u, int fa) -> void {
      for (int v : E[u]) {
        if (v != fa) {
          dep[v] = dep[u] + 1;
          self(self, v, u);
        }
      }
    };

    dfs(dfs, 0, -1);
    std::cout << 1 << "\n";
    std::string sep = "";
    for (int i = 0; i < n; ++i) {
      std::cout << sep << (!(dep[i] & 1) << p | i);
      sep = " ";
    }
    std::cout << "\n";
    sep = "";
    for (auto [u, v] : edge) {
      if (dep[u] < dep[v]) {
        std::swap(u, v);
      }
      std::cout << sep << ((dep[u] & 1) << p | u);
      sep = " ";
    }
    std::cout << "\n";
  }
}