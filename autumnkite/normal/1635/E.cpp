#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> E(n);
  for (int i = 0; i < m; ++i) {
    int op, x, y;
    std::cin >> op >> x >> y;
    --op, --x, --y;
    E[x].emplace_back(y, op);
    E[y].emplace_back(x, op);
  }

  std::vector<int> col(n, -1);

  auto dfs = [&](auto &self, int u, int c) -> bool {
    if (col[u] != -1) {
      return col[u] == c;
    }
    col[u] = c;
    for (auto [v, op] : E[u]) {
      if (!self(self, v, c ^ 1)) {
        return false;
      }
    }
    return true;
  };

  for (int i = 0; i < n; ++i) {
    if (col[i] == -1 && !dfs(dfs, i, 0)) {
      std::cout << "NO\n";
      return 0;
    }
  }

  std::vector<std::vector<int>> G(n);
  std::vector<int> deg(n);
  for (int u = 0; u < n; ++u) {
    for (auto [v, op] : E[u]) {
      if (col[u] == op && col[v] == !op) {
        G[u].push_back(v);
        ++deg[v];
      }
    }
  }
  std::vector<int> Q;
  for (int i = 0; i < n; ++i) {
    if (!deg[i]) {
      Q.push_back(i);
    }
  }
  for (int i = 0; i < (int)Q.size(); ++i) {
    int u = Q[i];
    for (int v : G[u]) {
      --deg[v];
      if (!deg[v]) {
        Q.push_back(v);
      }
    }
  }
  if ((int)Q.size() < n) {
    std::cout << "NO\n";
    return 0;
  }
  std::vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[Q[i]] = i;
  }
  std::cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    std::cout << (col[i] ? 'R' : 'L') << " " << ans[i] << "\n";
  }
}