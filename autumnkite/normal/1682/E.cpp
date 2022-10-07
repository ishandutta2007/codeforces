#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
    --p[i];
  }
  std::vector<std::vector<std::pair<int, int>>> a(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    a[u].emplace_back(v, i);
    a[v].emplace_back(u, i);
  }

  std::vector<std::vector<int>> E(m);
  std::vector<int> deg(m);
  std::vector<int> ord(n, -1);
  for (int i = 0; i < n; ++i) {
    if (ord[i] == -1) {
      std::vector<int> cyc;
      for (int j = i; ord[j] == -1; j = p[j]) {
        ord[j] = cyc.size();
        cyc.push_back(j);
      }

      auto dist = [&](int x, int y) -> int {
        return (ord[y] - ord[x] + cyc.size()) % cyc.size();
      };

      for (int j : cyc) {
        std::sort(a[j].begin(), a[j].end(), [&](auto x, auto y) {
          return dist(j, x.first) < dist(j, y.first);
        });
        for (int k = 1; k < (int)a[j].size(); ++k) {
          int u = a[j][k - 1].second, v = a[j][k].second;
          E[u].push_back(v);
          ++deg[v];
        }
      }
    }
  }

  std::vector<int> Q;
  for (int i = 0; i < m; ++i) {
    if (!deg[i]) {
      Q.push_back(i);
    }
  }
  for (int i = 0; i < (int)Q.size(); ++i) {
    int u = Q[i];
    for (int v : E[u]) {
      --deg[v];
      if (!deg[v]) {
        Q.push_back(v);
      }
    }
  }
  for (int x : Q) {
    std::cout << x + 1 << " ";
  }
  std::cout << "\n";
}