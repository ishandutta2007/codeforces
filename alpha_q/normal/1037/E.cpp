#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef pair <int, int> pii;

const int N = 200010;

set <pii> s;
set <int> g[N];
int n, m, k, ans, d[N], U[N], V[N], res[N];

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d", U + i, V + i);
    ++d[U[i]], ++d[V[i]];
    g[U[i]].insert(V[i]);
    g[V[i]].insert(U[i]);
  }
  for (int i = 1; i <= n; ++i) {
    s.emplace(d[i], i);
  }
  ans = n;
  for (int i = m; i > 0; --i) {
    while (!s.empty() and (*s.begin()).first < k) {
      int u = (*s.begin()).second;
      // cout << i << " --> " << u << endl;
      s.erase(s.begin());
      for (int v : g[u]) {
        s.erase(pii(d[v], v));
        --d[v];
        s.insert(pii(d[v], v));
        g[v].erase(u);
      }
      g[u].clear();
      --ans;
    }
    res[i] = ans;
    if (g[U[i]].find(V[i]) != g[U[i]].end()) {
      g[U[i]].erase(V[i]);
      g[V[i]].erase(U[i]);
      int u = U[i];
      if (s.find(pii(d[u], u)) != s.end()) {
        s.erase(pii(d[u], u));
        --d[u];
        s.insert(pii(d[u], u));
      }
      u = V[i];
      if (s.find(pii(d[u], u)) != s.end()) {
        s.erase(pii(d[u], u));
        --d[u];
        s.insert(pii(d[u], u));
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    printf("%d\n", res[i]);
  }
  return 0;
}