#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
using ld = long double;

int const nmax = 150;
ll const inf = 1000000000LL * nmax;

int v[1 + nmax];
ll dp[1 + nmax][1 + nmax * nmax];

int main()
{
  int n, k, s;
  cin >> n >> k >> s;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n * n; j++)
      dp[i][j] = inf;
  int sum = 0;
  dp[0][0] = 0;
  for(int i = 1;i <= n; i++){
    for(int j = i; 1 <= j; j--)
      for(int h = (i - j); h <= sum; h++)
        dp[j][h] = min(dp[j][h], dp[j - 1][h - (i - j)] + v[i]);
    sum += i;
  }
  ll result = inf;
  for(int i = 0; i <= min(s, sum - n); i++)
    result = min(result, dp[k][i]);
  cout << result;
  return 0;
}