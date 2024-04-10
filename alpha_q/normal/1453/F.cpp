#include <bits/stdc++.h>

using namespace std;

const int N = 3005;

int t, n, a[N], dp[N][N], f[N], r[N], cost[N], tr[N << 1];

int query (int l, int r) {
  int ret = 69696969; --l;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ret = min(ret, tr[l++]);
    if (r & 1) ret = min(ret, tr[--r]);
  }
  return ret;
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      r[i] = i + a[i];
    }
    for (int i = 1; i < n; ++i) dp[n][i] = 0;
    for (int i = n - 1; i >= 1; --i) {
      int tot = 0;
      for (int j = 0; j <= n; ++j) {
        f[j] = 0, cost[j] = 69696969;
      }
      for (int j = i + 1; j <= r[i]; ++j) {
        cost[j] = dp[j][i] + tot;
        tot -= f[j], ++f[r[j]];
        if (r[j] > j) ++tot;
      }
      for (int j = 0; j < n; ++j) tr[n + j] = cost[j + 1];
      for (int j = n - 1; j; --j) tr[j] = min(tr[j << 1], tr[j << 1 | 1]);
      for (int j = 1; j < i; ++j) {
        if (r[j] < i) dp[i][j] = 69696969;
        else dp[i][j] = query(max(i, r[j]) + 1, r[i]);
        // cerr << i << " " << j << " --> " << dp[i][j] << '\n';
      }
    }
    int ans = 69696969, tot = 0;
    for (int i = 0; i <= n; ++i) f[i] = 0;
    for (int i = 2; i <= r[1]; ++i) {
      ans = min(ans, tot + dp[i][1]);
      tot -= f[i]; ++f[r[i]]; 
      if (r[i] > i) ++tot;
    }
    printf("%d\n", ans);
  }
  return 0;
}