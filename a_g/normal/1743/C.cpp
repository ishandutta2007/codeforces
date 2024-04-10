#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    vector<vector<int>> dp(n+1, vector<int>(2));
    for (int i = 0; i < n; i++) {
      dp[i+1][0] = max(dp[i][0], dp[i][1]) + (s[i] == '1' ? a[i] : 0);
      if (s[i] == '1' && i > 0) {
        if (s[i-1] == '1') {
          dp[i+1][1] = dp[i][1]+a[i-1];
        }
        else {
          dp[i+1][1] = dp[i][0]+a[i-1];
        }
      }
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';
  }
}