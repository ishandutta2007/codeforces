#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<ll>> dp(n+2, vector<ll>(2));
    dp[0][0] = 1;
    for (int x: a) {
      if (x) {
        dp[x-1][1] += (dp[x-1][0] + dp[x-1][1]);
        dp[x-1][1] %= MOD;
      }
      dp[x+1][0] += (dp[x][0] + dp[x+1][0]);
      dp[x+1][0] %= MOD;
      dp[x+1][1] += (dp[x+1][1]);
      dp[x+1][1] %= MOD;
    }
    ll ans = -1;
    for (int j = 0; j < 2; j++) {
      for (int i = 0; i <= n; i++) {
        ans += dp[i][j];
      }
    }
    cout << ans%MOD << '\n';
  }
}