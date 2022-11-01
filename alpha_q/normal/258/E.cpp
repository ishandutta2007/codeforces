#include <bits/stdc++.h>

using namespace std;

struct node {
  int mn, occ;
  node () {
    mn = occ = 0;
  } 
  node (int _m, int _o) {
    mn = _m, occ = _o;
  }
};

typedef pair <int, int> range;

const int N = 100005;

int n, m;
vector <int> g[N];
node t[4 * N];
int lazy[4 * N];
int flat[N], ptr;
int lt[N], rt[N];
vector <range> s[N];
int ans[N];

void dfs (int u, int from = -1) {
  flat[++ptr] = u;
  lt[u] = ptr;
  for (int v : g[u]) {
    if (v == from) continue;
    dfs(v, u);
  }
  rt[u] = ptr;
}

node merge (node a, node b) {
  node c;
  if (a.mn < b.mn) {
    c = a;
  } else if (a.mn > b.mn) {
    c = b;
  } else {
    c = a, c.occ += b.occ;
  }
  return c;
}

void propagate (int u, int b, int e) {
  t[u].mn += lazy[u];
  if (b != e) {
    lazy[u << 1] += lazy[u];
    lazy[u << 1 | 1] += lazy[u];
  }
  lazy[u] = 0;
}

void init (int u, int b, int e) {
  if (b == e) {
    t[u].mn = 0;
    t[u].occ = 1;
    return;
  }
  int mid = b + e >> 1;
  init(u << 1, b, mid);
  init(u << 1 | 1, mid + 1, e);
  t[u] = merge(t[u << 1], t[u << 1 | 1]);
}

void update (int u, int b, int e, int l, int r, int v) {
  if (lazy[u] != 0) propagate(u, b, e);
  if (b > r or e < l) return;
  if (b >= l and e <= r) {
    lazy[u] += v;
    propagate(u, b, e);
    return;
  }
  int mid = b + e >> 1;
  update(u << 1, b, mid, l, r, v);
  update(u << 1 | 1, mid + 1, e, l, r, v);
  t[u] = merge(t[u << 1], t[u << 1 | 1]);
}

void go (int u, int from = -1) {
  for (range z : s[u]) {
    update(1, 1, n, z.first, z.second, 1);
  }
  update(1, 1, n, lt[u], lt[u], 1);
  if (lazy[1] != 0) propagate(1, 1, n);
  ans[u] = (t[1].mn == 0 ? n - 1 - t[1].occ : n - 1);
  update(1, 1, n, lt[u], lt[u], -1);
  for (int v : g[u]) {
    if (v == from) continue;
    go(v, u);
  }
  for (range z : s[u]) {
    update(1, 1, n, z.first, z.second, -1);
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    s[u].emplace_back(lt[u], rt[u]);
    s[u].emplace_back(lt[v], rt[v]);
    s[v].emplace_back(lt[u], rt[u]);
    s[v].emplace_back(lt[v], rt[v]);
  }
  init(1, 1, n);
  go(1); 
  for (int i = 1; i <= n; ++i) {
    printf("%d ", ans[i]);
  }
  puts("");
  return 0;
}