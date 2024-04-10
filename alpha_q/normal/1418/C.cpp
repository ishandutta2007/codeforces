#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;

int t, n, a[N], dp[N][2];

int main() {
//  freopen("in.txt", "r", stdin);
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    dp[n + 1][0] = dp[n + 1][1] = 0;
    for (int i = n; i >= 1; --i) {
      if (a[i]) {
        dp[i][0] = 1 + dp[i + 1][1];
        if (i < n) dp[i][0] = min(dp[i][0], 1 + a[i + 1] + dp[i + 2][1]);
      } else {
        dp[i][0] = dp[i + 1][1];
        if (i < n) dp[i][0] = min(dp[i][0], a[i + 1] + dp[i + 2][1]);
      }
      dp[i][1] = dp[i + 1][0];
      if (i < n) dp[i][1] = min(dp[i][1], dp[i + 2][0]);
    }
    printf("%d\n", dp[1][0]);
  }
  return 0;
}