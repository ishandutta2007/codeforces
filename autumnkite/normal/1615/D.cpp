#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::tuple<int, int, int>> edge;
    std::vector<std::vector<std::pair<int, int>>> E(n);
    for (int i = 0; i < n - 1; ++i) {
      int u, v, w;
      std::cin >> u >> v >> w;
      --u, --v;
      edge.emplace_back(u, v, w);
      if (w != -1) {
        w = __builtin_parity(w);
        E[u].emplace_back(v, w);
        E[v].emplace_back(u, w);
      }
    }
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      std::cin >> u >> v >> w;
      --u, --v;
      E[u].emplace_back(v, w);
      E[v].emplace_back(u, w);
    }

    std::vector<int> col(n, -1);

    auto dfs = [&](auto &self, int u, int c) -> bool {
      if (col[u] != -1) {
        return col[u] == c;
      }
      col[u] = c;
      for (auto [v, d] : E[u]) {
        if (!self(self, v, c ^ d)) {
          return false;
        }
      }
      return true;
    };

    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (col[i] == -1 && !dfs(dfs, i, 0)) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
      for (auto [u, v, w] : edge) {
        if (w == -1) {
          std::cout << u + 1 << " " << v + 1 << " " << (col[u] ^ col[v]) << "\n";
        } else {
          std::cout << u + 1 << " " << v + 1 << " " << w << "\n";
        }
      }
    }
  }
}