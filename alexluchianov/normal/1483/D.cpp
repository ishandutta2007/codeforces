#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 600;
int const inf = 1000000005;
int dist[1 + nmax][1 + nmax];
int rest[1 + nmax][1 + nmax];

struct Edge{
  int x, y, cost;
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= n; j++)
      dist[i][j] = inf;
  
  std::vector<Edge> edges;
  for(int i = 1;i <= m; i++) {
    int x, y, cost;
    std::cin >> x >> y >> cost;
    edges.push_back({x, y, cost});
    dist[x][y] = std::min(dist[x][y], cost);
    std::swap(x, y);
    dist[x][y] = std::min(dist[x][y], cost);
  }

  for(int h = 1; h <= n; h++)
    for(int i = 1;i <= n; i++)
      for(int j = 1; j <= n; j++)
        dist[i][j] = std::min(dist[i][j], dist[i][h] + dist[h][j]);
  int q;
  std::cin >> q;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= n; j++)
      rest[i][j] = 0;

  for(int i = 1;i <= q; i++) {
    int x, y, cost;
    std::cin >> x >> y >> cost;
    rest[y][x] = rest[x][y] = std::max(rest[x][y], cost);
  }

  for(int i = 1;i <= n; i++) {
    for(int j = 1;j <= n; j++)
      for(int h = 1; h <= n; h++)
        rest[i][j] = std::max(rest[i][j], rest[i][h] - dist[h][j]);
  }
  for(int i = 1;i <= n; i++) {
    for(int j = 1;j <= n; j++)
      for(int h = 1; h <= n; h++)
        rest[j][i] = std::max(rest[j][i], rest[h][i] - dist[h][j]);
  }
  
  int result = 0;
  for(int i = 0; i < edges.size(); i++) {
    int x = edges[i].x;
    int y = edges[i].y;
    if(edges[i].cost <= rest[x][y])
      result++;
  }
  std::cout << result;
  return 0;
}