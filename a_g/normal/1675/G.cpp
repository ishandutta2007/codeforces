#include <bits/stdc++.h>
using namespace std;

// source: jiangly
const int N = 255;
const int INF = 1e9;
int dp[N][N];
// dp[i][j] = minimum number of operations so that s_i = j

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  for (int i = 1; i < n; i++) {
    a[i] += a[i-1];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;
  for (int k = m; k >= 0; k--) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j+k <= m; j++) {
        dp[i+1][j+k] = min(dp[i+1][j+k], dp[i][j]+abs(j+k-a[i]));
      }
    }
  }
  cout << dp[n][m] << '\n';
}