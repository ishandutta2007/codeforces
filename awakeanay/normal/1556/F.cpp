#include <iostream>
#include <vector>

#define int long long

const int MOD = 1'000'000'007;

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
  return expo(x%MOD, MOD-2);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int m = (1 << n);

  int a[n];
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::vector<int> bit(m, 1);

  int x[n][n], y[n][n];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      x[i][j] = a[i]*inv(a[i]+a[j]);
      x[i][j] %= MOD;
      y[i][j] = inv(x[i][j]);
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int prob = x[i][j];
      prob %= MOD;
      for(int k = 0; k < m; k++) {
        if(((k >> i)&1) && (!((k >> j)&1)))
          bit[k] = (bit[k]*prob)%MOD;
      }
    }
  }

  int ans = 0;
  int dp[m];

  dp[0] = 0;
  for(int i = 1; i < m; i++) {
    int cur = (i-1)&i;
    dp[i] = 1;
    while(cur) {
      int bit2 = 1;
      for(int p = 0; p < n; p++) {
        for(int q = 0; q < n; q++) {
          if(!((cur >> p)&1))
            continue;
          if((!((i >> q)&1)) || ((cur >> q)&1))
            continue;
          bit2 = (bit2*x[p][q])%MOD;
        }
      }
      dp[i] = (MOD + dp[i] - bit2*dp[cur])%MOD;
      cur = (cur-1)&i;
    }
    int pop = __builtin_popcount(i);
    cur = dp[i]*bit[i];
    cur %= MOD;
    ans = (ans + pop*cur)%MOD;
  }

  std::cout << ans << std::endl;

  return 0;
}