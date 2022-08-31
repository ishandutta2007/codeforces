#include <bits/stdc++.h>
using namespace std;

const int maxN = 6e5 + 5;

vector<pair<int, int> > adj[maxN];
vector<int> edg[2][maxN];
int u[maxN], v[maxN], w[maxN], ban[maxN], lc[maxN], rc[maxN], tag[maxN], deg[maxN], vis[maxN];
int n, m, cnt, ans;

bool dfs1(int u, int pre, int flg) {
  vis[u] = 1;
  for (auto i : adj[u]) {
    if (i.second == pre) continue;
    tag[i.second] = (::u[i.second] == u) ^ flg;
    if (vis[i.first]) return 1;
    if (dfs1(i.first, i.second, flg)) break;
    flg = 1;
  }
  return 0;
}

void dfs2(int u) {
  if (!u) return;
  tag[lc[u]] ^= tag[u];
  tag[rc[u]] ^= tag[u];
  dfs2(lc[u]); dfs2(rc[u]);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &u[i], &v[i], &w[i]);
    edg[w[i] - 1][u[i]].push_back(i);
    edg[w[i] - 1][v[i]].push_back(i);
    if (w[i] == 1) {
      deg[u[i]] ^= 1;
      deg[v[i]] ^= 1;
    }
  }
  cnt = m;
  for (int u = 1; u <= n; u++) {
    for (int o = 0; o <= 1; o++) {
      vector<int> seq;
      for (auto i : edg[o][u]) {
        if (!ban[i]) {
          seq.push_back(i);
        }
      }
      for (int j = 1; j < (int)seq.size(); j += 2) {
        ++cnt;
        int x = seq[j - 1], y = seq[j];
        ban[x] = ban[y] = 1;
        lc[cnt] = x; rc[cnt] = y;
        if (::u[x] == u) {
          tag[x] = 1;
          ::u[cnt] = v[x];
        } else {
          ::u[cnt] = ::u[x];
        }
        if (::u[y] == u) {
          v[cnt] = v[y];
        } else {
          tag[y] = 1;
          v[cnt] = ::u[y];
        }
        if (::u[cnt] != v[cnt]) {
          edg[o][::u[cnt]].push_back(cnt);
          edg[o][v[cnt]].push_back(cnt);
        }
      }
    }
  }
  for (int i = 1; i <= cnt; i++) {
    if (!ban[i] && u[i] != v[i]) {
      adj[u[i]].emplace_back(v[i], i);
      adj[v[i]].emplace_back(u[i], i);
    }
  }
  for (int i = 1; i <= n; i++) {
    assert(adj[i].size() <= 2);
    if (!vis[i]) {
      dfs1(i, 0, 0);
    }
  }
  for (int i = 1; i <= cnt; i++) {
    if (!ban[i]) {
      dfs2(i);
    }
  }
  for (int i = 1; i <= n; i++) ans += deg[i];
  printf("%d\n", ans);
  for (int i = 1; i <= m; i++) printf("%d", tag[i] + 1);
  printf("\n");
  return 0;
}