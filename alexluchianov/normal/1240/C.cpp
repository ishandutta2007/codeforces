#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 500000;

struct Edge{
  int to;
  int cost;
};
vector<Edge> g[1 + nmax];

int n, k;

ll dp[1 + nmax][2];

void dfs(int node, int parent){
  dp[node][0] = dp[node][1] = 0;
  vector<int> bonus;

  for(int h = 0; h < g[node].size(); h++){
    Edge e = g[node][h];
    if(e.to != parent){
      dfs(e.to, node);
      dp[node][0] += dp[e.to][1];
      dp[node][1] += dp[e.to][1];
      bonus.push_back(dp[e.to][0] + e.cost - dp[e.to][1]);
    }
  }
  sort(bonus.begin(), bonus.end());
  reverse(bonus.begin(), bonus.end());

  for(int i = 0; i < bonus.size(); i++){
    if(i + 1 <= (k - 1))
      if(0 <= bonus[i])
        dp[node][0] += bonus[i];
    if(i + 1 <= k)
      if(0 <= bonus[i])
        dp[node][1] += bonus[i];
  }
}

void solve(){
  cin >> n >> k;
  for(int i = 1;i <= n; i++)
    g[i].clear();

  for(int i = 1;i < n; i++){
    int x, y, cost;
    cin >> x >> y >> cost;
    g[x].push_back({y, cost});
    g[y].push_back({x, cost});
  }
  dfs(1, 0);
  cout << dp[1][1] << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();

  return 0;
}