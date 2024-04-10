#include <iostream>

#define int long long

const int MOD = 998244353;
const int MAXN = 1000006;
const int inv3 = 332748118;

int dp[MAXN];
int pref[MAXN];

int c2(int x) {
  return ((x*(x+1))/2)%MOD;
}

int c3(int k) {
  int first = (k*(k+1))/2;
  first %= MOD;
  first *= (k+2);
  first %= MOD;
  first *= inv3;
  first %= MOD;
  return first;
}

signed main() {
  int n;
  std::cin >> n;

  dp[0] = pref[0] = 1;
  dp[1] = 2;
  pref[1] = 3;

  if(n == 1) {
    std::cout << 5 << std::endl;
    return 0;
  }

  for(int i = 2; i <= n; i++) {
    int a = dp[i-1], b = pref[i-2];
    int one = a;
    int two = c2(a);
    two += (a*b)%MOD;
    two %= MOD;
    int three = 0;
    if(i == n) {
      three = c3(a);
      three += (b*c2(a))%MOD;
      three %= MOD;
      three += (c2(b)*a)%MOD;
      three %= MOD;
    }
    dp[i] = (one + two + three)%MOD;
    pref[i] = (pref[i-1]+dp[i])%MOD;
  }

  int ans = 2*dp[n]-1+MOD;

  int cur = 1;
  for(int i = 2; i < n; i++) {
    ans += (dp[i-1]-1+MOD)*(dp[n-i]-dp[n-i-1]+MOD);
    ans %= MOD;
  }

  std::cout << (ans)%MOD << std::endl;

  return 0;
}