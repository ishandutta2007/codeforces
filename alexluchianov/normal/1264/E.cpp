#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

using ll = long long;
struct Edge{
  int to;
  int rev;
  int flow;
  int cap;
  int cost;
};
 
class MFMC{
  private:
    int const hardlimit = 10000000;
    ll const inf = 1000000000000000000;
    int const flowmax = 1000000000;
 
    std::vector<ll> dist;
    int source, sink, n;
  public:
    std::vector<std::vector<Edge>> g;
    MFMC(int n_) {
      n = n_;
      g.resize(1 + n);
      dist.resize(1 + n);
    }
 
    void addEdge(int x, int y, int cap, int cost) {
      g[x].push_back({y, g[y].size(), 0, cap, cost});
      g[y].push_back({x, g[x].size() - 1, 0, 0, -cost});
    }
    void setSourceSink(int source_, int sink_) {
      source = source_;
      sink = sink_;
    }
 
    bool bellman() {
      for(int i = 0; i <= n; i++) 
        dist[i] = inf;
      std::queue<int> q;
      std::vector<int> in_queue(1 + n);
      dist[source] = 0;
      in_queue[source] = 1;
      q.push(source);
 
      int steps = 0;
      while(0 < q.size() && steps < hardlimit) {
        int node = q.front();
        in_queue[node] = 0;
        q.pop();
        for(int h = 0; h < g[node].size(); h++) {
          ++steps;
          Edge e = g[node][h];
          if(e.flow < e.cap && dist[node] + e.cost < dist[e.to]) {
            dist[e.to] = dist[node] + e.cost;
            if(in_queue[e.to] == 0) {
              in_queue[e.to] = 1;
              q.push(e.to);
            }
          }
        }
      }
 
      return dist[sink] < inf && 0 == q.size();
    }
 
    bool dijkstra(int &globalflow, ll &globalcost) {
      std::vector<ll> dist2(1 + n);
      std::vector<int> last(1 + n);
      for(int i = 0; i <= n; i++)
        dist2[i] = inf;
      std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<std::pair<ll,int>>> pq;
      dist2[source] = 0;
      pq.push({dist2[source], source});
 
      while(0 < pq.size()) {
        ll curr = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(curr == dist2[node]) {
          for(int h = 0; h < g[node].size(); h++) {
            Edge &e = g[node][h];
            ll cost = e.cost - dist[e.to] + dist[node];
            if(e.flow < e.cap && dist2[node] + cost < dist2[e.to]) {
              dist2[e.to] = dist2[node] + cost;
              last[e.to] = e.rev;
              pq.push({dist2[e.to], e.to});
            }
          }
        }
      }
      for(int i = 0; i <= n; i++) {
        dist[i] += dist2[i];
        if(inf < dist[i])
          dist[i] = inf;
      }
      if(dist2[sink] == inf)
        return false;
      int deltaflow = flowmax;
      int start = sink;
 
      while(source != start) {
        int to = g[start][last[start]].to;
        int id = g[start][last[start]].rev;
        Edge &e = g[to][id];
        deltaflow = std::min(deltaflow, e.cap - e.flow);
        start = to;
      }
      assert(0 < deltaflow);
      start = sink;
      while(source != start) {
        int to = g[start][last[start]].to;
        int id = g[start][last[start]].rev;
        Edge &e = g[to][id];
        globalcost += deltaflow * e.cost;
        e.flow += deltaflow;
        g[start][last[start]].flow -= deltaflow;
        start = to;
      }
      globalflow += deltaflow;
      return true;
    }
 
    std::pair<int, ll> getflow() {
      if(bellman() == false)
        return {-1, 0};
      int globalflow = 0;
      ll globalcost = 0;
      while(dijkstra(globalflow, globalcost) == true);
      return {globalflow, globalcost};
    }
};

int const nmax = 50;
int mat[1 + nmax][1 + nmax];

int main() {
  int n, m;
  std::cin >> n >> m;
  MFMC graph(1 + n + n * n + n * n + 1);
  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    mat[x][y] = 1;
  }
  
  int id = 0;

  for(int i = 1;i <= n; i++)
    for(int j = i + 1; j <= n; j++)
      if(i != j) {
        id = n * i + j;
        graph.addEdge(0, id, 1, 0);
        if(mat[i][j] == 1) {
          graph.addEdge(id, i, 1, 0);
        } else if(mat[j][i] == 1) {
          graph.addEdge(id, j, 1, 0);
        } else {
          graph.addEdge(id, i, 1, 0);
          graph.addEdge(id, j, 1, 0);
        }
      }

  for(int i = 1;i <= n; i++)
    for(int j = 1; j <= n; j++) {
      graph.addEdge(i, n + n * n + n * (i - 1) + j, 1, j - 1);
      graph.addEdge(n + n * n + n * (i - 1) + j, n + n * n + n * n + 1, 1, 0);
    }
  graph.setSourceSink(0, n + n * n + n * n + 1);
  std::pair<int,ll> sol = graph.getflow();
  
  for(int i = 1;i <= n; i++) {
    for(int j = 1;j <= n; j++) {
      int id = std::min(i, j) * n + std::max(i, j);
      bool verdict = 0;
      for(int h = 0;h < graph.g[id].size(); h++) {
        Edge e = graph.g[id][h];
        if(e.to == i && e.flow == 1)
          verdict = 1;
      }
      std::cout << verdict;
    }
    std::cout << '\n';
  }
  return 0;
}