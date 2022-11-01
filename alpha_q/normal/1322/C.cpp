#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 500010;

int t, n, m;
ll c[N], tot[N];
vector <int> g[N];
map <vector <int>, ll> f;

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", c + i);
      g[i].clear(), tot[i] = 0;
    }
    while (m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[v].emplace_back(u);
      tot[u] += c[v];
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
      sort(g[i].begin(), g[i].end());
      ans = __gcd(ans, tot[i]);
    }
    f.clear();
    for (int i = 1; i <= n; ++i) {
      if (g[i].empty()) continue;
      f[g[i]] += c[i];
    }
    for (auto it : f) ans = __gcd(ans, it.second);
    printf("%lld\n", ans);
  }
  return 0;
}