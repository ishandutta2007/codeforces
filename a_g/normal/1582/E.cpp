#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[n-1-i];
    }
    vector<ll> prefsums(n+1, 0);
    for (int i = 0; i < n; i++) {
      prefsums[i+1] = prefsums[i] + a[i];
    }
    const int maxk = 500;
    vector<vector<ll>> dp(n+1, vector<ll>(maxk, 0));
    // sums[i+1][k] = a[i] + a[i-1] + ... + a[i-k]
    // dp[i+1][k] = largest possible sum of (k+1)th segment if restricted to a[0] to a[i]
    for (int i = 0; i < n; i++) {
      dp[i+1][0] = max(a[i], dp[i][0]);
      for (int k = 1; k < maxk; k++) {
        if (i >= k) {
          ll sum = prefsums[i+1]-prefsums[i-k];
          dp[i+1][k] = dp[i][k];
          if (i>= k && sum < dp[i-k][k-1]) {
            dp[i+1][k] = max(dp[i+1][k], sum);
          }
        }
      }
    }
    int ans = 0;
    for (int k = 0; k < maxk; k++) {
      if (dp[n][k] > 0) ans = k+1;
      else break;
    }
    cout << ans << endl;
  }
}