#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(n));
  int m = n*n;
  vector<int> freq(m), min_x(m, n), max_x(m, -1), min_y(m, n), max_y(m, -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int c;
      cin >> c;
      c--;
      a[i][j] = c;
      freq[c]++;
      min_x[c] = min(min_x[c], i);
      max_x[c] = max(max_x[c], i);
      min_y[c] = min(min_y[c], j);
      max_y[c] = max(max_y[c], j);
    }
  }

  int cur = 0;
  for (int x: freq) cur += !!x;
  if (cur <= k) {
    cout << k-cur << '\n';
    return 0;
  }

  for (int s = 1; s <= n; s++) {
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    for (int c = 0; c < m; c++) {
      if (!freq[c]) continue;
      if (max_x[c]-min_x[c] < s && max_y[c]-min_y[c] < s) {
        int u = max(0, max_x[c]-s+1);
        int v = max(0, max_y[c]-s+1);
        dp[u][v]++;
        dp[min_x[c]+1][v]--;
        dp[u][min_y[c]+1]--;
        dp[min_x[c]+1][min_y[c]+1]++;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] += dp[i][j-1];
      }
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] += dp[i-1][j];
      }
    }
    for (int i = 0; i+s <= n; i++) {
      for (int j = 0; j+s <= n; j++) {
        if (dp[i][j] == cur-k || dp[i][j] == cur-k+1) {
          cout << "1\n";
          return 0;
        }
      }
    }
  }

  cout << "2\n";
}