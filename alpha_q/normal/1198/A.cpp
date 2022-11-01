#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000010;

int n; 
ll tot, a[N], val[N], freq[N], pf[N], sf[N];

ll get (ll x) {
  ll ret = 0;
  while ((1LL << ret) < x) ++ret;
  return ret;
}

int main() {
  cin >> n >> tot;
  tot *= 8LL;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
  }
  sort(a + 1, a + n + 1);
  int m = 0;
  for (int i = 1, j; i <= n; i = j) {
    val[++m] = a[i], j = i;
    while (j <= n and a[j] == a[i]) ++j, ++freq[m];
  }
  pf[0] = sf[m + 1] = 0;
  for (int i = 1; i <= m; ++i) pf[i] = pf[i - 1] + freq[i];
  for (int i = m; i >= 1; --i) sf[i] = sf[i + 1] + freq[i];
  ll ans = n;
  for (int i = 1, j = 1; i <= m; ++i) {
    while (j < m and n * get(j - i + 2) <= tot) ++j;
    ans = min(ans, pf[i - 1] + sf[j + 1]);
  }
  cout << ans << endl;
  return 0;
}