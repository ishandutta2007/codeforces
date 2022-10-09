#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int const nmax = 200000;
int const inf = 1000000000;

int v[1 + nmax], v2[1 + nmax];
int dp[1 + nmax][2];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, c;
  cin >> n >> c;
  for(int i = 1;i < n; i++)
    cin >> v[i];
  for(int i = 1;i < n; i++)
    cin >> v2[i];
  for(int i = 1; i <= n; i++)
    dp[i][0] = dp[i][1] = inf;
  dp[1][0] = 0;
  for(int i = 2;i <= n; i++){
    dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + v[i - 1];
    dp[i][1] = min(dp[i - 1][0] + c, dp[i - 1][1]) + v2[i - 1];
  }
  for(int i = 1;i <= n; i++)
    cout << min(dp[i][0], dp[i][1]) << " ";
  cout << '\n';

  return 0;
}