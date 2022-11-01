#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int t, n, f[N], dp[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    memset(f, 0, sizeof f);
    for (int i = 1, x; i <= n; ++i) {
      scanf("%d", &x); ++f[x];
    }
    dp[N - 1] = 0;
    for (int i = N - 2; i >= 1; --i) {
      dp[i] = f[i];
      if (f[i]) {
        for (int j = i << 1; j < N; j += i) {
          dp[i] = max(dp[i], f[i] + dp[j]);
        }
      }
    }
    int ans = n - *max_element(dp, dp + N);
    printf("%d\n", ans);
  }
  return 0;
}