#include <iostream>

#define int long long

#define MOD (998244353)

int exp(int x, int p) {
  int ret = 1;
  while(p > 0) {
    if(p&1) {
      ret = (ret*x)%MOD;
    }
    x = (x*x)%MOD;
    p >>= 1;
  }
  return ret;
}

int inv(int x) {
  return exp(x, MOD-2);
}

signed main() {
  int n;
  std::cin >> n;

  int fact[3*n+1];
  fact[0] = 1;
  for(int i = 1; i < 3*n+1; i++) {
    fact[i] = (fact[i-1]*i)%MOD;
  }

  int ways = 0;
  for(int i = 1 + (n%2 == 0); i <= n; i+=2) {
    int k = i-1;
    int d = (n-k)/2;
    ways += (fact[d+k]*inv((fact[d]*fact[k])%MOD))%MOD;
    ways %= MOD;
  }

  std::cout << (ways*exp(inv(2),n))%MOD << std::endl;

  return 0;
}