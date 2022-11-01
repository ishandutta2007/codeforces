/*















*/

#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int ans[26][1501];

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  cin >> s;
  for(int c = 0; c < 26; c++) {
    vector<int> t(n);
    for(int i = 0; i < n; i++) t[i] = (s[i] - 'a' == c);
    // TODO
    vector<vector<int>> dp(n, vector<int>(n + 1));
    dp[0][0] = t[0];
    for(int i = 1; i <= n; i++) dp[0][i] = 1;
    for(int i = 1; i < n; i++) dp[i][0] = t[i] * (dp[i - 1][0] + 1);
    for(int i = 1; i < n; i++)
      for(int j = 1; j <= n; j++)
        dp[i][j] = dp[i - 1][j - !t[i]] + 1;
    for(int j = 1; j <= n; j++) {
      ans[c][j] = 0;
      for(int i = 0; i < n; i++)
        ans[c][j] = max(ans[c][j], dp[i][j]);
    }
  }
  int q;
  cin >> q;
  while(q--) {
    int m;
    char c;
    cin >> m >> c;
    cout << ans[c - 'a'][m] << '\n';
  }
}