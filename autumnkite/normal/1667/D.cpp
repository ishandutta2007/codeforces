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

    std::vector<int> fa(n, -1);
    std::vector<std::pair<int, int>> ans;

    auto dfs = [&](auto &self, int u) -> std::pair<int, int> {
      std::vector<int> sta[2];
      for (int v : E[u]) {
        if (v != fa[u]) {
          fa[v] = u;
          auto tmp = self(self, v);
          if (tmp.first == -1) {
            return tmp;
          }
          sta[tmp.first].push_back(tmp.second);
        }
      }
      int c = E[u].size() & 1;
      while (!sta[0].empty() && !sta[1].empty()) {
        std::vector<int> id[2];
        for (int k = 0; k < 2; ++k) {
          for (int v = sta[k].back(); v != u; v = fa[v]) {
            id[k].push_back(v);
          }
        }
        for (int k = 0; k < 2; ++k) {
          while (!id[c ^ k].empty()) {
            int v = id[c ^ k].back();
            ans.emplace_back(v, fa[v]);
            id[c ^ k].pop_back();
          }
        }
        sta[0].pop_back();
        sta[1].pop_back();
      }
      int k = sta[0].empty();
      if (c == k && !sta[k].empty()) {
        std::vector<int> id;
        for (int v = sta[k].back(); v != u; v = fa[v]) {
          id.push_back(v);
        }
        while (!id.empty()) {
          int v = id.back();
          ans.emplace_back(v, fa[v]);
          id.pop_back();
        }
        c ^= 1;
        sta[k].pop_back();
      }
      if (sta[k].empty()) {
        return std::make_pair(c, u);
      }
      if (sta[k].size() > 1) {
        return std::make_pair(-1, -1);
      }
      return std::make_pair(c, sta[k][0]);
    };

    if (dfs(dfs, 0).second != 0) {
      std::cout << "NO\n";
      continue;
    }

    std::cout << "YES\n";
    for (auto [u, v] : ans) {
      std::cout << u + 1 << " " << v + 1 << "\n";
    }
  }
}