#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pii>> floors(n);
  vector<vector<pii>> intervals(m+1);
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    floors[i].resize(val);
    for (int j = 0; j < val; j++) {
      int l, r;
      cin >> l >> r;
      floors[i][j] = {l, r};
      for (int k = l; k <= r; k++) {
        intervals[k].push_back({l, r});
      }
    }
  }
  vector<vector<int>> dp(m+2, vector<int>(m+1));
  for (int d = 0; d < m; d++) {
    for (int l = 1; l <= m-d; l++) {
      int r = l+d;
      for (int k = l; k <= r; k++) {
        int count = 0;
        for (pii p: intervals[k]) {
          if (l <= p.first && p.second <= r) count++;
        }
        dp[l][r] = max(dp[l][r], dp[l][k-1] + dp[k+1][r] + count*count);
      }
    }
  }
  cout << dp[1][m] << endl;
}