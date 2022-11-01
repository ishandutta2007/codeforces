#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;

int t, n, m; ll a[N], b[N], dp[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    ll tot = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a + i);
      if (i & 1) tot += a[i];
    }
    m = 0;
    for (int i = 1; i + 1 <= n; i += 2) {
      b[++m] = a[i + 1] - a[i];
    }
    dp[0] = 0;
    ll best = 0;
    for (int i = 1; i <= m; ++i) {
      dp[i] = b[i] + max(0LL, dp[i - 1]);
      best = max(best, dp[i]);
    }
    ll one = tot + best; m = 0;
    for (int i = 2; i + 1 <= n; i += 2) {
      b[++m] = a[i] - a[i + 1];
    }
    dp[0] = best = 0;
    for (int i = 1; i <= m; ++i) {
      dp[i] = b[i] + max(0LL, dp[i - 1]);
      best = max(best, dp[i]);
    }
    ll two = tot + best;
    printf("%lld\n", max(one, two));
  }
  return 0;
}