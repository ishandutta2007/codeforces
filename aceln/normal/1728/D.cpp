#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> dp(n + 2, vector<int>(n + 2)); // 1: A, 0 : draw, -1:B
    for (int i = 0; i + 1 < n; i++) {
      if (s[i] != s[i + 1])
        dp[i][i + 1] = 1;
      else
        dp[i][i + 1] = 0;
    }
    for (int len = 4; len <= n; len += 2) {
      for (int l = 0; l + len - 1 < n; l++) {
        int r = l + len - 1;
        // a
        if ((dp[l + 1][r - 1] == 1 || dp[l + 1][r - 1] == 0 && s[l] < s[r]) &&
            (dp[l + 2][r] == 1 || dp[l + 2][r] == 0 && s[l] < s[l + 1]))
          dp[l][r] = 1;
        else if ((dp[l + 1][r - 1] == 1 ||
                  dp[l + 1][r - 1] == 0 && s[l] > s[r]) &&
                 (dp[l][r - 2] == 1 || dp[l][r - 2] == 0 && s[r] < s[r - 1]))
          dp[l][r] = 1;

        // b
        else if (((dp[l + 1][r - 1] == -1 ||
                   dp[l + 1][r - 1] == 0 && s[l] > s[r]) ||
                  (dp[l + 2][r] == -1 ||
                   dp[l + 2][r] == 0 && s[l] > s[l + 1])) &&
                 ((dp[l + 1][r - 1] == -1 ||
                   dp[l + 1][r - 1] == 0 && s[l] < s[r]) ||
                  (dp[l][r - 2] == -1 || dp[l][r - 2] == 0 && s[r] > s[r - 1])))
          dp[l][r] = -1;

        else
          dp[l][r] = 0;
      }
    }
    if (dp[0][n - 1] == 1)
      cout << "Alice\n";
    else if (dp[0][n - 1] == 0)
      cout << "Draw\n";
    else
      cout << "Bob\n";
  }
}