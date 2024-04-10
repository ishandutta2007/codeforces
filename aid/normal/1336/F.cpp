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

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1.5e5 + 5;
int n, m, k;
vector<int> g[maxn];
pair<int, int> ps[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &ps[i].first, &ps[i].second);
    ps[i].first--;
    ps[i].second--;
  }
  return true;
}

const int logn = 18;
int p[maxn][logn];
int path[maxn];
int tin[maxn], tout[maxn], t;
int dep[maxn];

void dfs0(int v, int pr) {
  path[t] = v;
  tin[v] = t++;
  p[v][0] = (pr == -1 ? v : pr);
  dep[v] = (pr == -1 ? 0 : dep[pr] + 1);
  for (int i = 1; i < logn; i++) {
    p[v][i] = p[p[v][i - 1]][i - 1];
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == pr) {
      continue;
    }
    dfs0(u, v);
  }
  tout[v] = t;
}

bool anc(int v, int u) {
  return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int getLca(int v, int u) {
  if (anc(v, u)) {
    return v;
  }
  if (anc(u, v)) {
    return u;
  }
  for (int i = logn - 1; i >= 0; i--) {
    if (!anc(p[v][i], u)) {
      v = p[v][i];
    }
  }
  return p[v][0];
}

int goUp(int v, int k) {
  for (int i = 0; i < logn; i++) {
    if (k & (1 << i)) {
      v = p[v][i];
    }
  }
  return v;
}

struct node {
  int x, y, ts;
  node *l, *r;

  node(int xx): x(xx), y(mrand()), ts(1), l(0), r(0) {}

  node *update() {
    ts = 1 + (l ? l->ts : 0) + (r ? r->ts : 0);
    return this;
  }
};

int tsz(node *v) {
  return (v ? v->ts : 0);
}

node *merge(node *l, node *r) {
  if (!l) {
    return r;
  }
  if (!r) {
    return l;
  }
  if (l->y < r->y) {
    l->r = merge(l->r, r);
    return l->update();
  } else {
    r->l = merge(l, r->l);
    return r->update();
  }
}

void split(node *v, int x, node *&l, node *&r) {
  if (!v) {
    l = 0;
    r = 0;
    return;
  }
  if (v->x < x) {
    split(v->r, x, v->r, r);
    l = v->update();
  } else {
    split(v->l, x, l, v->l);
    r = v->update();
  }
}

vector<int> qs[maxn];
long long res;

vector<int> vs;

void getVs(node *v) {
  if (!v) {
    return;
  }
  getVs(v->l);
  vs.push_back(path[v->x]);
  getVs(v->r);
}

void delV(node *&rt, int v) {
  node *l, *m, *r;
  split(rt, tin[v], l, r);
  split(r, tout[v], m, r);
  rt = merge(l, r);
}

int getCnt(node *&rt, int v) {
  node *l, *m, *r;
  split(rt, tin[v], l, r);
  split(r, tout[v], m, r);
  int res = tsz(m);
  rt = merge(l, merge(m, r));
  return res;
}

void updateRes(node *&rt, int v, int u) {
  int w = getLca(v, u);
  int a = dep[v] - dep[w], b = dep[u] - dep[w];
  if (a + b < k) {
    return;
  }
  if (a < k) {
    if (tin[v] > tin[u]) {
      return;
    }
    int x = goUp(u, a + b - k);
    res += getCnt(rt, x);
    return;
  }
  {
    int x = goUp(v, k - 1);
    res += tsz(rt) - getCnt(rt, x);
  }
  if (tin[v] > tin[u] && w != u) {
    int x = goUp(u, b - 1);
    res -= getCnt(rt, x);
  }
}

void addVer(node *&rt, int v) {
  node *l, *r;
  split(rt, tin[v], l, r);
  rt = merge(merge(l, new node(tin[v])), r);
}

node *dfs(int v, int pr) {
  node *vrt = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == pr) {
      continue;
    }
    node *urt = dfs(u, v);
    delV(urt, v);
    if (tsz(vrt) < tsz(urt)) {
      swap(vrt, urt);
    }
    vs.clear();
    getVs(urt);
    for (int it = 0; it < sz(vs); it++) {
      updateRes(vrt, v, vs[it]);
    }
    for (int it = 0; it < sz(vs); it++) {
      addVer(vrt, vs[it]);
    }
  }
  for (int i = 0; i < sz(qs[v]); i++) {
    updateRes(vrt, v, qs[v][i]);
    addVer(vrt, qs[v][i]);
  }
  return vrt;
}

void solve() {
  t = 0;
  dfs0(0, -1);
  for (int i = 0; i < n; i++) {
    qs[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v = ps[i].first, u = ps[i].second;
    if (anc(u, v)) {
      swap(v, u);
    }
    if (!anc(v, u)) {
      qs[v].push_back(u);
    }
    qs[u].push_back(v);
  }
  res = 0;
  dfs(0, -1);
  printf("%lld\n", res);
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