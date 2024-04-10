#include <iostream>
#include <vector>
#include <set>

#define int long long

const int INF = 1000000000000000000;

signed main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::pair<int, int> > Adj[n];

  for(int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    u--; v--;
    Adj[u].push_back({v, w});
    Adj[v].push_back({u, w});
  }

  std::vector<int> dis(51*n, INF);
  dis[0] = 0;
  std::set<std::pair<int, int> > dij;
  dij.insert({0, 0});

  while(!dij.empty()) {
    std::pair<int, int> u = *dij.begin();
    dij.erase(dij.begin());
    int x = u.second%n;
    int y = u.second/n;

    for(std::pair<int, int> j : Adj[x]) {
      int cur = y == 0 ? u.first : u.first + (y + j.second)*(y+j.second);
      int v = y == 0 ? j.second*n+j.first : j.first;

      if(cur < dis[v]) {
        dij.erase({dis[v], v});
        dis[v] = cur;
        dij.insert({dis[v], v});
      }
    }
  }

  for(int i = 0; i < n; i++) {
    if(dis[i] >= INF)
      std::cout << -1 << " ";
    else
      std::cout << dis[i] << " ";
  }

  std::cout << std::endl;

  return 0;
}