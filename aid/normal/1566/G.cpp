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

const int maxn = (int) 1e5 + 5;
int n, m;
map<int, long long> g[maxn];
set<pair<long long, int>> es[maxn];
set<pair<long long, pair<int, int>>> all;
set<pair<long long, int>> b3;
set<pair<long long, int>> sts[maxn];
long long st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v] = infll;
  if (tl == tr - 1) {
    sts[tl].clear();
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void del(int v, int tl, int tr, int pos, pair<long long, int> val) {
  if (tl == tr - 1) {
    sts[tl].erase(val);
    st[v] = (sts[tl].empty() ? infll : sts[tl].begin()->first);
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    del(2 * v, tl, tm, pos, val);
  } else {
    del(2 * v + 1, tm, tr, pos, val);
  }
  st[v] = min(st[2 * v], st[2 * v + 1]);
}

void add(int v, int tl, int tr, int pos, pair<long long, int> val) {
  if (tl == tr - 1) {
    sts[tl].insert(val);
    st[v] = (sts[tl].empty() ? infll : sts[tl].begin()->first);
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    add(2 * v, tl, tm, pos, val);
  } else {
    add(2 * v + 1, tm, tr, pos, val);
  }
  st[v] = min(st[2 * v], st[2 * v + 1]);
}

long long get(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v];
  }
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

void delVertex(int v) {
  int cntv = 0;
  long long b3val = 3 * infll;
  for (auto itv = es[v].begin(); itv != es[v].end() && cntv < 3; ++itv, ++cntv) {
    int vv = itv->second;
    del(1, 0, n, vv, make_pair(itv->first, v));
    b3val += itv->first - infll;
  }
  b3.erase(make_pair(b3val, v));
}

void addVertex(int v) {
  int cntv = 0;
  long long b3val = 3 * infll;
  for (auto itv = es[v].begin(); itv != es[v].end() && cntv < 3; ++itv, ++cntv) {
    int vv = itv->second;
    add(1, 0, n, vv, make_pair(itv->first, v));
    b3val += itv->first - infll;
  }
  b3.insert(make_pair(b3val, v));
}

void addEdge(int v, int u, long long w) {
  if (v > u) {
    swap(v, u);
  }
  delVertex(v);
  delVertex(u);
  g[v][u] = w;
  g[u][v] = w;
  es[v].insert(make_pair(w, u));
  es[u].insert(make_pair(w, v));
  all.insert(make_pair(w, make_pair(v, u)));
  addVertex(v);
  addVertex(u);
}

void delEdge(int v, int u) {
  if (v > u) {
    swap(v, u);
  }
  delVertex(v);
  delVertex(u);
  long long w = g[v][u];
  g[v].erase(u);
  g[u].erase(v);
  es[v].erase(make_pair(w, u));
  es[u].erase(make_pair(w, v));
  all.erase(make_pair(w, make_pair(v, u)));
  addVertex(v);
  addVertex(u);
}

void getRes() {
  long long res = infll;
  res = min(res, b3.begin()->first);
  int v = all.begin()->second.first, u = all.begin()->second.second;
  long long wmin = all.begin()->first;
  int cntv = 0;
  for (auto itv = es[v].begin(); itv != es[v].end() && cntv < 3; ++itv, ++cntv) {
    int vv = itv->second;
    if (vv == u) {
      continue;
    }
    int cntu = 0;
    for (auto itu = es[u].begin(); itu != es[u].end() && cntu < 3; ++itu, ++cntu) {
      int uu = itu->second;
      if (uu == v || vv == uu) {
        continue;
      }
      res = min(res, itv->first + itu->first);
      break;
    }
  }
  delVertex(v);
  delVertex(u);
  if (0 < v) {
    res = min(res, wmin + get(1, 0, n, 0, v));
  }
  if (v + 1 < u) {
    res = min(res, wmin + get(1, 0, n, v + 1, u));
  }
  if (u + 1 < n) {
    res = min(res, wmin + get(1, 0, n, u + 1, n));
  }
  addVertex(v);
  addVertex(u);
  printf("%lld\n", res);
}

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  b3.clear();
  for (int i = 0; i < n; ++i) {
    g[i].clear();
    es[i].clear();
    b3.insert(make_pair(3 * infll, i));
  }
  all.clear();
  buildst(1, 0, n);
  for (int i = 0; i < m; ++i) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    --v;
    --u;
    addEdge(v, u, w);
  }
  return true;
}

void solve() {
  getRes();
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; ++qq) {
    int t;
    scanf("%d", &t);
    if (!t) {
      int v, u;
      scanf("%d%d", &v, &u);
      --v;
      --u;
      delEdge(v, u);
    } else {
      int v, u, w;
      scanf("%d%d%d", &v, &u, &w);
      --v;
      --u;
      addEdge(v, u, w);
    }
    getRes();
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