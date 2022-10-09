#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 100005;

long long a[MAXN];
long long d[MAXN];
long long sp[MAXN];
long long best[MAXN];

int main() {
  long long n, k;
  scanf("%lld%lld", &n, &k);
  for (long long i = 1; i <= n; ++i)
    scanf("%lld", &a[i]);
  for (long long i = 1; i <= n; ++i)
    scanf("%lld", &d[i]);
  if (k == 0) {
    long long ans = 0;
    for (long long i = n; i >= 1; --i) {
      sp[i] = sp[i + 1] + a[i];
      ans = max(ans, sp[i] - d[i]);
    }
    printf("%lld\n", ans);
  } else if (k == 1) {
    long long ans = 0;
    for (long long i = n; i >= 1; --i) {
      sp[i] = sp[i + 1] + a[i];
      ans = max(ans, sp[i] - d[i]);
      best[i] = ans;
    }
    ans = 0;
    long long s = 0;
    long long mn = 1000000000;
    for (long long i = 1; i < n; ++i) {
      mn = min(mn, d[i]);
      s += a[i];
      ans = max(ans, max(0LL, s - mn) + best[i + 1]);
    }
    mn = 1000000000000000LL;
    s = 0;
    for (int long long i = 1; i < n - 1; ++i) {
      s += a[i];
      long long t = a[i] - d[i] + max(0LL, a[i + 1] - d[i + 1]) + sp[i + 2];
      ans = max(ans, t);
      t = s - mn + max(0LL, a[i + 1] - d[i + 1]) + sp[i + 2];
      ans = max(ans, t);
      mn = min(mn, s - a[i] + d[i]);
    }
    printf("%lld\n", ans);
  } else {
    long long mn = 1000000000, s = 0, ans = max(0LL, a[n] - d[n]);
    for (long long i = 1; i <= n; ++i)
      s += a[i];
    for (int i = 1; i < n; ++i)
      ans = max(ans, s - d[i]);
    printf("%lld\n", ans);
  }

  return 0;
}