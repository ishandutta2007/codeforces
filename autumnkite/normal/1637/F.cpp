#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> E(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  int rt = std::max_element(a.begin(), a.end()) - a.begin();
  long long ans = 0;

  auto dfs = [&](auto &self, int u, int fa) -> int {
    int max = 0;
    for (int v : E[u]) {
      if (v != fa) {
        max = std::max(max, self(self, v, u));
      }
    }
    if (a[u] > max) {
      ans += a[u] - max;
      max = a[u];
    }
    return max;
  };

  int max = 0, sec = 0;
  for (int u : E[rt]) {
    int v = dfs(dfs, u, rt);
    if (v > max) {
      sec = max, max = v;
    } else if (v > sec) {
      sec = v;
    }
  }
  ans += a[rt] - max + a[rt] - sec;
  std::cout << ans << "\n";
}