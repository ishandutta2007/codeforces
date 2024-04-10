#include <bits/stdc++.h>

using namespace std;

const int LG = 20;
const int N = (1 << 20) + 69;


vector <int> g[N];
vector <int> circ;
bitset <N> bad, vis;
map <int, vector <int>> mp[N];
int n, m, a[N], b[N], deg[N], U[N], V[N];

void hierholzer (int src) {
  if (!deg[src]) return;
  vector <int> path;
  path.push_back(src);
  int at = src;
  while (!path.empty()) {
    if (deg[at]) {
      path.emplace_back(at);
      while (bad[g[at].back()]) g[at].pop_back();
      int e = g[at].back(), nxt = U[e] ^ at ^ V[e];
      bad[e] = 1, --deg[at], --deg[nxt], at = nxt;
    } else {
      circ.emplace_back(at);
      at = path.back(), path.pop_back();
    }
  }
  reverse(circ.begin(), circ.end());
}

void dfs (int u) {
  vis[u] = 1;
  for (int e : g[u]) {
    int v = U[e] ^ u ^ V[e];
    if (!vis[v]) dfs(v);
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", a + i, b + i);
  }
  m = n;
  for (int bit = 20; bit >= 0; --bit) {
    for (int i = 0; i < 1 << LG; ++i) {
      g[i].clear(), deg[i] = 0, bad[i] = 0;
    }
    circ.clear();
    for (int i = 1; i <= n; ++i) {
      U[i] = a[i] & ((1 << bit) - 1);
      V[i] = b[i] & ((1 << bit) - 1);
      if (U[i] > V[i]) swap(U[i], V[i]);
      // cout << U[i] << " " << V[i] << endl;
      g[U[i]].emplace_back(i);
      g[V[i]].emplace_back(i);
      ++deg[U[i]], ++deg[V[i]];
    }
    bool bad = 0;
    for (int i = 0; i < 1 << LG; ++i) {
      if (deg[i] & 1) {
        bad = 1;
        break;
      } 
    }
    if (bad) continue;
    int src = -1, cnt = 0;
    for (int i = 0; i < 1 << LG; ++i) {
      if (deg[i]) ++cnt, src = i;
    }
    if (src == -1) continue;
    vis.reset(); dfs(src);
    if (vis.count() != cnt) continue;
    hierholzer(src);
    for (int i = 1; i <= n; ++i) {
      mp[U[i]][V[i]].emplace_back(i);
    }
    cout << bit << '\n';
    for (int i = 0; i + 1 < circ.size(); ++i) {
      int u = circ[i], v = circ[i + 1];
      int cur = mp[min(u, v)][max(u, v)].back();
      mp[min(u, v)][max(u, v)].pop_back();
      int x = 2 * cur - 1, y = 2 * cur;
      if ((a[cur] & ((1 << bit) - 1)) != u) swap(x, y);
      printf("%d %d ", x, y);
    }
    cout << '\n';
    return 0;
  }
  return 0;
}