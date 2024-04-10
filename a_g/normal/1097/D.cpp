#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 200;
int inv[N];

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

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  inv[1] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
  }

  long long n;
  int k;
  cin >> n >> k;
  vector<pair<long long, int>> pfact;
  for (int p = 2; 1LL*p*p <= n; p++) {
    int e = 0;
    while (n%p == 0) {
      e++;
      n /= p;
    }
    if (e) pfact.emplace_back(p, e);
  }
  if (n) pfact.emplace_back(n, 1);

  int ans = 1;
  for (auto& [p, e]: pfact) {
    vector<int> dp(e+1);
    dp[e] = 1;
    for (int i = 0; i < k; i++) {
      vector<int> ndp(e+1);
      for (int j = 0; j <= e; j++) {
        for (int l = 0; l <= j; l++) {
          ndp[l] = (ndp[l]+1LL*dp[j]*inv[j+1])%MOD;
        }
      }
      swap(dp, ndp);
    }
    int t = 0;
    int pw = 1;
    for (int i = 0; i <= e; i++) {
      t = (t+1LL*pw*dp[i])%MOD;
      pw = 1LL*pw*p % MOD;
    }
    ans = (1LL*ans*t)%MOD;
  }
  cout << ans << '\n';
}