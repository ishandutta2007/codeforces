#include <iostream>

#define int long long

const int MOD = 1000'000'007;
const int MAXN = 500005;

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

int choose(int n, int r) {
  if(n < r || r < 0 || n < 0)
    return 0;
  int ans = fact[n]*inv(fact[r]);
  ans %= MOD;
  ans *= inv(fact[n-r]);
  ans %= MOD;
  return ans;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  fact[0] = 1;
  for(int i = 1; i < MAXN; i++) {
    fact[i] = (i*fact[i-1])%MOD;
  }

  int n;
  std::cin >> n;
  n++;

  int ans = 0;
  int last = -1;
  int lval = 0;
  for(int i = 0; i <= n; i++) {
    int x;
    if(i == n) {
      x = 0;
    }
    else
      std::cin >> x;
    //int steps = i+x;
    int times;
    if(last == x) {
      times = choose(i+x-1, i);
    }
    else
      times = choose(i+x, i);
    if(last-1 > x) {
      for(int j = last-1; j > x; j--) {
        times = (times + choose(i+j-1, i-1))%MOD;
        //std::cout << i << std::endl;
        //std::cout << j << " " << choose(i+j-1, i-1) << std::endl;
      }
    }
    //std::cout << times << std::endl;
    last = x;
    ans = (ans + times)%MOD;
  }

  ans = (ans-1+MOD)%MOD;
  std::cout << ans << std::endl;

  return 0;
}