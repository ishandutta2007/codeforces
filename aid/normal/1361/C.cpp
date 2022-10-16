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
const int logvs = 20, maxvs = (1 << logvs) + 5;
int m;
int es[maxn][2];

bool read() {
  if (scanf("%d", &m) < 1) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &es[i][j]);
    }
  }
  return true;
}

vector<int> g[maxvs];
vector<int> ids[maxvs];
vector<int> path;
int del[maxn];

void dfs(int v) {
  while (!g[v].empty()) {
    int u = g[v].back();
    int e = ids[v].back();
    g[v].pop_back();
    ids[v].pop_back();
    if (del[e / 2]) {
      continue;
    }
    del[e / 2] = true;
    dfs(u);
    path.push_back(e ^ 1);
    path.push_back(e);
  }
}

bool solve1(int k) {
  for (int i = 0; i < (1 << k); i++) {
    g[i].clear();
    ids[i].clear();
  }
  int s = -1;
  for (int i = 0; i < m; i++) {
    del[i] = false;
    int v = (es[i][0] & ((1 << k) - 1));
    int u = (es[i][1] & ((1 << k) - 1));
    g[v].push_back(u);
    ids[v].push_back(2 * i);
    g[u].push_back(v);
    ids[u].push_back(2 * i + 1);
    s = v;
  }
  for (int i = 0; i < (1 << k); i++) {
    if (sz(g[i]) & 1) {
      return false;
    }
  }
  path.clear();
  dfs(s);
  if (sz(path) != 2 * m) {
    return false;
  }
  printf("%d\n", k);
  for (int i = 0; i < sz(path); i++) {
    printf("%d ", path[i] + 1);
  }
  printf("\n");
  return true;
}

void solve() {
  for (int k = logvs; k >= 0; k--) {
    if (solve1(k)) {
      break;
    }
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