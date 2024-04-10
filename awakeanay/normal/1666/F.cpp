#include <iostream>

#define int long long

const int MAXN = 5005;
const int MOD = 998244353;

int bit[MAXN];

void add(int x, int v) {
  x += 1;
  while(x < MAXN) {
    bit[x] = (bit[x] + v)%MOD;
    x += x&-x;
  }
}

int sum(int x) {
  x += 1;
  int ret = 0;
  while(x > 0) {
    ret = (ret + bit[x])%MOD;
    x -= x&-x;
  }
  return ret;
}

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

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int less[n];
    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    if(a[n-1] == a[n-2]) {
      std::cout << 0 << std::endl;
      continue;
    }

    if(n == 2) {
      std::cout << 1 << std::endl;
      continue;
    }

    int cur = 0;
    for(int i = 0; i < n; i++) {
      while(cur < i && a[cur] < a[i])
        cur++;
      less[i] = cur;
    }

    int m = n/2;
    int dp[2][n];
    for(int i = 0; i < n; i++) {
      dp[1][i] = less[i]*(less[i] - 1);
      //std::cout << -1 << " " << i << " " << dp[1][i] << std::endl;
      if(i)
        dp[1][i] = (dp[1][i] + dp[1][i-1])%MOD;
    }

    for(int j = 0; j+1 < m; j++) {
      int u = j%2;
      int v = u^1;

      for(int i = 0; i < n; i++) {
        int mult;
        if(j+2 < m)
          mult = std::max(0ll, less[i] - 2*(j + 1) - 1);
        else
          mult = 1;
        dp[u][i] = (less[i] == 0 ? 0 : dp[v][less[i]-1])*mult;
        //std::cout << j << " " << i << " " << dp[u][i] << std::endl;
        if(i)
          dp[u][i] = (dp[u][i] + dp[u][i-1])%MOD;
      }
    }

    int ans = dp[m%2][n-1];

    for(int i = 0; i < n; i++) {
      int j = i;
      while(j < n && a[j] == a[i])
        j++;
      int fact = 1;
      int val = j-i;
      for(int k = 1; k <= val; k++)
        fact = (fact*k)%MOD;
      ans = ans*inv(fact);
      ans %= MOD;
      i = j-1;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}