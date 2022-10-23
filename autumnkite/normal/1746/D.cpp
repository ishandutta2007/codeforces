#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> fa(n, -1);
    std::vector<std::vector<int>> E(n);
    for (int i = 1; i < n; ++i) {
      std::cin >> fa[i];
      --fa[i];
      E[fa[i]].push_back(i);
    }
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    std::vector<int> val(n);
    std::vector<std::array<long long, 2>> f(n);

    auto dfs = [&](auto &self, int u) -> void {
      int d = E[u].size();
      f[u][0] = 1ll * val[u] * a[u];
      f[u][1] = 1ll * (val[u] + 1) * a[u];
      if (!d) {
        return;
      }
      for (int v : E[u]) {
        val[v] = val[u] / d;
        self(self, v);
      }
      for (int i = 0; i < 2; ++i) {
        int r = (val[u] + i) % d;
        std::vector<long long> w;
        for (int v : E[u]) {
          int t = (val[u] + i) / d - val[v];
          f[u][i] += f[v][t];
          w.push_back(f[v][(val[u] + i + d - 1) / d - val[v]] - f[v][t]);
        }
        std::nth_element(w.begin(), w.begin() + r, w.end(),
                         std::greater<long long>());
        f[u][i] += std::accumulate(w.begin(), w.begin() + r, 0ll);
      }
    };

    val[0] = k;
    dfs(dfs, 0);
    std::cout << f[0][0] << "\n";
  }
}