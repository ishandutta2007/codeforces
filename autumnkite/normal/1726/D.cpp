#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> E(n);
    for (int i = 0; i < m; ++i) {
      int u, v;
      std::cin >> u >> v;
      --u, --v;
      E[u].emplace_back(v, i);
      E[v].emplace_back(u, i);
    }

    std::vector<int> fi(n, -1);
    std::vector<bool> vis(n);
    std::vector<int> dep(n);
    std::vector<bool> col(m);
    std::vector<std::pair<int, int>> ids;
    std::vector<int> deg(n);

    auto dfs = [&](auto &self, int u, int fa) -> void {
      vis[u] = true;
      for (auto [v, id] : E[u]) {
        if (v != fa) {
          if (!vis[v]) {
            dep[v] = dep[u] + 1;
            fi[v] = id;
            self(self, v, u);
            col[id] = 0;
          } else if (dep[v] < dep[u]) {
            col[id] = 1;
            ids.emplace_back(id, u);
            ++deg[u], ++deg[v];
          }
        }
      }
    };

    dfs(dfs, 0, -1);
    if (ids.size() == 3 && std::find(deg.begin(), deg.end(), 1) == deg.end()) {
      col[ids[0].first] = 0;
      col[fi[ids[0].second]] = 1;
    }
    for (int i = 0; i < m; ++i) {
      std::cout << int(col[i]);
    }
    std::cout << "\n";
  }
}