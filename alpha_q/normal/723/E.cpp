#include <bits/stdc++.h>

using namespace std;

const int N = 205;
const int M = 40010;

bitset <M> bad;
vector <int> g[N];
vector <int> circ, edCirc, nodes;
int t, n, m, deg[N], U[M], V[M], vis[N];

void hierholzer (int src) {
  circ.clear(), edCirc.clear();
  if (!deg[src]) return;
  vector <int> path, ed;
  path.push_back(src);
  int at = src;
  while (!path.empty()) {
    if (deg[at]) {
      path.push_back(at);
      while (bad[g[at].back()]) g[at].pop_back();
      int e = g[at].back(), nxt = U[e] ^ at ^ V[e];
      ed.emplace_back(e);
      bad[e] = 1, --deg[at], --deg[nxt], at = nxt;
    } else {
      circ.push_back(at);
      if (!ed.empty()) edCirc.emplace_back(ed.back()), ed.pop_back();
      at = path.back(), path.pop_back();
    }
  }
  reverse(circ.begin(), circ.end());
  reverse(edCirc.begin(), edCirc.end());
}

void go (int u) {
  vis[u] = 1;
  nodes.emplace_back(u);
  for (int e : g[u]) {
    int v = U[e] ^ u ^ V[e];
    if (vis[v]) continue; go(v);
  }
}

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
    }
    bad.reset();
    memset(vis, 0, sizeof vis);
    memset(deg, 0, sizeof deg);
    for (int i = 1; i <= m; ++i) {
      scanf("%d %d", U + i, V + i);
      g[U[i]].push_back(i); 
      g[V[i]].push_back(i);
      ++deg[U[i]], ++deg[V[i]];
    }
    int tmp = m, ans = n;
    for (int i = 1; i <= n; ++i) {
      if (vis[i]) continue;
      nodes.clear(); go(i);
      vector <int> odd;
      for (int u : nodes) if (deg[u] & 1) {
        odd.emplace_back(u);
      }
      ans -= odd.size();
      assert(odd.size() % 2 == 0);
      for (int j = 0; j < odd.size(); j += 2) {
        ++tmp; U[tmp] = odd[j], V[tmp] = odd[j + 1];
        g[U[tmp]].emplace_back(tmp);
        g[V[tmp]].emplace_back(tmp);
        ++deg[U[tmp]], ++deg[V[tmp]];
      }
      // cout << "yo\n";
      hierholzer(i);
      // cout << "yo\n";
      int at = i;
      for (int e : edCirc) {
        int nxt = U[e] ^ at ^ V[e];
        if (nxt == U[e]) swap(U[e], V[e]);
        at = nxt;
      }
    }
    cout << ans << '\n';
    for (int i = 1; i <= m; ++i) {
      printf("%d %d\n", U[i], V[i]);
    }
  }
  return 0;
}