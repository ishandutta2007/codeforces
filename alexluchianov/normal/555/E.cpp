#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <set>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const lgmax = 20;

vector<int> g[1 + nmax];
int comp[1 + nmax];
int level[1 + nmax], maxlevel[1 + nmax], seen[1 + nmax];

int dfs(int node, int parent){
  seen[node] = 1;
  level[node] = level[parent] + 1;
  int result = node;
  int skipped = 0;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to == parent && skipped == 0) {
      skipped++;
      continue;
    }
    if(seen[to] == 0) {
      int ans = dfs(to, node);
      if(level[ans] < level[result])
        result = ans;
    } else if(level[to] < level[result]) {
      result = to;
    }
  }
  maxlevel[node] = result;
  return result;
}

void _partitions(int node, int parent, int &ptr){
  seen[node] = 1;
  if(maxlevel[node] == node)
    comp[node] = ++ptr;
  else
    comp[node] = comp[maxlevel[node]];

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent && seen[to] == 0)
      _partitions(to, node, ptr);
  }
}

namespace Tree{
  vector<int> g[1 + nmax];
  int level[1 + nmax];
  int far[1 + lgmax][1 + nmax];
  void dfs(int node, int parent){
    level[node] = level[parent] + 1;
    far[0][node] = parent;
    for(int h = 0; h < g[node].size(); h++){
      int to = g[node][h];
      if(to != parent)
        dfs(to, node);
    }
  }
  void computefar(int n){
    for(int h = 1; h <= lgmax; h++)
      for(int i = 1; i <= n; i++)
        far[h][i] = far[h - 1][far[h - 1][i]];
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

  int sum[1 + nmax][2];

  void augment(int from, int to, int val){
    sum[from][val]++;
    sum[to][val]--;
  }

  void dfstest(int node, int parent){
    for(int h = 0; h < g[node].size(); h++){
      int to = g[node][h];
      if(to != parent) {
        dfstest(to, node);
        sum[node][0] += sum[to][0];
        sum[node][1] += sum[to][1];
      }
    }
  }
}

set<pair<int,int>> edges;

int main()
{
  int n, m, q;
  cin >> n >> m >> q;
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  int ptr = 0;
  for(int i = 1;i <= n; i++)
    seen[i] = 0;
  _partitions(1, 0, ptr);


  for(int i = 1; i <= n; i++)
    for(int h = 0; h < g[i].size(); h++) {
      int x = comp[i], y = comp[g[i][h]];
      if(x != y && edges.find({x, y}) == edges.end()){
        Tree::g[x].push_back(y);
        edges.insert({x, y});
      }
    }


  Tree::dfs(1, 0);
  Tree::computefar(n);
  for(int i = 1; i <= q; i++){
    int x, y;
    cin >> x >> y;
    x = comp[x];
    y = comp[y];
    if(x == y)
      continue;
    else {
      int lca = Tree::getlca(x, y);
      if(lca == 0){
        cout << "No";
        return 0;
      }
      Tree::augment(x, lca, 0);
      Tree::augment(y, lca, 1);
    }
  }
  Tree::dfstest(1, 0);
  for(int i = 1;i <= n; i++)
    if(0 < Tree::sum[i][0] && 0 < Tree::sum[i][1]) {
      cout << "No";
      return 0;
    }
  cout << "Yes";
  return 0;
}