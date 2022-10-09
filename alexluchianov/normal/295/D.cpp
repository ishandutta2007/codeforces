#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 2000;
int const modulo = 1000000007;

int dp[1 + nmax][1 + nmax], sum[1 + nmax], pref[1 + nmax];

int main() {
  int n, m;
  std::cin >> n >> m;
  dp[0][0] = 1;
  for(int i = 0;i <= m; i++)
    if(1 != i)
      dp[1][i] = 1;
  
  for(int i = 2;i <= n; i++) {
    for(int j = 0; j <= m; j++) {
      if(0 < j)
        sum[j] = sum[j - 1];
      else
        sum[j] = 0;

      sum[j] += dp[i - 1][j];
      if(modulo <= sum[j])
        sum[j] -= modulo;
      
      if(0 < j)
        pref[j] = pref[j - 1];
      else
        pref[j] = 0;

      pref[j] += sum[j];
      if(modulo <= pref[j])
        pref[j] -= modulo;
    }

    for(int j = 0; j <= m; j++) {
      dp[i][j] = (pref[j] - j) % modulo;
      if(j == 1)
        dp[i][j] = 0;
    }
  }
  int result = 0;
  
  for(int i = 1;i <= n; i++) 
    for(int j = 2; j <= m; j++)
      result = (result + 1LL * dp[i][j] * (dp[n - i + 1][j] - dp[n - i][j]) % modulo * (m - j + 1)) % modulo;
  std::cout << result << '\n';
  return 0;
}