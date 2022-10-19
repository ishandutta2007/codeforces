#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1000;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    const int cols = 2*N;
    int dp[n+1][cols];
    for (int i = 0; i < cols; i++) {
      dp[0][i] = i;
    }
    for (int i = 1; i < n+1; i++) {
      for (int j = 0; j < cols; j++) {
        dp[i][j] = cols+1;
      }
    }

    for (int i = 0; i < n; i++) {
      int val;
      cin >> val;
      for (int j = 0; j < cols; j++) {
        int v = dp[i][j];
        if (val <= j) dp[i+1][j-val] = min(dp[i+1][j-val], v);
        if (j+val < cols) dp[i+1][j+val] = min(dp[i+1][j+val], max(j+val, v));
      }
    }

    /*
    for (int i = 0; i < n+1; i++) {
      for (int j = 0; j < cols; j++) {
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }
    */
    int ans = cols+1;
    for (int i = 0; i < cols; i++) ans = min(ans, dp[n][i]);
    cout << ans << endl;
  }
}