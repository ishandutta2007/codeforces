#include <iostream>

#define int long long

const int MOD = 1'000'000'007;

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
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;

  int nt = 3*n+3;

  int cur = 1;
  int a[nt+1];
  for(int i = 0; i <= nt; i++) {
    a[i] = cur;
    cur *= nt-i;
    cur %= MOD;
    cur *= inv(i+1);
    cur %= MOD;
  }

  a[0] = 0;

  for(int i = nt; i >= 2; i--) {
    a[i-1] = (a[i-1] - (3*a[i])%MOD + MOD)%MOD;
    a[i-2] = (a[i-2] - (3*a[i])%MOD + MOD)%MOD;
  }

  while(q--) {
    int x;
    std::cin >> x;

    std::cout << a[x+3] << std::endl;
  }
}