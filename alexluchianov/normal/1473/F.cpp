#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

using ll = long long;

int const inf = 1000000000;

class MaxFlow{
private:
  struct Edge{
    int to;
    int rev;
    int flow;
    int cap;
  };
  int n;
  std::vector<std::vector<Edge>> g;
  std::vector<int> level, rem;
  int source;
  int sink;
public:
  MaxFlow(int n_) {
    n = n_;
    source = 0;
    sink = n - 1;
    
    g.resize(n);
    level.resize(n);
    rem.resize(n);
  }
  void addEdge(int x, int y, int cap) {
    g[x].push_back({y, g[y].size(), 0, cap});
    g[y].push_back({x, g[x].size() - 1, 0, 0});
  }
  void setSourceSink(int _source, int _sink) {
    source = _source;
    sink = _sink;
  }
  bool BFS() {
    for(int i = 0; i < n; i++)
      level[i] = -1;
    std::queue<int> q;
    level[source] = 0;
    q.push(source);
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
    return 0 <= level[sink];
  }
  int DFS(int node, int delta) {
    if(node == sink)
      return delta;
    else {
      for(int &h = rem[node]; h < g[node].size(); h++) {
        Edge &e = g[node][h]; 
        if(e.flow < e.cap && level[node] + 1 == level[e.to]) {
          int deltaflow = DFS(e.to, std::min(delta, e.cap - e.flow));
          if(0 < deltaflow) {
            e.flow += deltaflow;
            g[e.to][e.rev].flow -= deltaflow;
            return deltaflow;
          }
        }
      }
      return 0;
    }
  }
  int64_t maxflow() {
    int64_t result = 0, delta = 0;
    while(BFS()) {
      for(int i = 0; i < n; i++)
        rem[i] = 0;
      delta = 0;
      do {
        result += delta;
        delta = DFS(source, inf);
      } while(0 < delta);
    }
    return result;
  }
};

int const nmax = 3000;
int v[1 + nmax], frec[1 + nmax];

int main() {
  int n;
  std::cin >> n;
  MaxFlow graph(n + 2);
  graph.setSourceSink(0, n + 1);
  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1;j <= v[i]; j++)
      if(v[i] % j == 0 && 0 < frec[j]) {
        graph.addEdge(i, frec[j], inf);
      }
    frec[v[i]] = i;
  }
  ll result = 0;
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    if(val < 0) 
      graph.addEdge(i, n + 1, -val);
    else {
      result += val;
      graph.addEdge(0, i, val);
    }
  }

  std::cout << result - graph.maxflow() << '\n';
  return 0;
}