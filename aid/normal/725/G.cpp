#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 2e5 + 5, logn = 18;
int n, m;
int p[maxn];
vector<int> g[maxn];
int from[maxn], tstart[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  n++;
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  p[0] = -1;
  for (int i = 1; i < n; i++) {
    scanf("%d", &p[i]);
    g[p[i]].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &from[i], &tstart[i]);
  }
  return true;
}

int dep[maxn], ts[maxn], heavy[maxn];

void dfs(int v) {
  ts[v] = 1;
  int maxts = 0;
  heavy[v] = -1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    dep[u] = dep[v] + 1;
    dfs(u);
    ts[v] += ts[u];
    if (ts[u] > maxts) {
      heavy[v] = u;
      maxts = ts[u];
    }
  }
}

int root[maxn], treePos[maxn];
int vals[maxn];
int vs[maxn];

struct node {
  int val, toadd;
  int flag;
};

node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v].toadd = 0;
  st[v].flag = false;
  if (tl == tr - 1) {
    st[v].val = vals[tl];
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  st[v].val = max(st[2 * v].val, st[2 * v + 1].val);
}

void push(int v) {
  if (!st[v].toadd) {
    return;
  }
  for (int it = 0; it < 2; it++) {
    int u = 2 * v + it;
    st[u].val += st[v].toadd;
    st[u].toadd += st[v].toadd;
    st[u].flag = true;
  }
  st[v].toadd = 0;
}

void del(int v, int tl, int tr) {
  if (!st[v].flag) {
    return;
  }
  st[v].val -= st[v].toadd;
  st[v].toadd = 0;
  st[v].flag = false;
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  del(2 * v, tl, tm);
  del(2 * v + 1, tm, tr);
  st[v].val = max(st[2 * v].val, st[2 * v + 1].val);
}

void add(int v, int tl, int tr, int l, int r, int toadd) {
  if (l == tl && r == tr) {
    del(v, tl, tr);
    st[v].flag = true;
    st[v].val += toadd;
    st[v].toadd += toadd;
    return;
  }
  st[v].flag = true;
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    add(2 * v, tl, tm, l, min(r, tm), toadd);
  }
  if (r > tm) {
    add(2 * v + 1, tm, tr, max(l, tm), r, toadd);
  }
  st[v].val = max(st[2 * v].val, st[2 * v + 1].val);
}

int get(int v, int tl, int tr, int l, int r, int x) {
  if (st[v].val <= x) {
    return -1;
  }
  if (tl == tr - 1) {
    return tl;
  }
  int tm = (tl + tr) / 2;
  if (r > tm) {
    int res = get(2 * v + 1, tm, tr, max(l, tm), r, x - st[v].toadd);
    if (res != -1) {
      return res;
    }
  }
  if (l < tm) {
    int res = get(2 * v, tl, tm, l, min(r, tm), x - st[v].toadd);
    if (res != -1) {
      return res;
    }
  }
  return -1;
}

pair<pair<int, int>, int> tosort[maxn];
int ans[maxn];

void updatePath(int v, int u, int val) {
  int ru = (u == -1 ? 0 : root[u]);
  while (root[v] != ru) {
    add(1, 0, n, treePos[root[v]], treePos[v] + 1, val);
    v = p[root[v]];
  }
  if (v != u) {
    add(1, 0, n, (u == -1 ? treePos[0] : treePos[u] + 1), treePos[v] + 1, val);
  }
}

void solve() {
  dep[0] = 0;
  dfs(0);
  for (int v = 0, pos = 0; v < n; v++) {
    if (p[v] == -1 || heavy[p[v]] != v) {
      for (int u = v; u != -1; u = heavy[u]) {
        root[u] = v;
        vals[pos] = 2 * dep[u];
        vs[pos] = u;
        treePos[u] = pos++;
      }
    }
  }
  buildst(1, 0, n);
  add(1, 0, n, 0, n, -inf);
  for (int i = 0; i < m; i++) {
    tosort[i] = make_pair(make_pair(tstart[i] + dep[from[i]], from[i]), i);
  }
  sort(tosort, tosort + m);
  for (int it = 0; it < m; it++) {
    int id = tosort[it].second;
    int v = from[id];
    while (v != -1) {
      int pos = get(1, 0, n, treePos[root[v]], treePos[v] + 1, tstart[id] + dep[from[id]]);
      if (pos == -1) {
        v = p[root[v]];
      } else {
        v = vs[pos];
        break;
      }
    }
    int t = tstart[id] + dep[from[id]] - (v == -1 ? 0 : 2 * dep[v]);
    updatePath(from[id], v, t);
    ans[id] = t + dep[from[id]];
  }
  for (int i = 0; i < m; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}