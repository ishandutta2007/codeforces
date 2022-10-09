#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
ll const inf = 1000000000000000000LL;

struct Node{
  ll cost;
  int node;
  bool operator < (Node const &a) const{
    return cost > a.cost;
  }
};

struct Edge{
  int to;
  int cost;
};
vector<Edge> g[1 + nmax];
ll dp[1 + nmax];
int seen[1 + nmax], last[1 + nmax];

void printpath(int node){
  if(1 < node)
    printpath(last[node]);
  cout << node << " " ;
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
  for(int i = 1;i <= n; i++) {
    dp[i] = inf;
    last[i] = 0;
  }

  priority_queue<Node> pq;
  pq.push({0, 1});
  dp[1] = 0;
  while(0 < pq.size()){
    int node = pq.top().node;
    pq.pop();
    if(seen[node] == 0){
      seen[node] = 1;
      for(int h = 0; h < g[node].size(); h++){
        Edge e = g[node][h];
        if(dp[node] + e.cost < dp[e.to]){
          dp[e.to] = dp[node] + e.cost;
          last[e.to] = node;
          pq.push({dp[e.to], e.to});
        }
      }
    }
  }

  if(dp[n] == inf)
    cout << -1;
  else {
    printpath(n);
  }
  return 0;
}