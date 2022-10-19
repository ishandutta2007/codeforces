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
    vector<vector<int>> lcp(n, vector<int>(n));
    vector<vector<int>> suff_less(n, vector<int>(n));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (s[n-i] == s[n-j]) {
          if (i == 1 && j > 1) {
            suff_less[i-1][j-1] = 1;
            lcp[i-1][j-1] = 1;
          }
          else if (j == 1) {
            suff_less[i-1][j-1] = 0;
            lcp[i-1][j-1] = 1;
          }
          else {
            lcp[i-1][j-1] = lcp[i-2][j-2] + 1;
            suff_less[i-1][j-1] = suff_less[i-2][j-2];
          }
        }
        else {
          suff_less[i-1][j-1] = (s[n-i] < s[n-j]);
        }
      }
    }

    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
      dp[i] = n-i;
      for (int j = 0; j < i; j++) {
        if (suff_less[n-1-j][n-1-i]) {
          dp[i] = max(dp[i], dp[j] + n-i-lcp[n-1-j][n-1-i]);
        }
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
}