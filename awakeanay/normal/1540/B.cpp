#include <iostream>

#define int long long

const int MOD = 1000000007;
const int INF = 100000000000;

int expo(int x, int p) {
  int ret = 1;
  while(p > 0) {
    if(p&1)
      ret = (ret*x)%MOD;
    p >>= 1;
    x = (x*x)%MOD;
  }
  return ret;
}

int inv(int x) {
  return expo(x, MOD-2);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int d[n][n];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      d[i][j] = (i == j) ? 0 : INF;

  for(int i = 1; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    x--; y--;
    d[x][y] = d[y][x] = 1;
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (d[i][k] < INF && d[k][j] < INF)
          d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]); 
      }
    }
  }

  int dp[n][n];
  for(int i = 1; i < n; i++) {
    dp[0][i] = 1;
    dp[i][0] = 0;
  }

  for(int i = 1; i < n; i++) {
    for(int j = 1; j < n; j++) {
      dp[i][j] = (dp[i-1][j] + dp[i][j-1])*inv(2);
      dp[i][j] %= MOD;
    }
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      for(int k = 0; k < n; k++) {
        int diff = d[k][j]-d[k][i];
        int sum = d[i][j];
        int a = (sum+diff)/2;
        int b = (sum-diff)/2;
        ans += dp[a][b];
        ans %= MOD;
      }
    }
  }

  ans *= inv(n);
  ans %= MOD;
  std::cout << ans << std::endl;

  return 0;
}