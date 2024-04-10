#include <iostream>

#define int long long

const int MOD = 1000000007;
const int MAXN = 200005;

int l, r, n;

int inter(int a, int b, int x, int y) {
  int q = std::min(b, y);
  int p = std::max(a, x);
  return std::max(0ll, q-p+1);
}

int count(int x) {
  return inter(1, n, x+l, x+r);
}

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

int fact[MAXN];

int choose(int n, int r) {
  if(n < 0)
    return 0;
  if(r < 0)
    return 0;
  if(n < r)
    return 0;
  int ans = fact[n];
  ans = (ans*inv(fact[r]))%MOD;
  ans = (ans*inv(fact[n-r]))%MOD;
  return ans;
}

int get(int a, int b) {
  if(a+b < n)
    return 0;

  int ans = 0;
  int ex = a+b-n;
  a -= ex;
  b -= ex;

  int x = n/2, y = n-n/2;
  if(x-a >= 0 && y-b >= 0) {
    ans += choose(ex, x-a);
    ans %= MOD;
  }

  if(n%2) {
    x ^= y ^= x ^= y;
    if(x-a >= 0 && y-b >= 0) {
      ans += choose(ex, x-a);
      ans %= MOD;
    }
  }

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
    std::cin >> n >> l >> r;

    int a = r-n;
    int b = 1-l;

    int done = std::min(a, b);
    int ans = 0;

    ans += done*get(n, n);
    ans %= MOD;

    for(int i = 1; i <= n; i++) {
      int x = done+i;
      ans += get(count(x), count(-x));
      ans %= MOD;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}