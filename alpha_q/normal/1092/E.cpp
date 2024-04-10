#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 1005;

bitset <N> vis;
vector <int> g[N];
int n, m, d[N], at, p[N];
vector <pair <int, int>> cen;

void go (int u, int from = -1, int far = 0) {
  d[u] = far, p[u] = from, vis[u] = 1;
  if (at == -1 or d[u] > d[at]) at = u;
  for (int v : g[u]) if (v - from) {
    go(v, u, far + 1);
  }
}

pair <int, int> get (int x) {
  at = -1; go(x);
  x = at; at = -1; go(x);
  int dia = d[at];
  int mid = d[at] >> 1;
  while (mid--) at = p[at];
  return {dia, at};
}

int main() {
  cin >> n >> m;
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    cen.push_back(get(i));
  }
  sort(cen.rbegin(), cen.rend());
  int ans = cen[0].first;
  for (int i = 1; i < cen.size(); ++i) {
    ans = max(ans, (1 + cen[0].first) / 2 + 1 + (1 + cen[i].first) / 2);
  }
  if (cen.size() > 2) ans = max(ans, (1 + cen[1].first) / 2 + 2 + (1 + cen[2].first) / 2);
  printf("%d\n", ans);
  for (int i = 1; i < cen.size(); ++i) {
    printf("%d %d\n", cen[0].second, cen[i].second);
  }
  return 0;
}