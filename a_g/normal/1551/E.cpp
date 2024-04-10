#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] = i+1-a[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int d = (j == a[i] ? 1 : 0);
        if (j == 0) {
          dp[i+1][j] = dp[i][j]+d;
        }
        else {
          dp[i+1][j] = max(dp[i][j]+d, dp[i][j-1]);
        }
      }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
      if (dp[n][i] >= k) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
  }
}