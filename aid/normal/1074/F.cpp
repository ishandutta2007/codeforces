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

const int maxn = (int) 2e5 + 5;
int n, q;
vector<int> g[maxn];

int read() {
  if (scanf("%d%d", &n, &q) < 2) {
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
  return true;
}

const int logn = 20;
int p[maxn][logn];
int tin[maxn], tout[maxn], t;
int path[maxn];

void dfs(int v) {
  tin[v] = t;
  path[t++] = v;
  for (int i = 1; i < logn; i++) {
    p[v][i] = p[p[v][i - 1]][i - 1];
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p[v][0]) {
      continue;
    }
    p[u][0] = v;
    dfs(u);
  }
  tout[v] = t;
}

struct T {
  int val, cnt;

  T(): val(inf), cnt(0) {}
  
  T(int _val, int _cnt): val(_val), cnt(_cnt) {}

  T operator + (const T &t) const {
    if (val < t.val) {
      return *this;
    } else if (t.val < val) {
      return t;
    } else {
      return T(val, cnt + t.cnt);
    }
  }
};

struct node {
  T val;
  int toadd;
};

node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v].toadd = 0;
  if (tl == tr - 1) {
    st[v].val = T(0, 1);
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  st[v].val = st[2 * v].val + st[2 * v + 1].val;
}

void push(int v) {
  if (!st[v].toadd) {
    return;
  }
  for (int i = 0; i < 2; i++) {
    int u = 2 * v + i;
    st[u].val.val += st[v].toadd;
    st[u].toadd += st[v].toadd;
  }
  st[v].toadd = 0;
}

void update(int v, int tl, int tr, int l, int r, int toadd) {
  if (l == tl && r == tr) {
    st[v].val.val += toadd;
    st[v].toadd += toadd;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    update(2 * v, tl, tm, l, min(r, tm), toadd);
  }
  if (r > tm) {
    update(2 * v + 1, tm, tr, max(l, tm), r, toadd);
  }
  st[v].val = st[2 * v].val + st[2 * v + 1].val;
}

bool anc(int v, int u) {
  return tin[v] <= tin[u] && tout[u] <= tout[v];
}

void addEdge(int v, int u, int sgn) {
  if (anc(u, v)) {
    swap(v, u);
  }
  if (anc(v, u)) {
    int w = u;
    for (int i = logn - 1; i >= 0; i--) {
      if (!anc(p[w][i], v)) {
        w = p[w][i];
      }
    }
    update(1, 0, n, tin[w], tout[w], sgn);
    update(1, 0, n, tin[u], tout[u], -sgn);
    return;
  }
  update(1, 0, n, 0, n, sgn);
  update(1, 0, n, tin[v], tout[v], -sgn);
  update(1, 0, n, tin[u], tout[u], -sgn);
}

set<pair<int, int>> es;

void solve() {
  t = 0;
  p[0][0] = 0;
  dfs(0);
  buildst(1, 0, n);
  es.clear();
  for (int qq = 0; qq < q; qq++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    if (v > u) {
      swap(v, u);
    }
    int sgn;
    if (es.count(make_pair(v, u))) {
      sgn = -1;
      es.erase(make_pair(v, u));
    } else {
      sgn = 1;
      es.insert(make_pair(v, u));
    }
    addEdge(v, u, sgn);
    printf("%d\n", (st[1].val.val ? 0 : st[1].val.cnt));
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