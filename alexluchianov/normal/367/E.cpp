#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 1000;
int const modulo = 1000000007;
int dp[1 + nmax][1 + nmax];
int sum[1 + nmax][1 + nmax];

int main()
{
  int n, m, cond;
  cin >> n >> m >> cond;
  if(m < n) {
    cout << 0;
    return 0;
  }
  dp[0][0] = 1;
  sum[0][0] = 1;
  for(int val = 1; val <= m; val++){
    for(int i = 0; i <= n; i++)
      for(int j = 0; j <= i; j++) {
        dp[i][j] = 0;
        if(0 < i)
          dp[i][j] += sum[i - 1][j];

        if(0 < j && val != cond)
          dp[i][j] += sum[i][j - 1];
        if(modulo <= dp[i][j])
          dp[i][j] -= modulo;

        if(0 < i && 0 < j)
          dp[i][j] += sum[i - 1][j - 1];
        if(modulo <= dp[i][j])
          dp[i][j] -= modulo;
      }

    if(val == cond)
      for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
          sum[i][j] = 0;

    for(int i = 0; i <= n; i++)
      for(int j = 0; j <= n; j++) {
        sum[i][j] += dp[i][j];
        if(modulo <= sum[i][j])
          sum[i][j] -= modulo;
      }
  }
  int result = sum[n][n];
  for(int i = 1;i <= n; i++)
    result = 1LL * result * i % modulo;
  cout << result;
  return 0;
}