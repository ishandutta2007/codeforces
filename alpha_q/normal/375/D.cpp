#include <bits/stdc++.h>

using namespace std;

const int B = 320;
const int N = 110010;

struct query {
  int l, r, k, id;

  query () {}
  query (int l, int r, int k, int id) : l(l), r(r), k(k), id(id) {}

  bool operator < (const query &q) const {
    return l / B == q.l / B ? r < q.r : l / B < q.l / B;
  }
};

query yo[N]; vector <int> g[N];
int n, m, c[N], flat[N], ptr, lt[N], rt[N], res[N], f[N], cnt[N], b[B];

void dfs (int u = 1, int from = -1) {
  flat[++ptr] = u, lt[u] = ptr;
  for (int v : g[u]) if (v - from) dfs(v, u);
  rt[u] = ptr;
}

void add (int p) {
  p = c[flat[p]];
  if (f[p]) --cnt[f[p]], --b[f[p] / B];
  ++f[p], ++cnt[f[p]], ++b[f[p] / B];
}

void remove (int p) {
  p = c[flat[p]];
  --cnt[f[p]], --b[f[p] / B], --f[p];
  if (f[p]) ++cnt[f[p]], ++b[f[p] / B];
}

int get (int lo) {
  int at = lo / B, res = 0;
  for (int i = lo; i < at * B + B; ++i) res += cnt[i];
  for (int i = at + 1; i < B; ++i) res += b[i];
  return res;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", c + i);
  }
  for (int i = 1; i < n; ++i) {
    int u, v; scanf("%d %d", &u, &v);
    g[u].push_back(v); g[v].push_back(u);
  }
  dfs();
  for (int i = 1; i <= m; ++i) {
    int u, k; scanf("%d %d", &u, &k);
    yo[i] = query(lt[u], rt[u], k, i);
  }
  sort(yo + 1, yo + m + 1);
  int l = 1, r = 0;
  for (int i = 1; i <= m; ++i) {
    while (r < yo[i].r) add(++r);
    while (l > yo[i].l) add(--l);
    while (r > yo[i].r) remove(r--);
    while (l < yo[i].l) remove(l++);
    res[yo[i].id] = get(yo[i].k);
  }
  for (int i = 1; i <= m; ++i) {
    printf("%d\n", res[i]);
  }
  return 0;
}