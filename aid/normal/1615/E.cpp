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

const int maxn = (int) 2e5 + 5;
int n, k;
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

int tin[maxn], tout[maxn];
int par[maxn];
vector<int> path;

void dfs(int v, int p) {
  par[v] = p;
  tin[v] = sz(path);
  bool leaf = true;
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    leaf = false;
    dfs(u, v);
  }
  if (leaf) {
    path.push_back(v);
  }
  tout[v] = sz(path);
}

struct node {
  int val, who, toadd;
};

node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v].val = 0;
  st[v].toadd = 0;
  if (tl == tr - 1) {
    st[v].who = path[tl];
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  st[v].who = st[2 * v].who;
}

void push(int v) {
  if (!st[v].toadd) {
    return;
  }
  for (int i = 0; i < 2; ++i) {
    int u = 2 * v + i;
    st[u].val += st[v].toadd;
    st[u].toadd += st[v].toadd;
  }
  st[v].toadd = 0;
}

void add(int v, int tl, int tr, int l, int r, int toadd) {
  if (l == tl && r == tr) {
    st[v].val += toadd;
    st[v].toadd += toadd;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    add(2 * v, tl, tm, l, min(r, tm), toadd);
  }
  if (r > tm) {
    add(2 * v + 1, tm, tr, max(l, tm), r, toadd);
  }
  if (st[2 * v].val > st[2 * v + 1].val) {
    st[v].val = st[2 * v].val;
    st[v].who = st[2 * v].who;
  } else {
    st[v].val = st[2 * v + 1].val;
    st[v].who = st[2 * v + 1].who;
  }
}

int del[maxn];

void solve() {
  path.clear();
  dfs(0, -1);
  if (k >= sz(path)) {
    long long res = -infll;
    for (int i = sz(path); i <= k; ++i) {
      res = max(res, (long long) i * (n - i));
    }
    printf("%lld\n", res);
    return;
  }
  buildst(1, 0, sz(path));
  for (int i = 0; i < n; ++i) {
    del[i] = false;
    add(1, 0, sz(path), tin[i], tout[i], 1);
  }
  for (int i = 0; i < k; ++i) {
    int v = st[1].who;
    while (v != -1 && !del[v]) {
      add(1, 0, sz(path), tin[v], tout[v], -1);
      del[v] = true;
      v = par[v];
    }
  }
  int maxb = 0;
  for (int i = 0; i < n; ++i) {
    if (!del[i]) {
      ++maxb;
    }
  }
  long long res = infll;
  for (int b = 0; b <= maxb; ++b) {
    int w = n - k - b;
    res = min(res, (long long) w * (k - b));
  }
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