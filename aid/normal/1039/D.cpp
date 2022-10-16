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

const int maxn = (int) 1e5 + 5;
int n;
vector<int> g[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
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

int p[maxn];
vector<int> vs;

void dfs(int v) {
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p[v]) {
      continue;
    }
    p[u] = v;
    dfs(u);
  }
  vs.push_back(v);
}

int nid[maxn];
int np[maxn];
vector<int> ng[maxn];

int ans[maxn];

int dep[maxn][2];

int get(int x) {
  int res = 0;
  for (int v = 0; v < n; v++) {
    dep[v][0] = 0;
    dep[v][1] = 0;
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (u == p[v]) {
        continue;
      }
      int cur = dep[u][0];
      if (cur > dep[v][0]) {
        dep[v][1] = dep[v][0];
        dep[v][0] = cur;
      } else if (cur > dep[v][1]) {
        dep[v][1] = cur;
      }
    }
    dep[v][0]++;
    if (dep[v][0] + dep[v][1] >= x) {
      res++;
      dep[v][0] = 0;
    }
  }
  return res;
}

void solve(int l, int r) {
  if (l == r - 1) {
    return;
  }
  if (ans[l] == ans[r]) {
    for (int i = l + 1; i < r; i++) {
      ans[i] = ans[l];
    }
    return;
  }
  int m = (l + r) / 2;
  ans[m] = get(m);
  solve(l, m);
  solve(m, r);
}

void solve() {
  vs.clear();
  p[0] = -1;
  dfs(0);
  for (int i = 0; i < n; i++) {
    nid[vs[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    int v = vs[i];
    np[i] = (p[v] == -1 ? -1 : nid[p[v]]);
    ng[i].clear();
    for (int j = 0; j < sz(g[v]); j++) {
      ng[i].push_back(nid[g[v][j]]);
    }
  }
  for (int i = 0; i < n; i++) {
    p[i] = np[i];
    g[i] = ng[i];
  }
  ans[1] = get(1);
  ans[n] = get(n);
  solve(1, n);
  for (int i = 1; i <= n; i++) {
    printf("%d\n", ans[i]);
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