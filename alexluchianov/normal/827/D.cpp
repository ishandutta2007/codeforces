#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
int const nmax = 200000;
int const inf = 2000000000;
int const lgmax = 20;

namespace Dsu{
  vector<int> mult;
  vector<int> sz;
  void initialize(int n){
    mult.resize(1 + n);
    sz.resize(1 + n);
    for(int i = 1;i <= n; i++)
      mult[i] = i;
    for(int i = 1;i <= n; i++)
      sz[i] = 1;
  }
  int jump(int gala){
    if(gala != mult[gala])
      mult[gala] = jump(mult[gala]);
    return mult[gala];
  }
  void unite(int gala, int galb){
    gala = jump(gala);
    galb = jump(galb);
    if(gala == galb)
      return ;
    if(sz[galb] < sz[gala])
      swap(gala, galb);
    sz[galb] += sz[gala];
    mult[gala] = galb;
  }
}

struct Edge{
  int x;
  int y;
  int cost;
  int id;
  bool operator < (Edge const &a) const{
    return cost < a.cost;
  }
};
int active[1 + nmax];
vector<int> g[1 + nmax];
int level[1 + nmax];
int far[1 + lgmax][1 + nmax], farp[1 + lgmax][1 + nmax];

void dfs(int node, int parent){
  level[node] = level[parent] + 1;
  far[0][node] = parent;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to == parent)
      g[node].erase(g[node].begin() + h);
  }
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    dfs(to, node);
  }
}

int getlca(int x, int y){
  if(level[x] < level[y])
    swap(x, y);
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
///returns the minimum on the path from x upwards of length target
int getpath(int x, int target){
  int result = 0;
  for(int h = lgmax; 0 <= h; h--)
    if((1 << h) <= target){
      target -= (1 << h);
      result = max(result, farp[h][x]);
      x = far[h][x];
    }
  return result;
}
int sol[1 + nmax];
int pathmin[1 + lgmax][1 + nmax];

void updatepath(int x, int target, int cost){
  for(int h = lgmax; 0 <= h; h--){
    if((1 << h) <= target){
      pathmin[h][x] = min(pathmin[h][x], cost);
      target -= (1 << h);
      x = far[h][x];
    }
  }
}

void computefar(int n){
  for(int h = 1; h <= lgmax; h++)
    for(int i = 1;i <= n; i++)
      farp[h][i] = MAX(farp[h - 1][i], farp[h - 1][far[h - 1][i]]);
  for(int h = lgmax ; 1 <= h; h--) {
    for(int i = 1;i <= n; i++) {
      pathmin[h - 1][i] = min(pathmin[h - 1][i], pathmin[h][i]);
      pathmin[h - 1][far[h - 1][i]] = min(pathmin[h - 1][far[h - 1][i]], pathmin[h][i]);
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<Edge> edge;
  for(int i = 1; i <= m; i++){
    int x, y, cost;
    cin >> x >> y >> cost;
    edge.push_back({x, y, cost, i});
  }
  Dsu::initialize(n);
  for(int h = 0; h <= lgmax; h++)
    for(int i = 0;i <= n; i++) {
      pathmin[h][i] = inf;
      farp[h][i] = inf;
    }
  sort(edge.begin(), edge.end());
  for(int i = 0; i < m; i++){
    int x = edge[i].x, y = edge[i].y;
    if(Dsu::jump(x) != Dsu::jump(y)){
      Dsu::unite(x, y);
      active[edge[i].id] = 1;
      g[x].push_back(y);
      g[y].push_back(x);
    }
  }
  dfs(1, 0);
  for(int h = 1; h <= lgmax; h++)
    for(int i = 1; i <= n; i++)
      far[h][i] = far[h - 1][far[h - 1][i]];

  for(int i = 0; i < m; i++){
    int x = edge[i].x, y = edge[i].y, id = edge[i].id;
    if(active[id] == 1){
      if(level[x] < level[y])
        swap(x, y);
      farp[0][x] = min(farp[0][x], edge[i].cost);
    } else {
      int lca = getlca(x, y);
      updatepath(x, level[x] - level[lca], edge[i].cost);
      updatepath(y, level[y] - level[lca], edge[i].cost);
    }
  }
  computefar(n);
  for(int i = 0; i < m; i++){
    int x = edge[i].x, y = edge[i].y, id = edge[i].id;
    if(active[id] == 0){
      int lca = getlca(x, y);
      sol[id] = max(getpath(x, level[x] - level[lca]), getpath(y, level[y] - level[lca]));
    } else {
      if(level[x] < level[y])
        swap(x, y);
      sol[id] = pathmin[0][x];
    }
  }
  for(int i = 1; i <= m; i++) {
    if(sol[i] == inf)
      cout << -1 <<  " " ;
    else
      cout << sol[i] - 1 << " " ;
  }
  return 0;
}