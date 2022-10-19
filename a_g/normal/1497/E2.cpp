#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  const int maxn = 1e7+2;
  vector<int> sqf(maxn, 0);
  for (int i = 1; i < maxn; i++) {
    if (!sqf[i]) {
      for (int j = 1; i*j*j < maxn; j++) {
        sqf[i*j*j]=i;
      }
    }
  }

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] = sqf[a[i]];
    }
    vector<vector<int>> left(n, vector<int>(k+1));
    for (int j = 0; j <= k; j++) {
      unordered_map<int, int> counts;
      int l = 0;
      int r = 0;
      int changes = 0;
      counts[a[0]]++;
      while (r < n) {
        while (changes <= j) {
          left[r][j] = l;
          r++;
          if (r == n) break;
          if (counts[a[r]]) changes++;
          counts[a[r]]++;
        }
        if (r == n) break;
        while (changes > j) {
          counts[a[l]]--;
          if (counts[a[l]]) changes--;
          l++;
        }
      }
    }
    vector<vector<int>> dp(n, vector<int>(k+1, 1e9));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= k; j++) {
        for (int m = 0; m <= j; m++) {
          int l = left[i][m];
          if (l == 0) dp[i][j] = 1;
          else dp[i][j] = min(dp[i][j], dp[l-1][j-m]+1);
        }
      }
    }
    cout << dp[n-1][k] << '\n';
  }
}