#include <iostream>

#define int long long

const int MOD = 1000000007;

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

const int MAXN = 1000006;

int fact[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  fact[0] = 1;
  for(int i = 1; i < MAXN; i++) {
    fact[i] = (i*fact[i-1])%MOD;
  }

  int t;
  std::cin >> t;

  while(t--) {
    int n, m, k;
    std::cin >> n >> m >> k;

    int p[n+1];
    p[0] = 0;
    for(int i = 1; i <= n; i++)
      p[i] = 2*i-1;

    int ans = 0;
    for(int j = m; j >= 0; j--) {
      int ch = fact[n-1];
      int k = m-j;
      ch *= inv(fact[k]);
      ch %= MOD;
      ch *= inv(fact[n-1-k]);
      ch %= MOD;

      ans += p[j]*ch;
      ans %= MOD;
    }
    for(int i = 1; i < n; i++)
      ans = (ans*inv(2))%MOD;

    std::cout << (ans*k)%MOD << std::endl;
  }

  return 0;
}