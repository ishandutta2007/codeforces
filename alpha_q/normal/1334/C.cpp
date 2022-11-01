#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 600010;

int t, n; ll a[N], b[N], c[N], p[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld %lld", a + i, b + i);
      a[n + i] = a[i], b[n + i] = b[i];
    }
    for (int i = 1; i < n + n; ++i) {
      c[i] = max(0LL, a[i + 1] - b[i]);
      p[i] = p[i - 1] + c[i];
    }
    ll ans = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
      ll cur = a[i] + p[i + n - 2] - p[i - 1];
      ans = min(ans, cur);
    }
    printf("%lld\n", ans);
  }
  return 0;
}