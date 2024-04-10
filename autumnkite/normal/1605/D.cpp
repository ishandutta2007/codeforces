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

    std::vector<int> p[2];

    auto dfs = [&](auto &self, int u, int fa, int d) -> void {
      p[d].push_back(u);
      for (int v : E[u]) {
        if (v != fa) {
          self(self, v, u, d ^ 1);
        }
      }
    };

    dfs(dfs, 0, -1, 0);

    int lg = std::__lg(n);
    std::vector<int> bel(lg + 1);
    int tmp = p[1].size();
    for (int i = lg; i >= 0; --i) {
      int c = std::min(1 << (i + 1), n + 1) - (1 << i);
      if (tmp >= c) {
        tmp -= c;
        bel[i] = 1;
      }
    }

    std::vector<int> ans(n);
    std::array it = {p[0].begin(), p[1].begin()};
    for (int i = 0; i <= lg; ++i) {
      for (int j = 1 << i; j <= n && j < (1 << (i + 1)); ++j) {
        ans[*(it[bel[i]]++)] = j;
      }
    }
    for (int i = 0; i < n; ++i) {
      std::cout << ans[i] << " \n"[i + 1 == n];
    }
  }
}