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

const int maxn = (int) 5e5 + 5;
int n, q;
vector<pair<int, int>> g[maxn];
vector<int> vqs[maxn];
int ps[maxn];
int wps[maxn];
int qs[maxn][3];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
    vqs[i].clear();
  }
  for (int v = 1; v < n; v++) {
    int u, w;
    scanf("%d%d", &u, &w);
    u--;
    g[u].push_back(make_pair(v, w));
    ps[v] = u;
    wps[v] = w;
  }
  for (int i = 0; i < q; i++) {
    int v, l, r;
    scanf("%d%d%d", &v, &l, &r);
    v--;
    l--;
    qs[i][0] = v;
    qs[i][1] = l;
    qs[i][2] = r;
    vqs[v].push_back(i);
  }
  return true;
}

struct node {
  long long val, toadd;
};

node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v].val = infll;
  st[v].toadd = 0;
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void push(int v) {
  if (!st[v].toadd) {
    return;
  }
  for (int i = 0; i < 2; i++) {
    int u = 2 * v + i;
    st[u].val += st[v].toadd;
    st[u].toadd += st[v].toadd;
  }
  st[v].toadd = 0;
}

void update(int v, int tl, int tr, int pos, long long val) {
  if (tl == tr - 1) {
    st[v].val = val;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    update(2 * v, tl, tm, pos, val);
  } else {
    update(2 * v + 1, tm, tr, pos, val);
  }
  st[v].val = min(st[2 * v].val, st[2 * v + 1].val);
}

void addSeg(int v, int tl, int tr, int l, int r, long long val) {
  if (l == tl && r == tr) {
    st[v].val += val;
    st[v].toadd += val;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    addSeg(2 * v, tl, tm, l, min(r, tm), val);
  }
  if (r > tm) {
    addSeg(2 * v + 1, tm, tr, max(l, tm), r, val);
  }
  st[v].val = min(st[2 * v].val, st[2 * v + 1].val);
}

long long get(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v].val;
  }
  push(v);
  int tm = (tl + tr) / 2;
  long long res = infll;
  if (l < tm) {
    res = min(res, get(2 * v, tl, tm, l, min(r, tm)));
  }
  if (r > tm) {
    res = min(res, get(2 * v + 1, tm, tr, max(l, tm), r));
  }
  return res;
}

long long dep[maxn];
int ls[maxn], rs[maxn];
long long ans[maxn];

void getSegs(int v) {
  ls[v] = v;
  rs[v] = v + 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first;
    getSegs(u);
    rs[v] = rs[u];
  }
}

void dfs(int v) {
  for (int it = 0; it < sz(vqs[v]); it++) {
    int id = vqs[v][it];
    int l = qs[id][1], r = qs[id][2];
    ans[id] = get(1, 0, n, l, r);
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, w = g[v][i].second;
    addSeg(1, 0, n, 0, n, w);
    addSeg(1, 0, n, ls[u], rs[u], -2 * w);
    dfs(u);
    addSeg(1, 0, n, ls[u], rs[u], 2 * w);
    addSeg(1, 0, n, 0, n, -w);
  }
}

void solve() {
  dep[0] = 0;
  for (int i = 1; i < n; i++) {
    dep[i] = dep[ps[i]] + wps[i];
  }
  buildst(1, 0, n);
  for (int v = 0; v < n; v++) {
    if (g[v].empty()) {
      update(1, 0, n, v, dep[v]);
    }
  }
  getSegs(0);
  dfs(0);
  for (int i = 0; i < q; i++) {
    printf("%lld\n", ans[i]);
  }
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