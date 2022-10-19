#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int p[N], dp[N], h[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
      cin >> p[i];
    }
    int low = 0;
    int high = n-1;
    while (high-low > 1) {
      fill(dp+1, dp+n+1, 0);
      fill(h+1, h+n+1, 1);
      int mid = (low+high)/2;
      for (int v = n; v >= 2; v--) {
        dp[p[v]] += dp[v];
        if (h[v] >= mid && p[v] != 1) {
          dp[p[v]]++;
        }
        else {
          h[p[v]] = max(h[p[v]], h[v]+1);
        }
      }
      if (dp[1] <= k) high = mid;
      else low = mid;
    }
    cout << high << '\n';
  }
}