#include <iostream>

#define int long long

const int MAXN = 1000006;
const int MOD = 1000000007;
 
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
 
int choose(int a, int b) {
  if(b > a)
    return 0;
  int ans = fact[a]*inv(fact[b]);
  ans %= MOD;
  ans *= inv(fact[a-b]);
  ans %= MOD;
  return ans;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  fact[0] = 1;
  for(int i = 1; i < MAXN; i++)
    fact[i] = (fact[i-1]*i)%MOD;

  int n;
  std::cin >> n;

  if(n == 2) {
    std::cout << 4 << std::endl;
    return 0;
  }

  int ans = 2*fact[n];
  ans %= MOD;
  if(n%2)
    ans = 0;

  for(int i = (n%2 ? 1 : 2); 2*i <= n; i+=2) {
    int opt1 = choose(n-3-(i-2), i-1)*2;
    opt1 %= MOD;
    int opt2 = choose(n-1-(i-1), i)*2;
    opt2 %= MOD;
    int poss = (opt1 + opt2)%MOD;
    poss *= fact[n-i];
    poss %= MOD;
    ans = (ans + poss)%MOD;
  }

  std::cout << ans << std::endl;

  return 0;
}