#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  long long k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> G(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    G[u].push_back(v);
  }

  std::vector<int> val = a;
  std::sort(val.begin(), val.end());
  val.erase(std::unique(val.begin(), val.end()), val.end());

  auto it = std::lower_bound(val.begin(), val.end(), 0, [&](int x, int y) {
    std::vector<int> deg(n);

    auto check = [&](int u) {
      return a[u] <= x;
    };

    for (int u = 0; u < n; ++u) {
      for (int v : G[u]) {
        if (check(u) && check(v)) {
          ++deg[v];
        }
      }
    }
    std::vector<int> Q;
    std::vector<int> f(n);
    int cnt = 0;
    for (int u = 0; u < n; ++u) {
      if (check(u)) {
        if (!deg[u]) {
          Q.push_back(u);
          f[u] = 1;
        }
        ++cnt;
      }
    }
    for (int k = 0; k < (int)Q.size(); ++k) {
      int u = Q[k];
      for (int v : G[u]) {
        if (check(v)) {
          f[v] = std::max(f[v], f[u] + 1);
          --deg[v];
          if (!deg[v]) {
            Q.push_back(v);
          }
        }
      }
    }
    if ((int)Q.size() < cnt) {
      return false;
    }
    if (*std::max_element(f.begin(), f.end()) >= k) {
      return false;
    }
    return true;
  });

  if (it == val.end()) {
    std::cout << -1 << "\n";
  } else {
    std::cout << *it << "\n";
  }
}