#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 505;
int dp[N][N], dp2[N][N];
int pos[N], c[N];

// dp[l][r] = number of ways to do the interval [l, r], assuming the intervals
// [a, b] for the visible colors in [l, r] do not cross [l, r]
//
// dp2[l][r] = sum from k = l-1 to r of dp[l][k]*dp[k+1][r]

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
    pos[c[i]] = i;
  }
  for (int i = 0; i < N; i++) {
    fill(dp[i], dp[i]+N, 1);
    fill(dp2[i], dp2[i]+N, 1);
  }

  for (int d = 0; d < m; d++) {
    for (int l = 1; l+d <= m; l++) {
      int r = l+d;
      dp[l][r] = 0;

      auto it = min_element(c+l, c+r+1);
      int z = *it;
      int k = it-c;
      dp[l][r] = (dp[l][r]+1LL*dp2[l][k-1]*dp2[k+1][r])%MOD;

      dp2[l][r] = 0;
      for (int k = l-1; k <= r; k++) {
        dp2[l][r] = (dp2[l][r]+1LL*dp[l][k]*dp[k+1][r]) % MOD;
      }
    }
  }
  cout << dp[1][m] << '\n';
}