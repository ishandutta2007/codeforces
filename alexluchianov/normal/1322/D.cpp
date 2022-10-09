#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <queue>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 2000;
int const inf = 1000000000;

int v[1 + nmax], dp[1 + nmax][1 + nmax];
int agro[1 + nmax], cost[1 + nmax], coef[1 + 2 * nmax];
int marker[1 + nmax][1 + nmax];

int n, m;

int eval(int start, int mask){
  int result = 0;
  for(int i = 0; i <= 10; i++)
    if((0 < (mask & (1 << i))))
      result += coef[start + i];
  return result;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    cin >> agro[i];
  for(int i = 1; i <= n; i++)
    cin >> cost[i];
  for(int i = 1; i <= n + m; i++)
    cin >> coef[i];

  for(int i = 0; i <= m; i++)
    for(int j = 0; j <= n; j++)
      dp[i][j] = -inf;

  for(int i = 0; i <= m; i++)
    dp[i][0] = 0;

  for(int i = n;1 <= i; i--){
    queue<pair<int,int>> q;
    for(int j = n; 1 <= j; j--) {
      dp[agro[i]][j] = max(dp[agro[i]][j], dp[agro[i]][j - 1] - cost[i] + eval(agro[i], (j ^ (j - 1))));
      q.push({agro[i], j});
    }

    while(0 < q.size()){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      if(x <= m && marker[x][y] != i){
        marker[x][y] = i;
        dp[x + 1][y / 2] = max(dp[x + 1][y / 2], dp[x][y]);
        q.push({x + 1, y / 2});
      }
    }
  }

  int result = 0;
  for(int i = 0; i <= m; i++)
    for(int j = 0; j <= n; j++)
      result = max(result, dp[i][j]);
  cout << result;
  return 0;
}