#include <iostream>

#define int long long

const int MOD = 998244353;
const int LCM = 720720;

int ct[LCM];

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

  int ans = 0;

  int n, a, x, y, k, M;
  std::cin >> n >> a >> x >> y >> k >> M;

  int p = inv(n);

  for(int i = 0; i < n; i++) {
    ct[a%LCM]++;
    ans = (ans + k*p*a)%MOD;
    a = (a*x + y)%M;
  }

  for(int i = 1; i <= k; i++) {
    for(int j = 0; j < LCM; j++) {
      x = (p*ct[j])%MOD;
      ans = (ans - (x*(j%i)*(((k-i)*p)%MOD))%MOD + MOD)%MOD;
      ct[j] = (ct[j] - x + MOD)%MOD;
      ct[j-j%i] = (ct[j-j%i] + x)%MOD;
    }
  }

  for(int i = 1; i <= k; i++)
    ans = (ans*n)%MOD;
  std::cout << ans << std::endl;

  return 0;
}