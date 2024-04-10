#include <iostream>
#include <algorithm>

#define int long long
#define MOD 998244353

int exp(int x, int p) {
  int ret = 1;
  while(p > 0) {
    if(p & 1) {
      ret = (ret*x)%MOD;
    }

    p >>= 1;
    x = (x*x)%MOD;
  }

  return ret;
}

int inv(int x) {
  return exp(x, MOD-2);
}

signed main() {
  int n;
  std::cin >> n;

  int a[2*n];
  for(int i = 0; i < 2*n; i++)
    std::cin >> a[i];

  std::sort(a, a+2*n);

  int sum = 0;
  for(int i = n; i < 2*n; i++)
    sum = (sum + a[i])%MOD;
  for(int i = 0; i < n; i++) 
    sum = (sum + 2*MOD - a[i])%MOD;

  int fact[2*n+1];
  fact[0] = 1;
  for(int i = 1; i <= 2*n; i++)
    fact[i] = (fact[i-1]*i)%MOD;

  sum *= fact[2*n];
  sum %= MOD;
  sum *= exp(fact[n], 2*MOD-4);
  sum %= MOD;

  std::cout << sum << std::endl;

  return 0;
}