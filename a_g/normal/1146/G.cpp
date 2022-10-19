#include <bits/stdc++.h>
using namespace std;

const int N = 52;
int dp[N][N][N];

struct restriction {
  int l, r, x, c;
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, h, m;
  cin >> n >> h >> m;
  vector<restriction> zr(m);
  int cost = 0;
  for (restriction& z: zr) {
    cin >> z.l >> z.r >> z.x >> z.c;
    cost += z.c;
  }
  // dp[l][r][h] = maximum profit if all buildings in [l, r] are height at most
  // h, which includes all satisfied zoning restrictions contained in the range
  for (int d = 0; d < n; d++) {
    for (int l = 1; l+d <= n; l++) {
      int r = l+d;
      for (int q = 0; q <= h; q++) {
        // max height < q
        if (q) dp[l][r][q] = dp[l][r][q-1];
        // max height = q, iterate over spot where this height is achieved
        for (int p = l; p <= r; p++) {
          int val = dp[l][p-1][q]+dp[p+1][r][q]+q*q;
          for (restriction& z: zr) {
            if (z.l >= l && z.l <= p && z.r >= p && z.r <= r && z.x >= q) {
              val += z.c;
            }
          }
          dp[l][r][q] = max(dp[l][r][q], val);
        }
      }
    }
  }
  cout << dp[1][n][h]-cost << '\n';
}