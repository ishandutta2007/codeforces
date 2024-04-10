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
vector<pair<int, int>> es[maxn];
vector<int> vs[maxn];
int deg[maxn];
vector<int> cs[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    es[i].clear();
    vs[i].clear();
  }
  for (int i = 0; i < n; i++) {
    deg[i] = 0;
    cs[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u, c;
    scanf("%d%d%d", &v, &u, &c);
    v--;
    u--;
    c--;
    es[c].push_back(make_pair(v, u));
    vs[c].push_back(v);
    vs[c].push_back(u);
    deg[v]++;
    cs[v].push_back(c);
    deg[u]++;
    cs[u].push_back(c);
  }
  return true;
}

vector<int> p[maxn];
vector<int> ts[maxn];

int get(int c, int x) {
  return (p[c][x] == x ? x : p[c][x] = get(c, p[c][x]));
}

void unite(int c, int x, int y) {
  x = get(c, x);
  y = get(c, y);
  if (x == y) {
    return;
  }
  if (ts[c][x] < ts[c][y]) {
    swap(x, y);
  }
  ts[c][x] += ts[c][y];
  p[c][y] = x;
}

bool check(int c, int vv, int uu) {
  int v = lower_bound(vs[c].begin(), vs[c].end(), vv) - vs[c].begin();
  if (v >= sz(vs[c]) || vs[c][v] != vv) {
    return false;
  }
  int u = lower_bound(vs[c].begin(), vs[c].end(), uu) - vs[c].begin();
  if (u >= sz(vs[c]) || vs[c][u] != uu) {
    return false;
  }
  return get(c, v) == get(c, u);
}

map<pair<int, int>, int> mem;

void solve() {
  for (int i = 0; i < n; i++) {
    sort(cs[i].begin(), cs[i].end());
    cs[i].erase(unique(cs[i].begin(), cs[i].end()), cs[i].end());
  }
  for (int c = 0; c < m; c++) {
    sort(vs[c].begin(), vs[c].end());
    vs[c].erase(unique(vs[c].begin(), vs[c].end()), vs[c].end());
    int k = sz(vs[c]);
    p[c].resize(k);
    ts[c].resize(k);
    for (int v = 0; v < k; v++) {
      p[c][v] = v;
      ts[c][v] = 1;
    }
    for (int i = 0; i < sz(es[c]); i++) {
      int v = lower_bound(vs[c].begin(), vs[c].end(), es[c][i].first) - vs[c].begin();
      int u = lower_bound(vs[c].begin(), vs[c].end(), es[c][i].second) - vs[c].begin();
      unite(c, v, u);
    }
  }
  mem.clear();
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; qq++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    if (deg[v] > deg[u] || (deg[v] == deg[u] && v > u)) {
      swap(v, u);
    }
    if (mem.count(make_pair(v, u))) {
      printf("%d\n", mem[make_pair(v, u)]);
      continue;
    }
    int res = 0;
    for (int c = 0; c < sz(cs[v]); c++) {
      res += check(cs[v][c], v, u);
    }
    mem[make_pair(v, u)] = res;
    printf("%d\n", res);
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