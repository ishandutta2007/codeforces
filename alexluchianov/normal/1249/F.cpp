#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int const nmax = 200;
vector<int> g[5 + nmax];

int val[5 + nmax];
int dp[5 + nmax][5 + nmax];
int dp2[5 + nmax][5 + nmax];

int n, k;

void dfs(int node, int parent){
  dp[node][0] = val[node];
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent) {
      dfs(to, node);
      for(int i = 0; i <= nmax; i++)
        dp2[node][i] = 0;
      for(int i = 0; i <= nmax; i++)
        for(int j = 0; j < nmax; j++)
          if(k < i + j + 1)
            dp2[node][min(i, j + 1)] = max(dp2[node][min(i, j + 1)], dp[node][i] + dp[to][j]);

      for(int i = 0; i < nmax; i++)
        dp[node][i] = max(dp[node][i], dp2[node][i]);
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for(int i = 1;i <= n; i++)
    cin >> val[i];
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  int result = 0;

  for(int i = 0; i <= nmax; i++)
    result = max(result, dp[1][i]);
  cout << result;
  return 0;
}