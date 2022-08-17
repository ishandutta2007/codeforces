#include <iostream>
#include <set>
#include <vector>

#define int long long

const int INF = 100000000000000000;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int> > d(n, std::vector<int>(n, 0));
  std::vector<std::vector<int> > W(n, std::vector<int>(n, INF));
  std::vector<std::pair<int, std::pair<int, int> > > edges;

  for(int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    u--; v--;
    edges.push_back({w, {u, v}});
    W[u][v] = W[v][u] = w;
  }

  for(int i = 0; i < n; i++)
    W[i][i] = 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
        W[j][k] = std::min(W[j][k], W[j][i] + W[i][k]);
      }
    }
  }

  int q;
  std::cin >> q;
  for(int i = 0; i < q; i++) {
    int u, v, l;
    std::cin >> u >> v >> l;
    u--; v--;
    d[u][v] = d[v][u] = l;
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
        d[j][k] = std::max(d[j][k], d[j][i] - W[i][k]);
        d[j][k] = std::max(d[j][k], d[i][k] - W[j][i]);
      }
    }
  }

  int ans = 0;
  for(auto j : edges) {
    if(j.first <= d[j.second.first][j.second.second])
      ans++;
  }

  std::cout << ans << std::endl;

  return 0;
}