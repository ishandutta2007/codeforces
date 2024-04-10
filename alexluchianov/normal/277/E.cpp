#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <queue>
#include <iomanip>

using ll = long long;
using ld = long double;

class Graph{
private:
  int const hard_limit = 1000000;
  ld const inf = 1000000000000000000;
  ld const eps = 0.000001;
  int const maxcap = 1000000000;
  
  bool equal(ld a, ld b) {
    return a - b <= eps && b - a <= eps;
  }

  struct Edge{
    int to;
    int rev;
    int flow;
    int cap;
    ld cost;
  };
  std::vector<std::vector<Edge>> g;
  std::vector<ld> dist;
  std::vector<ld> dist2;
  std::vector<int> seen, last;
  int source, sink;
  int n;

public:
  Graph(int n_) {
    n = n_;
    g.resize(1 + n);
    dist.resize(1 + n);
    seen.resize(1 + n);
    dist2.resize(1 + n);
    last.resize(1 + n);
  }
  void addEdge(int x, int y, int cap, ld cost) {
    g[x].push_back({y, g[y].size(), 0, cap, cost});
    g[y].push_back({x, g[x].size() - 1, 0, 0, -cost});
  }
  
  void setSourceSink(int _source, int _sink) {
    source = _source;
    sink = _sink;
  }

  bool bellman() {
    for(int i = 0; i <= n; i++)
      dist[i] = seen[i] = 0;

    std::queue<int> q;
    std::vector<int> in_queue(1 + n);
    seen[source] = 1;
    in_queue[source] = 1;
    q.push(source);
    
    int steps = 0;

    while(0 < q.size() && steps < hard_limit) {
      steps++;
      int node = q.front();
      in_queue[node] = 0;
      q.pop();
      for(int h = 0; h < g[node].size(); h++) {
        Edge e = g[node][h];
        if(e.flow < e.cap && (seen[e.to] == 0 || dist[node] + e.cost < dist[e.to])) {
          dist[e.to] = dist[node] + e.cost;
          if(in_queue[e.to] == 0) {
            q.push(e.to);
            seen[e.to] = 1;
            in_queue[e.to] = 1;
          }
        }
      }
    }
    return 0 == q.size() && 1 == seen[sink];
  }

  bool dijkstra(ll &result, ld &result2) {
    for(int i = 0;i <= n; i++) {
      last[i] = seen[i] = 0;
      dist2[i] = inf;
    }
    std::priority_queue<std::pair<ld, int>, std::vector<std::pair<ld, int>>,
                        std::greater<std::pair<ld, int>>> pq;
    dist2[source] = 0; 
    pq.push({0, source});

    while(0 < pq.size()) {
      int node = pq.top().second;
      pq.pop();
      if(seen[node] == 1)
        continue;
      seen[node] = 1;
      for(int h = 0; h < g[node].size(); h++) {
        Edge e = g[node][h];
        ld cost = dist[node] - dist[e.to] + e.cost;
        if(e.flow < e.cap && seen[e.to] == 0 && dist2[node] + cost < dist2[e.to]) {
          dist2[e.to] = dist2[node] + cost;
          last[e.to] = e.rev;
          pq.push({dist2[e.to], e.to});
        }
      }
    }
    
    if(seen[sink] == 1) {
      int delta = maxcap;
      int start = sink;
      while(source != start) {
        int id = last[start];
        Edge e = g[start][id];
        start = e.to;
        id = e.rev;
        delta = std::min(delta, g[start][id].cap - g[start][id].flow);
      }

      start = sink;
      result += delta;
      while(source != start) {
        int id = last[start];
        Edge &e = g[start][id];
        start = e.to;
        id = e.rev;
        g[start][id].flow += delta;
        e.flow -= delta;
        result2 += delta * g[start][id].cost;
      }
      
      assert(0 < delta);
      for(int i = 0; i <= n; i++)
        if(dist[i] + dist2[i] < inf) 
          dist[i] += dist2[i];

      return 1;
    } else
      return 0;
  }

  std::pair<ll, ld> maxflow() {
    ll result = 0;
    ld result2 = 0;
    if(bellman() == false)
      return {0, 0};
    bool flag = true;
    do {
      flag = dijkstra(result, result2);
    } while(flag == true);
    return {result, result2};
  }
};

ld getdist(std::pair<int,int> a, std::pair<int,int> b) {
  return sqrtl((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
 
  std::vector<std::pair<int,int>> v;
  for(int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    v.push_back({y, x});
  }
  std::sort(v.begin(), v.end());
  std::reverse(v.begin(), v.end());
  Graph graph(1 + 2 * n);
  if(v[0].first == v[1].first) {
    std::cout << -1;
    return 0;
  }
  
  for(int i = 0; i < v.size(); i++) {
    graph.addEdge(0, 1 + i, 2, 0);
    for(int j = 0; j < i; j++) 
      if(v[i].first < v[j].first) 
        graph.addEdge(1 + j, n + 1 + i, 1, getdist(v[i], v[j]));
    if(0 < i)
      graph.addEdge(n + 1 + i, 2 * n + 1, 1, 0);
  }
  graph.setSourceSink(0, 2 * n + 1);
  std::pair<ll, ld> sol = graph.maxflow();
  if(sol.first == n - 1)
    std::cout << std::setprecision(9) << std::fixed << sol.second << '\n';
  else
    std::cout << -1 << '\n';
  return 0;
}