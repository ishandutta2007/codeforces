#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 998244353;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<bool> add(n);
  vector<int> vals(n);
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    add[i] = c == '+';
    if (add[i]) cin >> vals[i];
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (add[i]) {
      ll v = vals[i];
      vector<vector<ll>> dp(n+1, vector<ll>(n, 0));
      dp[0][0] = 1;
      for (int j = 0; j < i; j++) {
        if (add[j]) {
          if (vals[j] > v) {
            for (int k = 0; k < n; k++) {
              dp[j+1][k] = 2*dp[j][k] % MOD;
            }
          }
          else {
            for (int k = 0; k < n; k++) {
              dp[j+1][k] = (dp[j+1][k] + dp[j][k]) % MOD;
              dp[j+1][min(k+1, n-1)] = (dp[j+1][min(k+1, n-1)] + dp[j][k]) % MOD;
            }
          }
        }
        else {
          for (int k = 0; k < n; k++) {
            dp[j+1][k] = (dp[j+1][k] + dp[j][k]) % MOD;
            dp[j+1][max(k-1, 0)] = (dp[j+1][max(k-1, 0)] + dp[j][k]) % MOD;
          }
        }
      }

      for (int k = 0; k < n; k++) dp[i+1][k] = dp[i][k];

      for (int j = i+1; j < n; j++) {
        if (add[j]) {
          if (vals[j] >= v) {
            for (int k = 0; k < n; k++) {
              dp[j+1][k] = 2*dp[j][k] % MOD;
            }
          }
          else {
            for (int k = 0; k < n; k++) {
              dp[j+1][k] = (dp[j+1][k] + dp[j][k]) % MOD;
              dp[j+1][min(k+1, n-1)] = (dp[j+1][min(k+1, n-1)] + dp[j][k]) % MOD;
            }
          }
        }
        else {
          for (int k = 0; k < n; k++) {
            dp[j+1][k] = (dp[j+1][k] + dp[j][k]) % MOD;
            if (k > 0) dp[j+1][k-1] = (dp[j+1][k-1] + dp[j][k]) % MOD;
          }
        }
      }

      ll count = 0;
      for (int k = 0; k < n; k++) count = (count + dp[n][k]) % MOD;
      ans = (ans + count*v) % MOD;
    }
  }
  cout << ans << endl;
}