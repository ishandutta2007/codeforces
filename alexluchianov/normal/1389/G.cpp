#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

int const nmax = 300000;
using ll = long long;

class Dsu{
  private:
    std::vector<int> mult;
  public:
    Dsu(int n = 0) {
      mult.resize(1 + n);
      for(int i = 1;i <= n; i++)
        mult[i] = i;
    }
    int jump(int gala) {
      if(mult[gala] != gala)
        mult[gala] = jump(mult[gala]);
      return mult[gala];
    }
    void unite(int gala, int galb) {
      gala = jump(gala);
      galb = jump(galb);
      mult[gala] = galb;
    }
};

ll v[5 + nmax];

struct Edges{
  int x;
  int y;
  int cost;
};

namespace Tree{
  int far[5 + nmax], level[5 + nmax];
  Dsu dsu;
  std::vector<int> g[5 + nmax];

  void dfs(int node, int parent) {
    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h];
      if(level[to] == 0) {
        level[to] = level[node] + 1;
        far[to] = node;
        dfs(to, node);
      }
    }
  }

  void build(int n, std::vector<Edges> &edges) {
    for(int i = 0; i < edges.size(); i++) {
      int x = edges[i].x;
      int y = edges[i].y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    level[1] = 1;
    dfs(1, 0);
    dsu = Dsu(n);
    for(int i = 0; i < edges.size(); i++) {
      int x = edges[i].x;
      int y = edges[i].y;
      if(level[y] < level[x])
        std::swap(x, y);
      if(level[x] + 1 < level[y]) {
        while(dsu.jump(x) != dsu.jump(y)) {
          dsu.unite(dsu.jump(y), far[dsu.jump(y)]);
        }
      }
    }
  }

  int convert(int node) {
    return dsu.jump(node);
  }
};

namespace Solver{
  int sz[5 + nmax];
  int active[5 + nmax];

  std::vector<std::pair<int,int>> g[5 + nmax];

  void dfs(int node, int parent, int target) {
    active[node] = 1;

    for(int h = 0; h < g[node].size(); h++)
      if(g[node][h].first == parent)
        g[node].erase(g[node].begin() + h);

    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h].first;
      dfs(to, node, target);
      sz[node] += sz[to];
      if(sz[to] == target)
        active[node] = 0;

      if(sz[to] == 0) {
        v[node] += v[to];
        v[to] = 0;
      }
    }

    if(sz[node] == 0)
      active[node] = 0;
  }

  ll dp[5 + nmax], dp2[5 + nmax];

  void computeDp(int node, int parent) {
    dp[node] = v[node];

    for(int h = 0;h < g[node].size(); h++) {
      int to = g[node][h].first;
      int cost = g[node][h].second;
      if(active[to] == 1) {
        computeDp(to, node);
        dp[node] += std::max(0LL, dp[to] - cost);
      }
    }
  }

  void computeDp2(int node, int parent) {
    ll acc = dp2[node];
    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h].first;
      int cost = g[node][h].second;
      if(active[to] == 0)
        continue;
      acc += std::max(0LL, dp[to] - cost);
    }
    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h].first;
      int cost = g[node][h].second;
      if(active[to] == 0)
        continue;
      dp2[to] = std::max(0LL, acc + v[node] - std::max(0LL, dp[to] - cost) - cost);
      computeDp2(to, node);
    }
  }

  void push(int node) {
    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h].first;
      if(sz[to] == 0) {
        dp[to] = dp[node];
      }
      push(to);
    }
  }

  void build(int n, std::vector<Edges> &edges, std::vector<int> &spec) {
    assert(0 < spec.size());
    for(int i = 0; i < edges.size(); i++) {
      int x = edges[i].x;
      int y = edges[i].y;
      int cost = edges[i].cost;
      g[x].push_back({y, cost});
      g[y].push_back({x, cost});
    }
    for(int i = 0; i < spec.size(); i++)
      sz[spec[i]] = 1;
    dfs(spec[0], 0, spec.size());
    computeDp(spec[0], 0);

    dp2[spec[0]] = 0;
    computeDp2(spec[0], 0);
    
    /*
    std::cout << "Build\n";
    for(int i = 1;i <= n; i++)
      std::cout << active[i] << " ";
    std::cout << '\n';
    for(int i = 1;i <= n; i++)
      std::cout << v[i] << " ";
    std::cout << '\n';

    for(int i = 1;i <= n; i++)
      std::cout << dp[i] << " ";
    std::cout << '\n';
    //*/

    for(int i = 1;i <= n; i++)
      if(active[i] == 1)
        dp[i] += dp2[i];
    push(spec[0]);
  }
};



int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> specialNodes;
  for(int i = 1;i <= k; i++) {
    int val;
    std::cin >> val;
    specialNodes.push_back(val);
  }
  for(int i = 1; i <= n; i++)
    std::cin >> v[i];
  std::vector<Edges> edges(m);
  for(int i = 0;i < m; i++)
    std::cin >> edges[i].cost;
  for(int i = 0;i < m; i++) {
    std::cin >> edges[i].x >> edges[i].y;
  }

  Tree::build(n, edges); 
  for(int i = 0; i < specialNodes.size(); i++)
    specialNodes[i] = Tree::convert(specialNodes[i]);
  std::sort(specialNodes.begin(), specialNodes.end());
  specialNodes.erase(std::unique(specialNodes.begin(), specialNodes.end()), specialNodes.end());

  std::vector<Edges> newEdges;
  for(int i = 0; i < edges.size(); i++) {
    Edges newEdge = edges[i];
    newEdge.x = Tree::convert(newEdge.x);
    newEdge.y = Tree::convert(newEdge.y);
    if(newEdge.x != newEdge.y)
      newEdges.push_back(newEdge);
  }
  std::swap(newEdges, edges);

  for(int i = 1;i <= n; i++) {
    if(Tree::convert(i) != i)
      v[Tree::convert(i)] += v[i];
  }
  

  /*
  for(int i = 1;i <= n; i++)
    std::cout << v[i] << " ";
  std::cout << '\n';
  for(int i = 1;i <= n; i++)
    std::cout << Tree::dsu.jump(i) << " ";
  std::cout << '\n';
  std::cout << "Edges\n";
  for(int i = 0; i < edges.size(); i++)
    std::cout << edges[i].x << " " << edges[i].y << " " << edges[i].cost << '\n';
  std::cout << '\n';
  */

  Solver::build(n, edges, specialNodes);
  for(int i = 1; i <= n; i++)
    std::cout << Solver::dp[Tree::convert(i)] << " ";
  std::cout << '\n';

  return 0;
}