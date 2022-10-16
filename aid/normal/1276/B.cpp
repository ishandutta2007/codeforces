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
int n, m, a, b;
vector<int> g[maxn], ids[maxn];

bool read() {
  if (scanf("%d%d%d%d", &n, &m, &a, &b) < 4) {
    return false;
  }
  a--;
  b--;
  for (int i = 0; i < n; i++) {
    g[i].clear();
    ids[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    ids[v].push_back(i);
    g[u].push_back(v);
    ids[u].push_back(i);
  }
  return true;
}

int used[maxn];
int tin[maxn], f[maxn], t;

void dfs0(int v, int p) {
  used[v] = true;
  tin[v] = t++;
  f[v] = tin[v];
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    if (used[u]) {
      f[v] = min(f[v], tin[u]);
      continue;
    }
    dfs0(u, v);
    f[v] = min(f[v], f[u]);
  }
}

int c[maxn], cs;

void dfs(int v, int p, int col) {
  used[v] = true;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i], e = ids[v][i];
    if (used[u]) {
      if (c[e] == -1) {
        c[e] = col;
      }
      continue;
    }
    int ncol = col;
    if (f[u] >= tin[v]) {
      ncol = cs++;
    }
    c[e] = ncol;
    dfs(u, v, ncol);
  }
}

vector<int> gg[maxn];
vector<int> cc;
vector<int> path;

bool getPath(int v, int p, int t) {
  path.push_back(v);
  if (v == t) {
    return true;
  }
  for (int i = 0; i < sz(gg[v]); i++) {
    int u = gg[v][i];
    if (u == p) {
      continue;
    }
    if (getPath(u, v, t)) {
      return true;
    }
  }
  path.pop_back();
  return false;
}

int getCnt(int v, int p) {
  int res = (v < n);
  for (int i = 0; i < sz(gg[v]); i++) {
    int u = gg[v][i];
    if (u == p) {
      continue;
    }
    res += getCnt(u, v);
  }
  return res;
}

void solve() {
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  t = 0;
  dfs0(0, -1);
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  for (int i = 0; i < m; i++) {
    c[i] = -1;
  }
  cs = 0;
  dfs(0, -1, -1);
  for (int i = 0; i < n + cs; i++) {
    gg[i].clear();
  }
  for (int v = 0; v < n; v++) {
    cc.clear();
    for (int i = 0; i < sz(g[v]); i++) {
      int e = ids[v][i];
      cc.push_back(c[e]);
    }
    sort(cc.begin(), cc.end());
    cc.erase(unique(cc.begin(), cc.end()), cc.end());
    for (int i = 0; i < sz(cc); i++) {
      int u = n + cc[i];
      gg[v].push_back(u);
      gg[u].push_back(v);
    }
  }
  path.clear();
  assert(getPath(a, -1, b));
  int x = getCnt(path[0], path[1]), y = getCnt(path[sz(path) - 1], path[sz(path) - 2]);
  x--;
  y--;
  printf("%lld\n", (long long) x * y);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}