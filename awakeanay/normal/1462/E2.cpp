#include <iostream>
#include <algorithm>

#define int long long

const int MOD = 1000000007;

int exp(int x, int p) {
  int ret = 1;
  while(p > 0) {
    if(p & 1)
      ret = (ret*x)%MOD;

    p >>= 1;
    x = (x*x)%MOD;
  }

  return ret;
}

int inv(int x) {
  return exp(x, MOD-2);
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m, k;
    std::cin >> n >> m >> k;

    int fact[n+1];
    fact[0] = 1;
    for(int i = 1; i <= n; i++)
      fact[i] = (i*fact[i-1])%MOD;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    std::sort(a, a+n);

    int l = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      while(a[i] - a[l] > k)
        l++;

      if(i-l < m-1)
        continue;

      ans += (((fact[i-l]*inv(fact[i-l-m+1]))%MOD)*inv(fact[m-1]))%MOD;
      ans %= MOD;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}