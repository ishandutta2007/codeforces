#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

bitset <N> vis;
vector <int> g[N];
int n, k, cur, U[N], V[N], comp[N], nod[N], ed[N];

void go (int u) {
  vis[u] = 1, comp[u] = cur, ++nod[cur];
  for (int v : g[u]) if (!vis[v]) go(v);
}

int main() {
  cin >> n >> k;
  for (int i = 1, u, v; i <= k; ++i) {
    scanf("%d %d", &u, &v);
    U[i] = u, V[i] = v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    ++cur; go(i);
  }
  for (int i = 1; i <= k; ++i) ++ed[comp[U[i]]];
  int ans = 0;
  for (int i = 1; i <= cur; ++i) {
    ans += ed[i] + 1 - nod[i];
  }
  cout << ans << '\n';
  return 0;
}