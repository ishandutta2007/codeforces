#include <iostream>
#include <algorithm>

#define int long long

const int MOD = 1000000007;
const int MAXN = 100005;

int expo(int x, int p) {
  int ret = 1;
  while(p > 0) {
    if(p & 1)
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

signed main() {
  fact[0] = 1;
  for(int i = 1; i < MAXN; i++)
    fact[i] = (i*fact[i-1])%MOD;

  int n;
  std::cin >> n;

  int seq[n];
  int sum = 0;
  for(int i = 0; i < n; i++) {
    std::cin >> seq[i];
    sum += seq[i];
  }

  if(sum%n != 0) {
    std::cout << 0 << std::endl;
    return 0;
  }

  int ans = 1;
  int a = 0, b = 0;
  for(int i = 0; i < n; i++) {
    if(seq[i]*n < sum)
      a++;
    else if(seq[i]*n > sum)
      b++;
  }

  ans *= fact[n];
  if(a > 1 && b > 1) {
    ans *= inv(fact[a+b]);
    ans %= MOD;
    ans *= fact[a]*2;
    ans %= MOD;
    ans *= fact[b];
    ans %= MOD;
  }

  std::sort(seq, seq+n);
  int last = 0;
  for(int i = 1; i < n; i++) {
    if(seq[i] != seq[last]) {
      ans *= inv(fact[i-last]);
      ans %= MOD;
      last = i;
    }
  }

  ans *= inv(fact[n-last]);
  ans %= MOD;

  std::cout << ans << std::endl;

  return 0;
}