#include <iostream>
#include <vector>
#include <algorithm>
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

int const nmax = 50;
struct Funct{
  int a, b, c;
  int eval(int x) {
    return a * x * x + b * x + c;
  }
} v[5 + nmax];
int l[5 + nmax], r[5 + nmax], start[5 + nmax];

int main() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 1; i <= n; i++)
    std::cin >> v[i].a >> v[i].b >> v[i].c;
  
  start[1] = 1;
  for(int i = 1;i <= n; i++) {
    std::cin >> l[i] >> r[i];
    start[i + 1] = start[i] + (r[i] - l[i] + 1);
  }
  MaxFlow graph(start[n + 1] + 1);
  graph.setSourceSink(0, start[n + 1]);
  ll result = 0;
  
  for(int i = 1;i <= n; i++) {
    result += v[i].eval(l[i]);
    graph.addEdge(0, start[i], inf);
    for(int j = l[i] + 1; j <= r[i]; j++) {
      int res = v[i].eval(j) - v[i].eval(j - 1);
      graph.addEdge(start[i] + (j - l[i]), start[i] + (j - l[i]) - 1, inf);
      if(0 <= res) {
        result += res;
        graph.addEdge(0, start[i] + (j - l[i]), res);
      } else
        graph.addEdge(start[i] + (j - l[i]), start[n + 1], -res); 
    }
  }
  
  for(int i = 1;i <= m; i++) {
    int x, y, d;
    std::cin >> x >> y >> d;
    for(int j = l[x]; j <= r[x]; j++) {
      int oth = std::max(j - d, l[y]);
      if(r[y] < oth) {
        graph.addEdge(start[x] + (j - l[x]), start[n + 1], inf);
      } else
        graph.addEdge(start[x] + (j - l[x]), start[y] + oth - l[y], inf);
    }
  }

  std::cout << result -  graph.maxflow() << '\n';
  return 0;
}