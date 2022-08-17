#include <iostream>

#define int long long

const int MAXN = 400005;
const int MOD = 998244353;

int fact[MAXN];

int expo(int x, int p) {
  int ret = 1;
  while(p > 0) {
    if(p&1)
      ret = (ret*x)%MOD;
    x = (x*x)%MOD;
    p >>= 1;
  }
  return ret;
}

int inv(int x) {
  return expo(x, MOD-2);
}

signed main() {
  int n, k;
  std::cin >> n >> k;
  k--;

  fact[0] = 1;
  for(int i = 1; i < MAXN; i++)
    fact[i] = (i*fact[i-1])%MOD;

  int val[n+1];
  val[n] = -1;

  int a[n];
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    val[a[i]] = i;
  }

  for(int i = 0; i+1 < n; i++) {
    if(val[a[i]+1] > val[a[i+1]+1])
      k--;
  }

  if(k < 0) {
    std::cout << 0 << std::endl;
    return 0;
  }

  int ans = fact[n+k]*inv(fact[k]);
  ans %= MOD;
  ans *= inv(fact[n]);
  ans %= MOD;

  std::cout << ans << std::endl;

  return 0;
}