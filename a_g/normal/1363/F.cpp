#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<vector<int>> pref_s(n+1, vector<int>(26));
    vector<vector<int>> pref_t(n+1, vector<int>(26));
    for (int i = 0; i < n; i++) {
      pref_s[i+1] = pref_s[i];
      pref_t[i+1] = pref_t[i];
      pref_s[i+1][s[i]-'a']++;
      pref_t[i+1][t[i]-'a']++;
    }
    bool ok = 1;
    for (int i = 0; i < 26; i++) {
      if (pref_s[n][i] != pref_t[n][i]) ok = 0;
    }
    if (!ok) {
      cout << "-1\n";
      continue;
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    dp[0] = vector<int>(n+1, 0);
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        int& x = dp[i][j];
        x = dp[i-1][j]+1;
        if (s[i-1] == t[j-1]) {
          x = min(x, dp[i-1][j-1]);
        }
        if (pref_s[i][t[j-1]-'a'] < pref_t[j][t[j-1]-'a'] && i < j) {
          x = min(x, dp[i][j-1]);
        }
      }
    }
    cout << dp[n][n] << '\n';
  }
}