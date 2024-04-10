#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, lim;
  std::cin >> n >> lim;
  std::vector<std::vector<int>> E(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  std::vector<int> fa(n, -1), dis(n), son(n);

  auto dfs = [&](auto &self, int u) -> void {
    son[u] = -1;
    dis[u] = 0;
    for (int v : E[u]) {
      if (v != fa[u]) {
        fa[v] = u;
        self(self, v);
        if (son[u] == -1 || dis[v] > dis[son[u]]) {
          son[u] = v;
          dis[u] = dis[v] + 1;
        }
      }
    }
  };

  dfs(dfs, 0);

  std::vector<int> len;
  for (int i = 0; i < n; ++i) {
    if (fa[i] == -1 || son[fa[i]] != i) {
      len.push_back(dis[i]);
    }
  }

  if (lim >= (int)len.size()) {
    int t = std::max((int)len.size(), std::min(n / 2, lim));
    std::cout << 1ll * t * (n - t) << "\n";
    return 0;
  }

  std::nth_element(len.begin(), len.begin() + lim, len.end(), std::greater<int>());
  int sum = 0;
  for (int i = 0; i < lim; ++i) {
    sum += len[i];
  }
  long long ans = std::numeric_limits<long long>::max();
  for (int i = 0; i <= n - lim - sum; ++i) {
    ans = std::min(ans, 1ll * (n - lim - i) * (lim - i));
  }
  std::cout << ans << "\n";
}