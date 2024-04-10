#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef pair <int, int> pii;

#define x first
#define y second

int q;
map <int, int> sz;
map <int, int> par;
map <int, int> dist;
map <int, vector <pii>> g;
set <int> active;

inline void init (int u) {
  if (active.count(u)) return;
  active.emplace(u);
  sz[u] = 1, par[u] = u, dist[u] = 0;
}

inline int find (int x) {
  if (par.find(x) == par.end() or par[x] == x) return par[x] = x;
  return par[x] = find(par[x]);
}

inline int get (int u) {
  return dist.find(u) == dist.end() ? dist[u] = 0 : dist[u];
}

void dfs (int u, int from, int cost) {
  dist[u] = cost;
  for (pii e : g[u]) {
    if (e.x != from) {
      dfs(e.x, u, cost ^ e.y);
    } 
  }
}

inline void unite (int x, int y, int w) {
  int r_x = find(x), r_y = find(y);
  if (r_x == r_y) return;
  if (sz[r_x] < sz[r_y]) {
    swap(x, y);
    swap(r_x, r_y);
  }
  dfs(y, -1, w ^ get(x));
  g[x].emplace_back(y, w);
  g[y].emplace_back(x, w);
  sz[r_x] += sz[r_y];
  par[r_y] = r_x;
}

int main() {
  scanf("%d", &q);
  int last = 0;
  while (q--) {
    int cmd, l, r, x;
    scanf("%d %d %d", &cmd, &l, &r);
    l ^= last, r ^= last;
    if (l > r) swap(l, r); ++r;
    init(l); init(r);
    if (cmd == 1) {
      scanf("%d", &x);
      x ^= last;
      unite(l, r, x);
    } else {
      int r_l = find(l), r_r = find(r);
      if (r_l != r_r) {
        puts("-1");
        last = 1;
        continue;
      }
      last = get(l) ^ get(r);
      printf("%d\n", last);
    }
  }
  return 0;
}