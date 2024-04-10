#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 2000000;
int const lgmax = 20;
int const inf = 1000000000;

class DSU{
public:
  vector<int> mult;
  vector<int> cost;
  DSU(int n = 0){
    mult.resize(1 + n);
    cost.resize(1 + n);
    for(int i = 1;i <= n; i++) {
      mult[i] = i;
      cost[i] = inf;
    }
  }
  int jump(int node){
    if(node != mult[node]){
      int father = mult[node];
      jump(father);
      cost[node] = min(cost[node], cost[father]);
      mult[node] = mult[father];
    }
    return mult[node];
  }
  void link(int node, int to){
    mult[to] = node;
  }
  void setvalue(int node, int val){
    cost[node] = val;
  }
  int query(int node){
    jump(node);
    return cost[node];
  }
};

namespace DominatorTree{
  vector<vector<int>> g;
  vector<vector<int>> invg;

  int id[1 + nmax], order[1 + nmax];
  DSU myset;

  void dfs(int root, int &ptr){
    id[root] = ++ptr;
    order[ptr] = root;
    for(int h = 0; h < g[root].size(); h++)
      if(id[g[root][h]] == 0) {
        dfs(g[root][h], ptr);
      }
  }

  void reset(int n){
    g.resize(1 + n);
    invg.resize(1 + n);
    for(int i = 1;i <= n; i++)
      g[i].clear();
  }
  int sdom[1 + nmax], idom[1 + nmax];
  int far[1 + lgmax][1 + nmax], farp[1 + lgmax][1 + nmax], level[1 + nmax];

  void computesdom(int node){
    sdom[node] = node;
    for(int h = 0; h < invg[node].size(); h++){
      int to = invg[node][h];
      if(to < node)
        sdom[node] = min(sdom[node], to);
      else
        sdom[node] = min(sdom[node], myset.query(to));
    }
    myset.setvalue(node, sdom[node]);
    for(int h = 0; h < g[node].size(); h++){
      int to = g[node][h];
      if(node == far[0][to])
        myset.link(node, to);
    }
  }


  void dfs2(int node){
    for(int h = 0; h < g[node].size(); h++){
      int to = g[node][h];
      if(level[to] == 0) {
        far[0][to] = node;
        level[to] = level[node] + 1;
        dfs2(to);
      }
    }
  }

  int combine(int x, int y){
    if(sdom[x] <= sdom[y])
      return x;
    else
      return y;
  }

  void computefar(int n){
    for(int i = 1;i <= n; i++)
      farp[0][i] = i;
    for(int h = 1;h <= lgmax; h++)
      for(int i = 1;i <= n; i++){
        far[h][i] = far[h - 1][far[h - 1][i]];
        farp[h][i] = combine(farp[h - 1][i], farp[h - 1][far[h - 1][i]]);
      }
  }

  void computeidom(int node){
    int target = level[node] - level[sdom[node]] - 1;
    int result = node, x = node;

    for(int h = lgmax; 0 <= h; h--){
      if((1 << h) <= target){
        target -= (1 << h);
        result = combine(result, farp[h][x]);
        x = far[h][x];
      }
    }
    if(result == node)
      idom[node] = sdom[node];
    else
      idom[node] = idom[result];
  }

  vector<pair<int,int>> convert(int n, int root, vector<pair<int,int>> edge){
    reset(n);
    for(int i = 0; i < edge.size(); i++){
      int x = edge[i].first, y = edge[i].second;
      g[x].push_back(y);
    }
    int ptr = 0;
    dfs(root, ptr);
    reset(n);
    for(int i = 0; i < edge.size(); i++){
      int x = edge[i].first, y = edge[i].second;
      g[id[x]].push_back(id[y]);
      invg[id[y]].push_back(id[x]);
    }
    root = id[root];
    level[root] = 1;
    dfs2(root);
    myset = DSU(n);

    sdom[0] = inf;
    for(int i = ptr; 1 <= i; i--)
      computesdom(i);
    computefar(ptr);

    for(int i = 1;i <= n; i++)
      computeidom(i);

    vector<pair<int,int>> sol;
    for(int i = 2; i <= n; i++)
      sol.push_back({order[idom[i]], order[i]});
    return sol;
  }
}

struct Edge{
  int to;
  ll cost;
  bool operator < (Edge const &a) const{
    return cost > a.cost;
  }
};
vector<pair<int,int>> g[1 + nmax];
int sz[1 + nmax];
ll dp[1 + nmax];

void solve(int node){
  sz[node] = 1;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h].first;
    solve(to);
    sz[node] += sz[to];
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, root;
  cin >> n >> m >> root;
  for(int i = 1;i <= m; i++){
    int x, y, w;
    cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }

  priority_queue<Edge> pq;
  pq.push({root, 1});
  dp[root] = 1;
  while(0 < pq.size()){
    int node = pq.top().to;
    ll cost = pq.top().cost;
    pq.pop();
    if(cost == dp[node]){
      for(int h = 0; h < g[node].size(); h++){
        int to = g[node][h].first;
        if(cost + g[node][h].second < dp[to] || dp[to] == 0){
          dp[to] = cost + g[node][h].second;
          pq.push({to, dp[to]});
        }
      }
    }
  }
  vector<pair<int,int>> edges;
  for(int i = 1;i <= n; i++)
    for(int h = 0; h < g[i].size(); h++){
      int to = g[i][h].first;
      ll cost = g[i][h].second;
      if(dp[i] + cost == dp[to]) {
        edges.push_back({i, to});
      }
    }
  edges = DominatorTree::convert(n, root, edges);
  for(int i = 1;i <= n; i++)
    g[i].clear();
  for(int i = 0; i < edges.size(); i++)
    g[edges[i].first].push_back({edges[i].second, 0});

  solve(root);

  int result = 0;
  for(int i = 1;i <= n; i++)
    if(i != root)
      result = max(result, sz[i]);
  cout << result;
  return 0;
}