#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), deg(n);
    for (int& x: a) cin >> x;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      edges[i].first = u;
      edges[i].second = v;
      deg[u]++;
      deg[v]++;
    }
    if (m%2 == 0) {
      cout << "0\n";
      continue;
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
      if (deg[i]&1) ans = min(ans, a[i]);
    }
    for (int i = 0; i < m; i++) {
      int u = edges[i].first;
      int v = edges[i].second;
      if (deg[u]%2 == 0 && deg[v]%2 == 0) ans = min(ans, a[u]+a[v]);
    }
    cout << ans << '\n';
  }
}