#include <iostream>

#define int long long

const int MOD = 998244353;
const int MAXN = 100005;

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

int fact[MAXN];

int choose(int n, int r) {
  if(n < r)
    return 0;
  if(n < 0)
    return 0;
  if(r < 0)
    return 0;
  int ans = fact[n];
  ans *= inv(fact[r]);
  ans %= MOD;
  ans *= inv(fact[n-r]);
  ans %= MOD;
  return ans;
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
    int count = 0;
    std::string s;
    std::cin >> s;

    int cur = 0;
    int el = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == '1')
        cur++;
      else {
        count += cur/2;
        el += cur%2;
        cur = 0;
      }
    }

    count += cur/2;
    el += cur%2;

    std::cout << choose(n-1-el-(count-1), count) << std::endl;
  }

  return 0;
}