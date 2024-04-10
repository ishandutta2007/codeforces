#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

int const nmax = 100;
int const sigma = 26;
char s[5 + nmax];
int v[5 + nmax];
int frec[1 + sigma];

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> s[i];
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i <= n; i++)
    frec[s[i] - 'a']++;
  MFMC graph(1 + n / 2 + sigma + 1);
  graph.setSourceSink(0, n / 2 + sigma + 1);
  for(int i = 0;i < sigma; i++)
    graph.addEdge(n / 2 + 1 + i, n / 2 + sigma + 1, frec[i], 0);
  for(int i = 1; i <= n/ 2; i++) {
    graph.addEdge(0, i, 2, 0);
    if(s[i] == s[n + 1 - i]) {
      for(int j = 0; j < sigma; j++)
        if(s[i] != ('a' + j))
          graph.addEdge(i, n / 2 + 1 + j, 1, 0);
        else
          graph.addEdge(i, n / 2 + 1 + j, 1, -std::max(v[n + 1 - i], v[i]));
    } else {
      for(int j = 0; j < sigma; j++)
        if(s[i] != ('a' + j) && s[n + 1 - i] != ('a' + j))
          graph.addEdge(i, n / 2 + 1 + j, 1, 0);
        else if(s[i] == ('a' + j))
          graph.addEdge(i, n / 2 + 1 + j, 1, -v[i]);
        else
          graph.addEdge(i, n / 2 + 1 + j, 1, -v[n + 1 - i]);
    }
  }
  std::cout << -(graph.getflow().second) << '\n';
  return 0;
}