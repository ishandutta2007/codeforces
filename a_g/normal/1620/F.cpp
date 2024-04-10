#include <bits/stdc++.h>
using namespace std;

// source: editorial
//
// dp[i][0]: there exists a valid sequence with p[i] at the end. Let y be the
// value stored here.
// If y > p[i], this is the minimum possible value of the maximum element
// (decreasing subsequence of length 1).
// If y < p[i], this is the minimum possible value of the end of the longest
// decreasing subsequence of length 2.
//
// dp[i][1]: same as above but with -p[i] instead of p[i]

const int maxn = 1e6+2;
const int INF = 1e9;

int dp[maxn][2];
int pre[maxn][2];
int p[maxn];
int a[maxn];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = -INF;
  dp[0][1] = -INF;
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < 2; j++) {
      if (dp[i][j] != INF) {
        int x = j ? -p[i] : p[i];
        int y = dp[i][j];
        if (x < y) swap(x, y);
        // at this point, x and y are the ends of the decreasing subsequences of
        // lengths 1 and 2, resp.
        for (int k = 0; k < 2; k++) {
          int z = k ? -p[i+1] : p[i+1];
          if (z > x) {
            if (dp[i+1][k] > y) {
              dp[i+1][k] = y;
              pre[i+1][k] = j;
            }
          }
          else if (z > y) {
            if (dp[i+1][k] > x) {
              dp[i+1][k] = x;
              pre[i+1][k] = j;
            }
          }
        }
      }
    }
  }

  for (int j = 0; j < 2; j++) {
    if (dp[n-1][j] != INF) {
      for (int i = n-1; i >= 0; i--) {
        a[i] = j ? -p[i] : p[i];
        j = pre[i][j];
      }
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
      }
      cout << '\n';
      return;
    }
  }
  cout << "NO\n";
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}