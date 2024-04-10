#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

bitset <N> vis;
vector <int> g[N], h[N];
int n, m, U[N], V[N], W[N], st[N], comp[N], ptr, cur, pos[N];

void go (int u) {
  vis[u] = 1;
  for (int e : g[u]) {
    int v = V[e];
    if (!vis[v]) go(v);
  }
  st[++ptr] = u;
}

void dfs (int u) {
  comp[u] = cur;
  for (int e : h[u]) {
    int v = U[e];
    if (!comp[v]) dfs(v);
  }
}

bool ok (int x) {
  for (int i = 1; i <= n; ++i) {
    g[i].clear(), h[i].clear();
  }
  for (int i = 1; i <= m; ++i) {
    if (W[i] > x) {
      g[U[i]].push_back(i); 
      h[V[i]].push_back(i);
    }
  }
  ptr = cur = 0, vis.reset();
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) go(i);
  }
  memset(comp, 0, sizeof comp);
  for (int i = n; i > 0; --i) {
    if (!comp[st[i]]) ++cur, dfs(st[i]); 
  }
  return cur == n; 
}

int main() {
  cin >> n >> m;
  int lo = 0, hi = 0; 
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d %d", U + i, V + i, W + i);
    hi = max(hi, W[i]);
  }
  while (lo < hi) {
    int mid = lo + hi >> 1;
    if (ok(mid)) hi = mid;
    else lo = mid + 1;
  }
  for (int i = 1; i <= n; ++i) {
    g[i].clear(), h[i].clear();
  }
  for (int i = 1; i <= m; ++i) {
    if (W[i] > lo) {
      g[U[i]].push_back(i); 
      h[V[i]].push_back(i);
    }
  }
  ptr = 0, vis.reset();
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) go(i);
  }
  for (int i = 1; i <= n; ++i) {
    pos[st[i]] = i;
  }
  vector <int> ans;
  for (int i = 1; i <= m; ++i) {
    int u = U[i], v = V[i];
    if (pos[u] < pos[v]) ans.push_back(i);
  }
  cout << lo << " " << ans.size() << '\n';
  for (int x : ans) cout << x << " "; cout << '\n';
  return 0;
}