#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

int const nmax = 200000;
int const lgmax = 20;
int const inf = 1000000000;

using ll = long long;

class Dsu{
private:
  std::vector<int> mult;
public:
  Dsu(int n) {
    mult.resize(1 + n);
    for(int i = 1;i <= n; i++)
      mult[i] = i;
  }
  int jump(int gala) {
    if(gala != mult[gala]) {
      mult[gala] = jump(mult[gala]);
    }
    return mult[gala];
  }
  void unite(int gala, int galb) {
    gala = jump(gala);
    galb = jump(galb);
    if(gala == galb)
      return ;
    mult[gala] = galb;
  }
  bool connected(int x, int y) {
    return jump(x) == jump(y);
  }
};

struct Edge{
  int x;
  int y;
  int cost;
  int id;
  bool operator < (Edge const oth) {
    return cost < oth.cost;
  }
};
ll sol[5 + nmax];
std::vector<std::pair<int,int>> g[5 + nmax];

int far[1 + lgmax][1 + nmax];
int farp[1 + lgmax][1 + nmax];
int level[5 + nmax];

int getLca(int x, int y) {
  if(level[x] < level[y])
    std::swap(x, y);
  for(int h = lgmax; 0 <= h; h--)
    if(level[y] + (1 << h) <= level[x])
      x = far[h][x];
  if(x == y)
    return x;
  for(int h = lgmax; 0 <= h; h--)
    if(far[h][x] != far[h][y]) {
      x = far[h][x];
      y = far[h][y];
    }
  return far[0][x];
}

void dfs(int node, int parent) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    int cost = g[node][h].second;
    if(to != parent) {
      far[0][to] = node;
      farp[0][to] = cost;
      level[to] = level[node] + 1;
      dfs(to, node);
    }
  }
}

int main() {
  int n, m;
  std::cin >> n >> m;
  Dsu dsu(1 + n);
  std::vector<Edge> edges;
  for(int i = 1; i <= m; i++) {
    int x, y, cost;
    std::cin >> x >> y >> cost;
    edges.push_back({x, y, cost, i});
  }
  std::sort(edges.begin(), edges.end());
  std::vector<Edge> treeEdges, queryEdges;
  
  ll base = 0;

  for(int i = 0; i < edges.size(); i++) {
    int x = edges[i].x, y = edges[i].y;
    if(dsu.connected(x, y) == 0) {
      base += edges[i].cost;
      dsu.unite(x, y);
      treeEdges.push_back(edges[i]);
    } else
      queryEdges.push_back(edges[i]);
  }

  //Here starts the relevant code
  for(int i = 0; i < treeEdges.size(); i++) {
    int x = treeEdges[i].x;
    int y = treeEdges[i].y;
    int cost = treeEdges[i].cost;
    g[x].push_back({y, cost});
    g[y].push_back({x, cost});
  }

  dfs(1, 0);

  for(int h = 1; h <= lgmax; h++) {
    for(int i = 1;i <= n; i++) {
      far[h][i] = far[h - 1][far[h - 1][i]];
      farp[h][i] = std::max(farp[h - 1][i], farp[h - 1][far[h - 1][i]]);
    }
  }
  
  for(int i = 0; i < queryEdges.size(); i++) {
    int x = queryEdges[i].x;
    int y = queryEdges[i].y;
    int lca = getLca(x, y);
    int result = 0;
    for(int h = lgmax; 0 <= h; h--)
      if(level[lca] + (1 << h) <= level[x]) {
        result = std::max(result, farp[h][x]);
        x = far[h][x];
      }
    for(int h = lgmax; 0 <= h; h--)
      if(level[lca] + (1 << h) <= level[y]) {
        result = std::max(result, farp[h][y]);
        y = far[h][y];
      }
    sol[queryEdges[i].id] = queryEdges[i].cost - result;
  }

  for(int i = 1;i <= m; i++)
    std::cout << base + sol[i] << '\n';

  //Here end the relevant code
  return 0;
}