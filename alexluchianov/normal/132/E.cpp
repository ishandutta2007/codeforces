#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>
#include <map>

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

int const sigma = 31;

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  MFMC graph(1 + 3 * n);
  std::map<int,int> frec;
  std::vector<int> v(1 + n);
  for(int i = 1; i <= n; i++) {
    int val;
    std::cin >> val;
    v[i] = val;
    graph.addEdge((i - 1) * 3, i * 3 - 2, 1, __builtin_popcount(val));
    graph.addEdge(i * 3 - 2, i * 3 - 1, 1, n * -sigma);
    graph.addEdge(i * 3 - 1, i * 3, 1, 0);
    graph.addEdge((i - 1) * 3, i * 3, m, 0);

    if(0 < frec[val]) 
      graph.addEdge(frec[val] * 3 - 1, i * 3 - 2, 1, 0);
    frec[val] = i;
  }
  graph.addEdge(3 * n + 1, 0, m, 0);

  graph.setSourceSink(3 * n + 1, 3 * n);
  std::pair<int,ll> sol = graph.getflow();
  assert(sol.first == m);
  ll result = sol.second + 1LL * sigma * n * n;
  std::vector<std::string> answer;
  frec.clear();

  int freemask = (1 << m) - 1;

  for(int i = 1;i <= n; i++) {
    int node = i * 3 - 2;
    bool verdict = false;
    for(int h = 0; h < graph.g[node].size(); h++) {
      Edge &e = graph.g[node][h];
      if(e.to == (i - 1) * 3 && e.flow < 0) {
        int bit = __builtin_ctz(freemask);
        answer.push_back(std::string(1, char(bit + 'a')) + "=" + std::to_string(v[i]));
        answer.push_back(std::string("print(") + char(bit + 'a') + ")");
        freemask ^= (1 << bit);
        verdict = true;
        frec[v[i]] = bit;
      }
    }
    if(verdict == false) 
      answer.push_back(std::string("print(") + char(frec[v[i]] + 'a') + ")");
    node = i * 3 - 1;
    for(int h = 0; h < graph.g[node].size(); h++) {
      Edge &e = graph.g[node][h];
      if(e.to == i * 3 && e.flow == 1) {
        freemask ^= (1 << frec[v[i]]);
        frec[v[i]] = -1;
      }
    }
  }

  std::cout << answer.size() << " " << result << '\n';
  for(int i = 0; i < answer.size(); i++)
    std::cout << answer[i] << '\n';
  return 0;
}