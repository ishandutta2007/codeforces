#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 100000;
int const lgmax = 20;
int sum[1 + lgmax][1 + nmax];
int dp[1 + (1 << lgmax)];

int main()
{
  int n, m, d;
  cin >> n >> m >> d;
  for(int i = 0;i < m; i++){
    int sz;
    cin >> sz;
    for(int j = 1;j <= sz; j++){
      int pos;
      cin >> pos;
      sum[i][pos]++;
    }
  }
  for(int i = 0;i < m; i++)
    for(int j = 1;j <= n; j++)
      sum[i][j] += sum[i][j - 1];

  for(int i = d;i <= n; i++){
    int mask = 0;
    for(int j = 0;j < m; j++)
      if(0 < sum[j][i] - sum[j][i - d])
        mask |= (1 << j);
    dp[mask] = 1;
  }
  for(int mask = 0; mask < (1 << m); mask++)
    for(int i = 0; i < m; i++)
      if(0 < ((1 << i) & mask))
        dp[mask] |= dp[mask ^ (1 << i)];

  int result = m;
  for(int mask = 0; mask < (1 << m); mask++)
    if(dp[((1 << m) - 1) ^ mask] == 0)
      result = min(result, __builtin_popcount(mask));
  cout << result;
  return 0;
}