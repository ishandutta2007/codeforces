#include <bits/stdc++.h>
using namespace std;

const int N = 5e6+5;
bool vis[N];
int freq[N], dp[N];
// testing an optimization from https://codeforces.com/contest/1699/submission/162819595

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int mn = 1e9;
    int mx = -1;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      vis[x] = 1;
      mn = min(mn, x);
      mx = max(mx, x);
    }
    iota(dp, dp+m+1, 0);
    for (int i = 1; i <= m; i++) {
      if (vis[i]) freq[i] = 1;
    }
    int ans = mx-mn;
    int r = mx;
    for (int l = mx-1; l >= 1; l--) {
      if (1LL*l*l <= m) {
        for (int j = l*l; j <= m; j += l) {
          if (dp[j/l] < dp[j]) {
            if (vis[j]) {
              freq[dp[j]]--;
            }
            dp[j] = dp[j/l];
            if (vis[j]) {
              freq[dp[j]]++;
            }
          }
        }
      }
      while (!freq[r]) r--;
      if (l <= mn) ans = min(ans, r-l);
    }

    fill(vis, vis+m+1, 0);
    fill(freq, freq+m+1, 0);
    cout << ans << '\n';
  }
}