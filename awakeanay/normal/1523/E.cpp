#include <iostream>

#define int long long

const int MAXN = 200005;
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

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  fact[0] = 1;
  for(int i = 1; i < MAXN; i++)
    fact[i] = (i*fact[i-1])%MOD;

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    int finish[n+1], only[n+1];
    finish[1] = 0;
    finish[0] = 0;
    only[0] = only[1] = 0;
    int tot = 0;
    int num = 0;

    for(int i = 2; i <= n; i++) {
      int a = n-1-(i-1)*k;
      int b = i;
      int comp;
      if(a < 0)
        comp = 0;
      else {
        comp = fact[a+b]*inv(fact[a]);
        comp %= MOD;
        comp *= inv(fact[b]);
        comp %= MOD;
        comp *= fact[i];
        comp %= MOD;
      }

      finish[i] = (fact[n]*inv(fact[n-i]))%MOD + MOD - comp;
      finish[i] %= MOD;

      only[i] = MOD + finish[i] - (finish[i-1]*(n-i+1))%MOD;
      only[i] %= MOD;
      int cur = only[i]*i;
      cur %= MOD;
      cur *= fact[n-i];
      cur %= MOD;
      num += cur;
      num %= MOD;
      tot += only[i];
      tot %= MOD;
    }

    std::cout << (num*inv(fact[n]))%MOD << std::endl;
  }

  return 0;
}