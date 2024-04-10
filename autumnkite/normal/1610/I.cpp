#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

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
  
  std::vector<int> fa(n, -1);
  std::vector<int> f(n);

  auto dfs = [&](auto &self, int u) -> void {
    for (int v : E[u]) {
      if (v != fa[u]) {
        fa[v] = u;
        self(self, v);
        f[u] ^= f[v] + 1;
      }
    }
  };

  dfs(dfs, 0);

  int now = f[0];

  std::string ans;
  if (now) {
    ans += '1';
  } else {
    ans += '2';
  }

  std::vector<bool> vis(n);
  vis[0] = true;
  for (int x = 1; x < n; ++x) {
    int lst = -1;
    for (int u = x; !vis[u]; lst = u, u = fa[u]) {
      for (int v : E[u]) {
        if (v != fa[u] && v != lst) {
          now ^= f[v] + 1;
        }
      }
      now ^= 1;
      vis[u] = true;
    }
    if (lst != -1) {
      now ^= f[lst] + 1;
    }
    if (now) {
      ans += '1';
    } else {
      ans += '2';
    }
  }
  std::cout << ans << "\n";
}