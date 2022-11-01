#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int LG = 20;
const int N = 100005;

vector <int> g[N];
vector <int> c[N];
int n, q, ptr, comp[N], in[N], p[N][LG], h[N], d[N];

void go (int u, int from = -1, int far = 0, int cost = 0) {
  p[u][0] = from, h[u] = far, d[u] = cost, comp[u] = ptr;
  for (int i = 0; i < (int) g[u].size(); ++i) {
    int v = g[u][i], w = c[u][i];
    go(v, u, far + 1, cost + w);
  }
}

int lca (int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  for (int i = LG - 1; i >= 0; --i) {
    if (h[u] - (1 << i) >= h[v]) {
      u = p[u][i];
    }
  }
  if (u == v) return u;
  for (int i = LG - 1; i >= 0; --i) {
    if (p[u][i] != -1 and p[u][i] != p[v][i]) {
      u = p[u][i], v = p[v][i];
    }
  }
  return p[u][0];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int par, type;
    scanf("%d %d", &par, &type);
    if (par == -1) continue;
    ++in[i];
    g[par].push_back(i);
    c[par].push_back(type ^ 1);
  }
  memset(p, -1, sizeof p);
  for (int i = 1; i <= n; ++i) {
    if (in[i] == 0) {
      ++ptr, go(i);
    }
  }
  for (int j = 1; j < LG; ++j) {
    for (int i = 1; i <= n; ++i) {
      if (p[i][j - 1] != -1) {
        p[i][j] = p[p[i][j - 1]][j - 1];
      }
    }
  }
  scanf("%d", &q);
  while (q--) {
    int cmd, u, v;
    scanf("%d %d %d", &cmd, &u, &v);
    if (cmd == 1) {
      puts((comp[u] == comp[v] and u != v and lca(u, v) == u and d[v] - d[u] == h[v] - h[u]) ? "YES" : "NO");
    } else {
      int l = lca(u, v);
      puts((comp[u] == comp[v] and u != v and l != v and d[u] - d[l] == h[u] - h[l] and d[v] - d[l] == 0) ? "YES" : "NO");
    }
  }
  return 0;
}