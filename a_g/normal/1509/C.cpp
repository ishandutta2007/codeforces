#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  sort(a.begin(), a.end());
  vector<vector<long long>> dp(n, vector<long long>(n, 1e18));
  for (int i = 0; i < n; i++) dp[i][i] = 0;
  for (int d = 0; d < n; d++) {
    for (int l = 0; l+d < n; l++) {
      int r = l+d;
      if (l) dp[l-1][r] = min(dp[l-1][r], dp[l][r]+a[r]-a[l-1]);
      if (r+1 < n) dp[l][r+1] = min(dp[l][r+1], dp[l][r]+a[r+1]-a[l]);
    }
  }
  cout << dp[0][n-1] << '\n';
}