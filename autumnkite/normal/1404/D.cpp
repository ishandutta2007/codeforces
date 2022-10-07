#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  if (n & 1) {
    std::cout << "Second" << std::endl;
    std::vector<int> b(2 * n), r(2 * n);
    std::vector<std::vector<int>> p(n);
    for (int i = 1; i <= 2 * n; ++i) {
      int t = i % (2 * n);
      std::cin >> b[t];
      --b[t];
      r[t] = p[b[t]].size();
      p[b[t]].push_back(i);
    }
    std::vector<std::vector<std::pair<int, int>>> E(n);
    for (int i = 0; i < n; ++i) {
      int w = r[i] ^ r[i + n] ^ 1;
      E[b[i]].emplace_back(b[i + n], w);
      E[b[i + n]].emplace_back(b[i], w);
    }
    std::vector<int> col(n, -1);

    auto dfs = [&](auto &self, int u, int c) -> void {
      if (col[u] != -1) {
        return;
      }
      col[u] = c;
      for (auto [v, w] : E[u]) {
        self(self, v, c ^ w);
      }
    };

    for (int i = 0; i < n; ++i) {
      if (col[i] == -1) {
        dfs(dfs, i, 0);
      }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum = (sum + p[i][col[i]]) % (2 * n);
    }
    if (sum != 0) {
      for (int i = 0; i < n; ++i) {
        col[i] ^= 1;
      }
    }
    for (int i = 0; i < n; ++i) {
      std::cout << p[i][col[i]] << " ";
    }
    std::cout << std::endl;
  } else {
    std::cout << "First" << std::endl;
    for (int i = 0; i < 2 * n; ++i) {
      std::cout << i % n + 1 << " ";
    }
    std::cout << std::endl;
  }
  int res;
  std::cin >> res;
}