
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

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
    g[x].push_back({y, (int)g[y].size(), 0, cap});
    g[y].push_back({x, (int)g[x].size() - 1, 0, 0});
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

int findPosition(int n, int h, int x, int y) {
  return 1 + (h + 1) * (x - 1) + 1 + y;
}

int main()
{
  int n, m, h;
  std::cin >> n >> h >> m;
  MaxFlow graph(1 + n * (h + 1) + m + 1 + 1);
  int64_t base = n * h * h;
  graph.setSourceSink(1, 1 + n * (h + 1) + m + 1);


  for(int i = 1; i <= n; i++)
    for(int j = 0; j < h; j++) {
      graph.addEdge(findPosition(n, h, i, j), findPosition(n, h, i, j + 1), inf);
      graph.addEdge(findPosition(n, h, i, j), 1 + n * (h + 1) + m + 1, (j + 1) * (j + 1) - j * j);
    }
  for(int i = 1; i <= m; i++) {
    int l, r, x, c;
    std::cin>> l >> r >> x >> c;
    for(int j = l; j <= r; j++)
      graph.addEdge(1 + n * (h + 1) + i, findPosition(n, h, j, x), inf);
    graph.addEdge(1, 1 + n * (h + 1) + i, c);
  }

  std::cout << base - graph.maxflow() << '\n';
  return 0;
}