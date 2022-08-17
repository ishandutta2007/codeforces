#include <iostream>

#define int long long

const int MOD = 998244353;
const int MAXN = 200005;

int fact[MAXN];

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

  fact[0] = 1;
  for(int i = 1; i < MAXN; i++) 
    fact[i] = (i*fact[i-1])%MOD;

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int max = -1, smax = -1;
    int cmax = 0, csmax = 0;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;

      if(x == max) {
        cmax++;
      }
      else if(x > max) {
        smax = max;
        csmax = cmax;
        max = x;
        cmax = 1;
      }
      else if(x > smax) {
        smax = x;
        csmax = 1;
      }
      else if(x == smax) {
        csmax++;
      }
    }

    if(cmax > 1) {
      std::cout << fact[n] << std::endl;
    }
    else if(smax != max-1) 
      std::cout << 0 << std::endl;
    else {
      int cur = (fact[n]*inv(csmax+1))%MOD;
      cur = (cur*csmax)%MOD;
      std::cout << cur << std::endl;
    }
  }

  return 0;
}