#include <iostream>

#define int long long
#define MOD (1000000007)

int a, b, n;

bool isG(int x) {
  while(x > 0) {
    if(x%10 != a && x%10 != b)
      return false;
    x /= 10;
  }
  return true;
}

int exp(int x, int p) {
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
  return exp(x, MOD-2);
}

signed main() {
  std::cin >> a >> b >> n;

  int fact[n+1];
  fact[0] = 1;
  for(int i = 1; i <= n; i++)
    fact[i] = (fact[i-1]*i)%MOD;

  int ans = 0;
  for(int i = 0; i <= n; i++) {
    if(isG(a*i + b*(n-i))) {
      ans = (ans + (fact[n]*inv((fact[i]*fact[n-i])%MOD))%MOD + MOD)%MOD;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}