#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int& x: c) cin >> x, x--;
    vector<vector<int>> dp(n+1, vector<int>(100));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 100; j++) {
        if (c[i] == j) {
          dp[i+1][j] = dp[i][j];
        }
        else {
          dp[i+1][j] = dp[max(0, i-k+1)][j]+1;
        }
      }
    }
    cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';
  }
}