#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;
const int MOD = 998244353;

ll bigMod (ll a, ll e) {
  e %= (MOD - 1);
  if (e < 0) e += MOD - 1;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % MOD;
    a = a * a % MOD, e >>= 1;
  }
  return ret;
}

int m; ll freq[N], dp[N]; 

int main() {
  cin >> m;
  for (int i = 1, x; i <= m; ++i) {
    scanf("%d", &x); scanf("%lld", freq + x);
  }
  for (int i = 1; i < N; ++i) {
    ll sum = 0, sq = 0, sz = 0;
    for (int j = i; j < N; j += i) {
      sz += freq[j];
      sum += j * freq[j] % MOD;
      sq += ((ll) j * j % MOD) * freq[j] % MOD;
    }
    sum %= MOD, sq %= MOD;
    if (sz < 2) continue;
    ll two = bigMod(2, sz - 3), n = sz % MOD;
    ll cur = ((n - 1) * 2 * two % MOD) * sq % MOD;
    cur = (cur + (n * two % MOD) * ((sum * sum - sq) % MOD)) % MOD;
    cur %= MOD, cur += MOD, cur %= MOD, dp[i] = cur;
  }
  for (int i = N - 1; i; --i) {
    for (int j = i << 1; j < N; j += i) {
      dp[i] -= dp[j];
      if (dp[i] < 0) dp[i] += MOD;
    }
  }
  cout << dp[1] << '\n';
  return 0;
}