#include <bits/stdc++.h>

template<typename Tp>
constexpr Tp INF = std::numeric_limits<Tp>::max() / 2;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::vector E(n, std::vector(n, INF<int>));
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      std::cin >> u >> v >> w;
      --u, --v;
      E[u][v] = std::min(E[u][v], w);
      E[v][u] = std::min(E[v][u], w);
    }
    
    auto bfs = [&](int s) {
      std::vector<int> dis(n, n);
      dis[s] = 0;
      std::vector<int> Q;
      Q.push_back(s);
      for (int i = 0; i < (int)Q.size(); ++i) {
        int u = Q[i];
        for (int v = 0; v < n; ++v) {
          if (E[u][v] != INF<int> && dis[v] == n) {
            dis[v] = dis[u] + 1;
            Q.push_back(v);
          }
        }
      }
      return dis;
    };

    std::vector<std::vector<int>> f(n);
    for (int i = 0; i < n; ++i) {
      f[i] = bfs(i);
    }
    long long ans = INF<long long>;
    for (int u = 0; u < n; ++u) {
      for (int v = 0; v < n; ++v) {
        if (E[u][v] != INF<int>) {
          int s = f[0][u] + f[n - 1][v] + 1;
          for (int k = 0; k < n; ++k) {
            s = std::min(s, f[k][u] + f[0][k] + f[n - 1][k] + 2);
          }
          ans = std::min(ans, 1ll * s * E[u][v]);
        }
      }
    }
    std::cout << ans << "\n";
  }
}