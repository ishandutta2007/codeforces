#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> len(n);
  std::map<int, int> lst;
  int idx = 0;
  std::vector<std::pair<int, int>> edge;
  for (int i = 0; i < n; ++i) {
    std::cin >> len[i];
    std::vector<int> a(len[i]);
    for (int &x : a) {
      std::cin >> x;
    }
    for (int j = 0; j < len[i]; ++j) {
      if (lst.count(a[j])) {
        edge.emplace_back(lst[a[j]], idx);
        lst.erase(a[j]);
      } else {
        lst[a[j]] = idx;
      }
      if (idx & 1) {
        edge.emplace_back(idx - 1, idx);
      }
      idx++;
    }
  }
  if (!lst.empty()) {
    std::cout << "NO\n";
    return 0;
  }

  std::vector<std::vector<int>> G(idx);
  for (auto [u, v] : edge) {
    G[u].push_back(v);
    G[v].push_back(u);
  }
  std::vector<int> col(idx, -1);

  auto dfs = [&](auto &self, int u, int c) -> bool {
    if (col[u] != -1) {
      return col[u] == c;
    }
    col[u] = c;
    for (int v : G[u]) {
      if (!self(self, v, c ^ 1)) {
        return false;
      }
    }
    return true;
  };

  for (int i = 0; i < idx; ++i) {
    if (col[i] == -1 && !dfs(dfs, i, 0)) {
      std::cout << "NO\n";
      return 0;
    }
  }

  std::cout << "YES\n";
  int now = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < len[i]; ++j) {
      std::cout << (col[now++] ? 'L' : 'R');
    }
    std::cout << "\n";
  }
}