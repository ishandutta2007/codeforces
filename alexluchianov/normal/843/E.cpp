#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <queue>

int const nmax = 1000;
int const inf = 1000000000;
using ll = long long;

class Graph{
private:
  struct Edge{
    int to;
    int rev;
    int flow;
    int cap;
    int id;
  };
  std::vector<std::vector<Edge>> g;
  std::vector<int> level, rem;
  int n;
  int source, sink;
public:
  Graph(int n_, int source_, int sink_) {
    n = n_;
    source = source_;
    sink = sink_;

    g.resize(1 + n);
    level.resize(1 + n);
    rem.resize(1 + n);
  }
  void add_edge(int x, int y, int cap, int id) {
    g[x].push_back({y, g[y].size(), 0, cap, id});
    g[y].push_back({x, g[x].size() - 1, 0, 0, -id});
  }
  bool bfs() {
    for(int i = 1;i <= n; i++)
      level[i] = -1;
    std::queue<int> q;
    q.push(source);
    level[source] = 0;
    while(0 < q.size()) {
      int node = q.front();
      q.pop();
      for(int h = 0;h < g[node].size(); h++) {
        Edge e = g[node][h];
        if(e.flow < e.cap && level[e.to] == -1) {
          level[e.to] = level[node] + 1;
          q.push(e.to);
        }
      }
    }
    return (0 <= level[sink]);
  }

  int dfs(int node, int deltaflow) {
    if(node == sink) {
      return deltaflow;
    } else {
      for(int &h = rem[node]; h < g[node].size(); h++) {
        Edge &e = g[node][h];
        if(e.flow < e.cap && level[node] + 1 == level[e.to]) {
          int delta = dfs(e.to, std::min(deltaflow, e.cap - e.flow));
          if(0 < delta) {
            e.flow += delta;
            g[e.to][e.rev].flow -= delta;
            return delta;
          }
        }
      }
      return 0;
    }
  }
  
  ll maxflow() {
    ll result = 0;
    while(bfs()) {
      int delta = 0;
      do {
        for(int i = 1; i <= n; i++)
          rem[i] = 0;
        result += delta;
        delta = dfs(source, inf);
      } while(0 < delta);
    }
    return result;
  }

  std::vector<int> extract_mincut() {
    bfs();
    std::vector<int> mincut;
    for(int i = 1;i <= n; i++)
      for(int h = 0; h < g[i].size(); h++) {
        Edge e = g[i][h]; 
        if(0 <= level[i] && level[e.to] == -1 && 0 < e.cap) {
          mincut.push_back(e.id);
        }
      }
    return mincut;
  }

  std::vector<std::pair<int,int>> get_sol(int m) {
    std::vector<std::pair<int,int>> sol(m);
    for(int i = 1; i <= n; i++)
      for(int h = 0; h < g[i].size(); h++) {
        Edge e = g[i][h];
        if(0 < e.id)
          sol[e.id - 1] = {e.flow, e.cap};
      }
    return sol;
  }
};

int start[1 + nmax], stop[1 + nmax], type[1 + nmax], special[1 + nmax];
int base[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m, s, t;
  std::cin >> n >> m >> s >> t;
  Graph graph(1 + n, s, t);
  for(int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> start[i] >> stop[i] >> type[i];

    if(type[i] == 0)
      graph.add_edge(start[i], stop[i], inf, i);
    else {
      graph.add_edge(start[i], stop[i], 1, i);
      graph.add_edge(stop[i], start[i], inf, 0);
    }
  }

  int init = graph.maxflow();
  
  std::cout << init << '\n';
  std::vector<int> mincut = graph.extract_mincut();
  for(int i = 0; i < mincut.size(); i++) 
    special[mincut[i]] = 1;
  
  Graph graph2(3 + n, n + 1, n + 2);

  base[s] = nmax * 5 * init;
  base[t] = -nmax * 5 * init;
  
  for(int i = 1;i <= m; i++) {
    if(type[i] == 0)
      graph2.add_edge(start[i], stop[i], 0, i);
    else if(special[i] == 1) {
      graph2.add_edge(start[i], stop[i], nmax * 5 - 1, i);
      base[start[i]]--;
      base[stop[i]]++;
    } else {
      graph2.add_edge(start[i], stop[i], inf - 1, i);
      base[start[i]]--;
      base[stop[i]]++;
    }
  }
  
  
  for(int i = 1; i <= n; i++)
    if(0 < base[i])
      graph2.add_edge(n + 1, i, base[i], 0);
    else if(base[i] < 0)
      graph2.add_edge(i, n + 2, -base[i], 0);
  
  int tar = 0;
  for(int i = 1;i <= n; i++)
    if(0 < base[i])
      tar += base[i];
  graph2.maxflow();

  std::vector<std::pair<int,int>> sol = graph2.get_sol(m);
  for(int i = 0; i < sol.size(); i++) {
    if(type[1 + i] == 1)
      std::cout << sol[i].first + 1 << " " << std::max(1, sol[i].second) + 1 << '\n';
    else
      std::cout << sol[i].first << " " << std::max(sol[i].second, 1) << '\n';
  }
  return 0;
}