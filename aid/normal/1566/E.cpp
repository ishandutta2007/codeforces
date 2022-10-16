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
int n;
vector<int> g[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
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

int par[maxn], dep[maxn];
vector<int> vs[maxn];

void dfs(int v) {
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    if (u == par[v]) {
      continue;
    }
    par[u] = v;
    dep[u] = dep[v] + 1;
    vs[dep[u]].push_back(u);
    dfs(u);
  }
}

int del[maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    vs[i].clear();
  }
  par[0] = -1;
  dep[0] = 0;
  dfs(0);
  for (int i = 0; i < n; ++i) {
    del[i] = false;
  }
  int lvs = 0, buds = 0;
  bool rleaf = false;
  for (int d = n - 1; d >= 0; --d) {
    for (int it = 0; it < sz(vs[d]); ++it) {
      int v = vs[d][it];
      if (del[v]) {
        continue;
      }
      int u = par[v];
      if (u == 0) {
        ++lvs;
        del[v] = true;
        rleaf = true;
        continue;
      }
      ++buds;
      del[u] = true;
      for (int i = 0; i < sz(g[u]); ++i) {
        int w = g[u][i];
        if (w == par[u] || del[w]) {
          continue;
        }
        ++lvs;
        del[w] = true;
      }
    }
  }
  int res = lvs - buds;
  if (!rleaf) {
    ++res;
  }
  printf("%d\n", res);
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