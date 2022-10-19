#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int x;
    cin >> x;
    for (int i = 0; i < n; i++) a[i] -= x;

    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[0][2] = 0;
    for (int i = 1; i < n; i++) {
      dp[i][0] = *max_element(dp[i-1].begin(), dp[i-1].end());
      dp[i][1] = dp[i-1][0]+1;
      if (a[i] + a[i-1] >= 0) {
        dp[i][2] = dp[i-1][1]+1;
        if (i > 1 && a[i]+a[i-1]+a[i-2] >= 0) {
          dp[i][2] = max(dp[i][2], dp[i-1][2]+1);
        }
      }
    }
    cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << '\n';
  }
}