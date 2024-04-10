#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
using ld = double;
int const nmax = 1000;
int const inf = 1000000000;

ld p[1 + nmax][1 + nmax];
ld dp[1 + nmax], cost[1 + nmax], coef[1 + nmax];
int seen[1 + nmax];

void update(int node, int to){
  cost[node] += coef[node] * p[node][to] * (1 + dp[to]);
  coef[node] = coef[node] * (1 - p[node][to]);
  ld result;
  if(coef[node] == 1)
    result = inf;
  else
    result = (cost[node] + coef[node]) / (1 - coef[node]);
  dp[node] = MIN(dp[node], result);
}

struct Node{
  ld cost;
  int node;
  bool operator < (Node const &a) const{
    return a.cost < cost;
  }
};

int main()
{
  srand(time(NULL));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    for(int j = 1; j <= n; j++) {
      int val;
      cin >> val;
      p[i][j] = val / 100.0;
    }


  for(int i = 1;i <= n; i++)
    dp[i] = inf;
  dp[n] = 0;
  for(int i = 1;i < n; i++) {
    cost[i] = 0;
    coef[i] = 1;
  }

  priority_queue<Node> pq;
  pq.push({0, n});
  while(0 < pq.size()){
    int node = pq.top().node;
    pq.pop();
    if(seen[node] == 0){
      seen[node] = 1;
      for(int i = 1;i <= n; i++)
        if(seen[i] == 0) {
          ld old = dp[i];
          update(i, node);
          if(dp[i] < old)
            pq.push({dp[i], i});
        }
    }
  }
  cout << setprecision(8) << fixed << dp[1];
  return 0;
}