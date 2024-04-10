#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int const nmax = 300000;

struct Edge{
  int x;
  int y;
  int cost;
  bool operator < (Edge const &a) const{
    return cost < a.cost;
  }
};
Edge edge[1 + nmax];
int dp[1 + nmax], dpnew[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= m; i++)
    cin >> edge[i].x >> edge[i].y >> edge[i].cost;
  sort(edge + 1, edge + m + 1);
  int result = 0, ptr = 1;

  while(ptr <= m){
    int cost = edge[ptr].cost;
    vector<int> update;
    while(ptr <= m && edge[ptr].cost == cost){
      update.push_back(edge[ptr].y);
      dpnew[edge[ptr].y] = max(dpnew[edge[ptr].y], dp[edge[ptr].x] + 1);
      ptr++;
    }
    for(int i = 0; i < update.size(); i++) {
      int node = update[i];
      dp[node] = max(dp[node], dpnew[node]);
      dpnew[node] = 0;
    }
  }

  for(int i = 1;i <= n; i++)
    result = max(result, dp[i]);
  cout << result;
  return 0;
}