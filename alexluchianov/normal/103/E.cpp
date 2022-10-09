#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
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

int main() {
  int n;
  std::cin >> n;
  std::vector<int> frec(1 + n);
  MaxFlow graph(1 + 2 * n + 1);
  graph.setSourceSink(0, 2 * n + 1);
  for(int i = 1;i <= n; i++) {
    int m;
    std::cin >> m;
    for(int j = 1; j <= m; j++) {
      int val;
      std::cin >> val;
      graph.addEdge(i, n + val, inf);
      frec[val] = 1;
    }
  }
  ll result = 0;
  for(int i = 1; i <= n; i++) {
    int val;
    std::cin >> val;
    result += val;
    graph.addEdge(0, i, inf - val);
    if(frec[i] == 1)
      result -= inf;
    graph.addEdge(n + i, 2 * n + 1, inf);
  }
  std::cout << result + graph.maxflow() << '\n';
}