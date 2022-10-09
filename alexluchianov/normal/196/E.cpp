#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <queue>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;

int const nmax = 100000;
ll const inf = 1000000000000000LL;

struct Edge{
  int to;
  ll cost;
  bool operator < (Edge const &a) const{
    return cost > a.cost;
  }
};

namespace Dsu{
  vector<int> mult;
  void initialize(int n){
    mult.resize(1 + n);
    for(int i = 1;i <= n; i++)
      mult[i] = i;
  }
  int jump(int gala){
    if(gala != mult[gala])
      mult[gala] = jump(mult[gala]);
    return mult[gala];
  }
  void unite(int gala, int galb){
    gala = jump(gala);
    galb = jump(galb);
    mult[gala] = galb;
  }
}

vector<Edge> g[1 + nmax];
int special[1 + nmax];
Edge far[1 + nmax][2];


void computefars(int n){
  for(int i = 1;i <= n; i++)
    far[i][0] = far[i][1] = {0, inf};
  priority_queue<Edge> pq;
  for(int i = 1;i <= n; i++){
    if(special[i] == 1){
      far[i][0] = {i, 0};
      pq.push({i, 0});
    }
  }
  while(0 < pq.size()){
    int node = pq.top().to;
    ll cost = pq.top().cost;
    pq.pop();
    if(cost == far[node][0].cost || cost == far[node][1].cost){
      for(int h = 0; h < g[node].size(); h++){
        Edge e = g[node][h];
        if(far[node][0].cost + e.cost < far[e.to][0].cost){
          if(far[node][0].to != far[e.to][0].to)
            far[e.to][1] = far[e.to][0];
          far[e.to][0] = {far[node][0].to, far[node][0].cost + e.cost};
          pq.push({e.to, far[e.to][0].cost});
        } else if(far[node][0].to != far[e.to][0].to && far[node][0].cost + e.cost < far[e.to][1].cost){
          far[e.to][1] = {far[node][0].to, far[node][0].cost + e.cost};
          pq.push({e.to, far[e.to][1].cost});
        }
        if(far[node][1].to != far[e.to][0].to && far[node][1].cost + e.cost < far[e.to][1].cost) {
          far[e.to][1] = {far[node][1].to, far[node][1].cost + e.cost};
          pq.push({e.to, far[e.to][1].cost});
        }
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= m; i++){
    int x, y, cost;
    cin >> x >> y >> cost;
    g[x].push_back({y, cost});
    g[y].push_back({x, cost});
  }
  Dsu::initialize(n);

  int k;
  cin >> k;
  for(int i = 1;i <= k; i++) {
    int val;
    cin >> val;
    special[val] = 1;
  }
  computefars(n);
  ll result = far[1][0].cost;

  while(1 < k){
    computefars(n);
    for(int i = 1;i <= n; i++){
      int node = Dsu::jump(i);
      if(special[node] == 0)
        continue;
      else {
        int to = Dsu::jump(far[node][1].to);
        if(node != to){
          Dsu::unite(to, node);
          result += far[node][1].cost;
          g[node].push_back({to, 0});
          g[to].push_back({node, 0});

          special[to] = 0;
          k--;
        }
      }
    }
  }
  cout << result << '\n';
  return 0;
}