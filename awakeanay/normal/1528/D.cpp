#include <iostream>
#include <set>

const int INF = 1000000700;
const int MAXN = 601;

int dist[MAXN][MAXN];

signed main() {
  int n, m;
  std::cin >> n >> m;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      dist[i][j] = INF;

  for(int i = 0; i < m; i++) {
    int a, b, c;
    std::cin >> a >> b >> c;
    dist[a][b] = c;
  }

  for(int i = 0; i < n; i++) {
    std::set<std::pair<int, int> > dij;
    for(int k = 0; k < n; k++) {
      dij.insert({dist[i][k], k});
    }

    while(!dij.empty()) {
      int u = (*dij.begin()).second;
      int v = (u+1)%n;
      dij.erase(dij.begin());
      int cd = dist[i][v];
      if(cd > dist[i][u] + 1) {
        dij.erase({cd, v});
        dist[i][v] = dist[i][u] + 1;
        dij.insert({dist[i][v], v});
      }
    }
  }

  int finale[n][n];
  for(int i = 0; i < n; i++) {
    std::set<std::pair<int, int> > dij;
    for(int j = 0; j < n; j++) {
      finale[i][j] = (i == j ? 0 : INF);
      dij.insert({finale[i][j], j});
    }

    while(!dij.empty()) {
      int u = (*dij.begin()).second;
      int d = (*dij.begin()).first;
      dij.erase(dij.begin());
      for(int j = 0; j < n; j++) {
        int add = dist[u][(j-d%n+n)%n];
        if(finale[i][j] > finale[i][u] + add) {
          dij.erase({finale[i][j], j});
          finale[i][j] = finale[i][u] + add;
          dij.insert({finale[i][j], j});
        } 
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      std::cout << finale[i][j] << " ";
    std::cout << std::endl;
  }

  return 0;
}