#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <queue>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 20000;
int const lgmax = 15;
int const inf = nmax;

struct Edge{
  int to;
  int rev;
  int flow;
  int cap;
};
class Graph{
public:
  std::vector<std::vector<Edge>> g;
  std::vector<int> level, rem;
  int n;
  Graph(int n_) {
    n = n_;
    g.resize(1 + n);
    level.resize(1 + n);
    rem.resize(1 + n);
  }
  void add_edge(int x, int y, int cap) {
    g[x].push_back({y, g[y].size(), 0, cap});
    g[y].push_back({x, g[x].size() - 1, 0, 0});
  }
  bool bfs() {
    for(int i = 1;i <= n; i++)
      level[i] = -1;
    std::queue<int> q;
    q.push(1);
    level[1] = 1;
    while(0 < q.size()) {
      int node = q.front();
      q.pop();
      for(int h = 0; h < g[node].size(); h++) {
        Edge e = g[node][h];
        if(e.flow < e.cap && level[e.to] == -1) {
          level[e.to] = level[node] + 1;
          q.push(e.to);
        }
      }
    }
    return 0 <= level[n];
  }

  int dfs(int node, int delta) {
    if(node == n)
      return delta;
    else  {
      for(int &h = rem[node]; h < g[node].size(); h++) {
        Edge &e = g[node][h];
        if(e.flow < e.cap && level[node] + 1 == level[e.to]) {
          int new_delta = dfs(e.to, std::min(delta, e.cap - e.flow));
          if(0 < new_delta) {
            e.flow += new_delta;
            g[e.to][e.rev].flow -= new_delta;
            return new_delta;
          }
        }
      }
      return 0;
    }
  }
  int maxflow() {
    int result = 0;
    while(bfs()) {
      for(int i = 1;i <= n; i++)
        rem[i] = 0;
      int delta = 0;
      do {
        result += delta;
        delta = dfs(1, inf);
      } while(0 < delta);
    }
    return result;
  }
  std::vector<std::pair<int,int>> minimum_cut() {
    bfs();
    std::vector<std::pair<int,int>> sol;
    for(int i = 1; i <= n; i++) {
      for(int h = 0; h < g[i].size(); h++) {
        Edge e = g[i][h];
        if(e.flow == 1 && 0 < level[i] && level[e.to] == -1) {
          sol.push_back({i, e.to});
        }
      }
    }
    return sol;
  }
};

int far[1 + lgmax][1 + nmax], level[1 + nmax];
int index[1 + nmax];
std::vector<std::pair<int,int>> g[1 + nmax];

void dfs(int node, int parent) {
  far[0][node] = parent;
  level[node] = level[parent] + 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    if(to != parent) {
      dfs(to, node);
      index[to] = g[node][h].second;
    }
  }
}

void computefar(int n) {
  for(int h = 1; h < lgmax; h++) 
    for(int i = 1;i <= n; i++)
      far[h][i] = far[h - 1][far[h - 1][i]];
}
int getlca(int x, int y) {
  if(level[x] < level[y]) 
    std::swap(x, y);
  for(int h = lgmax - 1; 0 <= h; h--) 
    if(level[y] + (1 << h) <= level[x])
      x = far[h][x];
  if(x == y)
    return x;
  for(int h = lgmax - 1; 0 <= h; h--)
    if(far[h][x] != far[h][y]) {
      x = far[h][x];
      y = far[h][y];
    }
  return far[0][x];
}

void connectpath(int x, int y, int id, Graph &graph, int &n) {
  for(int h = lgmax - 1; 0 <= h; h--) {
    if(level[y] + (1 << h) <= level[x]) {
      graph.add_edge(1 + h * n + x, id, inf);
      x = far[h][x];
    }
  }
}

int main() {
  int n, q;
  std::cin >> n >> q;
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back({y, i});
    g[y].push_back({x, i});
  }
  dfs(1, 0);
  computefar(n);
  Graph graph(1 + lgmax * n + q + 1);
  for(int i = 1;i <= n; i++)
    graph.add_edge(1, 1 + i, 1); 
  for(int h = 1; h < lgmax; h++) {
    for(int i = 1;i <= n; i++) {
      graph.add_edge(1 + (h - 1) * n + i, 1 + h * n + i, inf);
      if(0 < far[h - 1][i]) 
        graph.add_edge(1 + (h - 1) * n + far[h - 1][i], 1 + h * n + i, inf);
    }
  }
  int offset = 1 + lgmax * n;
  
  for(int i = 1; i <= q; i++) {
    int x, y;
    std::cin >> x >> y;
    int lca = getlca(x, y);
    connectpath(x, lca, offset + i,  graph, n);
    connectpath(y, lca, offset + i, graph, n);
    graph.add_edge(offset + i, offset + q + 1, 1);
  }
  
  std::cout << graph.maxflow() << '\n';
  std::vector<std::pair<int,int>> sol = graph.minimum_cut();
  std::vector<int> guardian, citizen;
  for(int i = 0; i < sol.size(); i++) {
    if(sol[i].first == 1)
      guardian.push_back(index[sol[i].second - 1]);
    else
      citizen.push_back(sol[i].first - offset);
  }
  std::cout << citizen.size() << " ";
  for(int i = 0; i < citizen.size(); i++)
    std::cout << citizen[i] << " ";
  std::cout << '\n';
  std::cout << guardian.size() << " ";
  for(int i = 0; i < guardian.size(); i++)
    std::cout << guardian[i] << " ";
  std::cout << '\n';
  return 0;
}