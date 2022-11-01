#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 500010;
const int MOD = 998244353;

pii range[N];
ll two[N], dp[N], pf[N];
int n, k, m, a[N], lt[N], rt[N], val[N], id[N];

int main() {
  two[0] = 1;
  for (int i = 1; i < N; ++i) two[i] = 2LL * two[i - 1] % MOD;
  cin >> n >> k >> m;
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d", lt + i, rt + i, val + i);
    id[i] = i;
  }
  sort(id, id + m, [] (int i, int j) {return rt[i] < rt[j];});
  ll ans = 1;
  for (int bit = 0; bit < k; ++bit) {
    for (int i = 1; i <= n; ++i) a[i] = 0;
    int sz = 0;
    for (int it = 0; it < m; ++it) {
      int i = id[it];
      if (val[i] & 1 << bit) ++a[lt[i]], --a[rt[i] + 1];
      else range[++sz] = make_pair(rt[i], lt[i]);
    }
    for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
    for (int i = 1; i <= n; ++i) a[i] = (a[i] > 0);
    if (!sz) {
      int zero = 0;
      for (int i = 1; i <= n; ++i) if (!a[i]) ++zero;
      ans = ans * two[zero] % MOD;
      continue;
    }
    dp[0] = pf[0] = 1;
    int last = 0, at = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i]) {
        dp[i] = dp[i - 1];
        pf[i] = pf[i - 1];
        continue;
      }
      while (at < sz and range[at + 1].first < i) {
        last = max(last, range[++at].second);
      }
      dp[i] = pf[i - 1] - (last ? pf[last - 1] : 0);
      if (dp[i] < 0) dp[i] += MOD;
      pf[i] = pf[i - 1] + dp[i];
      if (pf[i] >= MOD) pf[i] -= MOD;
    }
    while (at < sz) last = max(last, range[++at].second);
    ll cur = 0;
    for (int i = n; i >= last; --i) {
      if (a[i]) continue;
      cur += dp[i]; if (cur >= MOD) cur -= MOD;
    }
    ans = ans * cur % MOD;
  }
  cout << ans << '\n';
  return 0;
}