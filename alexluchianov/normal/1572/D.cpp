#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <climits>
#include <queue>
#include <bitset>


int const nmax = 16010;
int const inf = 1000000000;

namespace MCMF {
  using namespace std;
  struct Edge{
    int to;
    int rev;
    int cost;
    int cap;
    int flow;
  };
  vector<Edge> g[1 + nmax];

  int n, src, dest;
  int dist[1 + nmax], dist2[1 + nmax];

  void addedge(int a, int b, int cost, int cap) {
    g[a].push_back({b, g[b].size(),      cost, cap, 0});
    g[b].push_back({a, g[a].size() - 1, -cost,   0, 0});
  }

  void bellmanford(){
    for(int i = 1 ; i <= n ;i++){
      dist[i] = inf;
    }
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while(0 < q.size()) {
      int from = q.front();
      q.pop();

      for(int i = 0; i < g[from].size(); i++) {
        Edge &e = g[from][i];
        if(e.flow < e.cap) { 
          if(dist[from] + e.cost < dist[e.to]) {
            dist[e.to] = dist[from] + e.cost;
            q.push(e.to);
          }
        }
      }
    }
  }
  struct Node {
    int node;
    int cost;

    bool operator > (Node a) const {
      return (cost > a.cost);
    }
  };

  int prevnode[1 + nmax], prevedge[1 + nmax];
  int augment[1 + nmax];
  bitset<1 + nmax> vis; 

  void dijkstra() {
    vis = 0;
    for(int i = 1; i <= n ;i++){
      dist2[i] = inf;
      augment[i] = 0;
      prevnode[i] = prevedge[i] = 0;
    }
    priority_queue<Node, vector<Node> , greater<Node> > pq;
    dist2[src] = 0;
    augment[src] = nmax;
    pq.push({src , dist2[src]});
    while(0 < pq.size()){
      int from = pq.top().node;
      pq.pop();
      if(vis[from] == 0) {
        vis[from] = 1;
        for(int i = 0; i < g[from].size(); i++) {
          Edge &e = g[from][i];
          if(e.flow < e.cap) {  
            int newdist = dist2[from] + (e.cost + dist[from] - dist[e.to]); 
            if(newdist < dist2[e.to]){
              dist2[e.to] = newdist;
              pq.push({e.to, newdist});
              prevnode[e.to] = from;
              prevedge[e.to] = i;
              augment[e.to] = min(augment[from], e.cap - e.flow);
            }
          }
        }
      }
    }
  }


  void fmcm(int &flow, int &flowcost) {
    bellmanford();
    flow = flowcost = 0;
    int t = 0;
    while(dist[dest] < inf && dist2[dest] < inf) {
      dijkstra();

      if(dist2[dest] < inf) {
        flow += augment[dest];
        int x = dest;
        while(x != src && x != 0){
          Edge &e = g[prevnode[x]][prevedge[x]];
          e.flow += augment[dest];
          g[x][e.rev].flow -= augment[dest];
          flowcost += e.cost * augment[dest];
          x = prevnode[x];
        }
        for(int i = 1 ; i <= n ;i++){
          dist[i] += dist2[i];
          if(inf < dist[i])
            dist[i] =inf;

        }
      }
    }
  }
};

int const valmax = 20;
int v[5 + 1<<valmax];

int const gmax = (1 << (valmax + 1));

std::vector<std::pair<int,int>> buck[5 + gmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;
  
  for(int i = 0; i < (1 << n); i++) {
    //v[i] = i;
    std::cin >> v[i];
  }

  for(int mask = 0; mask < (1 << n); mask++)
    for(int i = 0; i < n; i++)
      if(0 == (mask & (1 << i))) {
        buck[v[mask] + v[mask ^ (1 << i)]].push_back({mask, mask ^ (1 << i)});
      }

  std::vector<std::pair<int,int>> events;
  int lim = n * k * 2;
  for(int i = gmax; 0 <= i; i--)
    if(events.size() < lim) {
      for(int h = 0; h < buck[i].size(); h++)
        if(events.size() < lim)
          events.push_back(buck[i][h]);
        else
          break;
    } else
      break;

  std::vector<int> active;
  for(int i = 0; i < events.size(); i++) {
    active.push_back(events[i].first);
    active.push_back(events[i].second);
  }
  std::sort(active.begin(), active.end());
  active.erase(std::unique(active.begin(), active.end()), active.end());

  MCMF::src = 1;
  MCMF::addedge(1, 2, 0, k); 
  MCMF::n = MCMF::dest = 4 + active.size() ;

  auto findId = [&](int x) {
    int result = std::lower_bound(active.begin(), active.end(), x) - active.begin();
    if(result == active.size())
      return -1;
    else if(active[result] == x)
      return 3 + result;
    else
      return -1;
  };

  for(const auto &node : active) {
    if(__builtin_popcount(node) % 2 == 1) {
      MCMF::addedge(2, findId(node), -v[node], 1);
      for(int i = 0; i < n; i++) {
        int to = node ^ (1 << i);
        int newid = findId(to);
        if(newid != -1) {
          MCMF::addedge(findId(node), findId(to), 0, 1); 
        }
      }
    } else
      MCMF::addedge(findId(node), MCMF::dest, -v[node], 1);
  }
  int flow = 0;
  int cost = 0;
  MCMF::fmcm(flow, cost);

  std::cout << -cost << '\n';
  return 0;
}