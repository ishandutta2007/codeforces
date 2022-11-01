#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int t, n, m;
bitset <N> vis;
vector <int> prv[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      prv[i].clear(), vis[i] = 0;
    }
    while (m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      prv[v].emplace_back(u);
    }
    vector <int> ans;
    for (int i = 1; i <= n; ++i) {
      bool ok = 1;
      for (int x : prv[i]) if (vis[x]) {
        for (int y : prv[x]) if (vis[y]) {
          ok = 0;
          break;
        }
        if (!ok) break;
      }
      if (ok) vis[i] = 1;
      else ans.emplace_back(i);
    }
    printf("%d\n", (int) ans.size());
    for (int x : ans) printf("%d ", x); puts("");
  }
  return 0;
}