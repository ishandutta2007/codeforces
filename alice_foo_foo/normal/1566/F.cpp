#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

struct seg {
  long long l, r;
  seg (long long a = 0, long long b = 0) : l(a), r(b) {}
  bool operator < (const seg rhs) const { return r - l + 1 < rhs.r - rhs.l + 1; }
} s[maxN], t[maxN];

set<pair<long long, long long> > all;
long long dp[maxN][2];
long long a[maxN];
int T, n, m, len;

bool cmp(const seg lhs, const seg rhs) { return lhs.l < rhs.l; }

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; i++) {
      scanf("%lld%lld", &s[i].l, &s[i].r);
      int id = lower_bound(a + 1, a + n + 1, s[i].l) - a;
      if (id <= n && a[id] <= s[i].r) {
        --i; --m;
        continue;
      }
    }
    sort(s + 1, s + m + 1);
    all.clear();
    len = 0;
    for (int i = 1; i <= m; i++) {
      auto it = all.lower_bound(make_pair(s[i].l, -2e9));
      if (it != all.end() && s[i].r >= it -> second) continue;
      all.insert(make_pair(s[i].l, s[i].r));
      t[++len] = s[i];
    }
    sort(t + 1, t + len + 1, cmp);
    a[0] = -1e10; a[n + 1] = 1e10;
    dp[0][0] = dp[0][1] = 0;
    for (int i = 0, j = 1; i <= n; i++) {
      int k = j - 1;
      while (k + 1 <= len && t[k + 1].r <= a[i + 1]) ++k;
      if (k == j - 1) {
        dp[i + 1][0] = dp[i + 1][1] = min(dp[i][0], dp[i][1]);
        continue;
      }
      dp[i + 1][0] = dp[i + 1][1] = 1e18;
      for (int o = j - 1; o <= k; o++) {
        long long val_l0 = dp[i][0], val_l1 = dp[i][1], val_r0 = 0, val_r1 = 0;
        if (o != j - 1) val_l0 += t[o].l - a[i], val_l1 += 2 * (t[o].l - a[i]);
        if (o != k) val_r0 += 2 * (a[i + 1] - t[o + 1].r), val_r1 += a[i + 1] - t[o + 1].r;
        dp[i + 1][0] = min(dp[i + 1][0], val_r0 + min(val_l0, val_l1));
        dp[i + 1][1] = min(dp[i + 1][1], val_r1 + min(val_l0, val_l1));
      }
      j = k + 1;
    }
    printf("%lld\n", min(dp[n + 1][0], dp[n + 1][1]));
  }
  return 0;
}