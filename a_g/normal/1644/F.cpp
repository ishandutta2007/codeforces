#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 2e5+7;
int fact[N];
int invfact[N];
int dp[N];

int expmod(long long a, long long b, int m) {
  int ans = 1;
  a %= m;
  while (b) {
    if (b&1) ans = 1LL*ans*a % m;
    b >>= 1;
    a = 1LL*a*a % m;
  }
  return ans;
}

int calc(int n, int m) {
  /* sum from k = 0 to m of S(n, k) */
  m = min(m, n);
  int ans = 0;
  int v = 0;
  for (int i = 0; i <= m; i++) {
    v += 1LL*expmod(i, n, MOD)*invfact[i] % MOD;
    v %= MOD;
    ans += ((m-i)&1 ? -1LL : 1LL) * invfact[m-i] * v % MOD;
    ans %= MOD;
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL*i*fact[i-1] % MOD;
  }
  invfact[N-1] = expmod(fact[N-1], MOD-2, MOD);
  for (int i = N-1; i >= 1; i--) {
    invfact[i-1] = 1LL*i*invfact[i] % MOD;
  }

  int n, k;
  cin >> n >> k;
  for (int i = n-1; i >= 1; i--) {
    dp[i] = calc((n-1)/i+1, k)-1;
    for (int j = 2*i; j <= n-1; j+=i) {
      dp[i] = (dp[i]-dp[j])%MOD;
    }
  }
  cout << (dp[1]+(n==1||k==1)+MOD)%MOD << '\n';
}