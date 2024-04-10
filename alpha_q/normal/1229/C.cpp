#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;

vector <int> big[N];
int n, m, q; ll ans, sz[N];

inline ll get (int i) {
  return big[i].size() * 1LL * (sz[i] - big[i].size());
}

int main() {
  cin >> n >> m;
  while (m--) {
    int u, v; scanf("%d %d", &u, &v);
    if (u < v) big[u].emplace_back(v);
    else big[v].emplace_back(u);
    ++sz[u], ++sz[v];
  }
  for (int i = 1; i <= n; ++i) ans += get(i);
  printf("%lld\n", ans);
  cin >> q;
  ll it = 0;
  for (int i = 1; i <= q; ++i) {
    int u; scanf("%d", &u); ans -= get(u);
    // cerr << big[u].size() << '\n';
    for (int v : big[u]) {
      ans -= get(v); big[v].emplace_back(u); ans += get(v);
    }
    it += big[u].size();
    big[u].clear();
    printf("%lld\n", ans);
  }
  // cerr << it << endl;
  return 0;
}