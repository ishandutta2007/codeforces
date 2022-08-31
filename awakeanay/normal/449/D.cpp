#include <iostream>
#include <vector>

#define int long long

const int MOD = 1'000'000'007;

const int k = 20;
const int m = (1 << k);
std::vector<int> f(m, 0), g(m, 0);
int dp[m][k+1];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int p2[n+1];
  p2[0] = 1;
  for(int i = 1; i <= n; i++)
    p2[i] = (2*p2[i-1])%MOD;


  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    x = m-1-x;
    f[x]++;
  }

  for(int i = 0; i < m; i++) {
    dp[i][0] = f[i];

    for(int j = 1; j <= k; j++) {
      if((i >> (j-1))&1)
        dp[i][j] = dp[i][j-1] + dp[i^(1 << (j-1))][j-1];
      else
        dp[i][j] = dp[i][j-1];
    }

    g[i] = p2[dp[i][k]];
  }

  for(int i = 0; i < m; i++) {
    dp[i][0] = 0;

    for(int j = 1; j <= k; j++) {
      if((i >> (j-1))&1)
        dp[i][j] = (dp[i][j-1] + dp[i^(1 << (j-1))][j-1])%MOD;
      else
        dp[i][j] = dp[i][j-1];
    }

    f[i] = (g[i] - dp[i][k] + MOD)%MOD;
    for(int j = 0; j <= k; j++)
      dp[i][j] = (dp[i][j] + f[i])%MOD;
  }

  std::cout << f[m-1] << std::endl;

  return 0;
}