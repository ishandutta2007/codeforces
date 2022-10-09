#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <queue>

using ll = long long;

int const nmax = 10000;
ll const inf = 1000000000000000000;

struct Edge{
  int to;
  int cost;
  int id;
};
std::vector<Edge> g[1 + nmax];
int orig[4][1 + nmax];
ll dist[1 + nmax], dp[1 + nmax];

bool check(int n, int k, int s1, int s2, int f, int target) {
  for(int i = 1;i <= n; i++)
    dp[i] = inf;
  dp[s1] = 0;
  std::priority_queue<std::pair<ll,int>, std::vector<std::pair<ll,int>>, std::greater<std::pair<ll,int>>> pq;
  pq.push({0, s1});
  while(0 < pq.size()) {
    ll cost = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if(cost == dp[node] && dp[node] <= dist[node] - target) {
      for(int h = 0; h < g[node].size(); h++) {
        Edge e = g[node][h];
        if(dp[node] + e.cost < dp[e.to]) {
          dp[e.to] = dp[node] + e.cost;
          pq.push({dp[e.to], e.to});
        }
      }
    }
  }
  /*
  for(int i = 1;i <= n; i++)
    std::cout << dist[i] << " ";
  std::cout << '\n';
  for(int i = 1;i <= n; i++)
    std::cout << dp[i] << " ";
  std::cout << '\n';
  */


  if(dp[f] <= dist[f] - target) {
    if(target == 1) 
      std::cout << "WIN\n";
    else
      std::cout << "DRAW\n";
    for(int i = 1;i <= k; i++) {
      int x = orig[2][i];
      int y = orig[3][i];
      if(dp[x] <= dist[x] - target && dp[y] <= dist[y] - target && dp[x] + orig[0][i] == dp[y]) {
        std::cout << orig[0][i] << " ";
      } else
        std::cout << orig[1][i] << " ";
    }
    std::cout << '\n';
    return true;
  }
  return false;
}

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  int s1, s2, f;
  std::cin >> s1 >> s2 >> f;
  for(int i = 1; i <= m; i++) {
    int x, y, cost;
    std::cin >> x >> y >> cost;
    g[x].push_back({y, cost, 0});
  }
  for(int i = 1;i <= k; i++) {
    int x, y, l, r;
    std::cin >> x >> y >> l >> r;
    g[x].push_back({y, r, 0});
    g[x].push_back({y, l, i});
    orig[0][i] = l;
    orig[1][i] = r;
    orig[2][i] = x;
    orig[3][i] = y;
  }
  
  if(s1 == s2) {
    std::cout << "DRAW\n";
    for(int i = 1; i <= k; i++) 
      std::cout << orig[0][i] << " ";
    std::cout << '\n';
    return 0;
  }

  for(int i = 1;i <= n; i++)
    dist[i] = inf;
  dist[s2] = 0;
  std::priority_queue<std::pair<ll,int>, std::vector<std::pair<ll,int>>, std::greater<std::pair<ll,int>>> pq;
  pq.push({0, s2});
  
  while(0 < pq.size()) {
    ll cost = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if(dist[node] == cost) {
      for(int h = 0; h < g[node].size(); h++) {
        Edge e = g[node][h];
        if(e.id == 0 && dist[node] + e.cost < dist[e.to]) {
          dist[e.to] = dist[node] + e.cost;
          pq.push({dist[e.to], e.to});
        }
      }
    }
  }
  if(check(n, k, s1, s2, f, 1) == false) {
    if(check(n, k, s1, s2, f, 0) == false) {
      std::cout << "LOSE\n";
      return 0;
    }
  }
  return 0;
}