#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 5005;
int dp[N][N], dps[N][N];

void add(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  vector<vector<int>> lcp(n, vector<int>(n));
  for (int i = n-1; i >= 0; i--) {
    for (int j = n-1; j >= 0; j--) {
      if (s[i] != s[j]) continue;
      if (i == n-1 || j == n-1) lcp[i][j] = 1;
      else lcp[i][j] = lcp[i+1][j+1]+1;
    }
  }

  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    dps[i][0] = dp[i][0];
    for (int j = 1; j < N; j++) {
      dps[i][j] = dps[i][j-1];
      add(dps[i][j], dp[i][j]);
    }
    if (s[i] == '0') continue;
    for (int len = 1; len <= n-i; len++) {
      add(dp[i+len][len], dps[i][len-1]);
      if (i && dp[i][len]) {
        assert(len <= i);
        int k = lcp[i][i-len];
        if (k < len && s[i+k] > s[i-len+k]) {
          add(dp[i+len][len], dp[i][len]);
        }
      }
    }
  }
  int ans = 0;
  for (int j = 0; j < N; j++) {
    add(ans, dp[n][j]);
  }
  cout << ans << '\n';
}