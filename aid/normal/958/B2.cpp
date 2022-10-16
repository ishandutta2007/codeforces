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
int del[maxn];
int deg[maxn];
vector< pair<int, int> > g[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    del[i] = false;
    deg[i] = 0;
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(make_pair(u, 1));
    g[u].push_back(make_pair(v, 1));
    deg[v]++;
    deg[u]++;
  }
  return true;
}

int ans[maxn];
int llen[maxn];
int lto[maxn];
set<pair<int, int>> lvs;

void delVertex(int v) {
  del[v] = true;
  int a = -1, b = -1;
  int len = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first;
    if (del[u]) {
      continue;
    }
    len += g[v][i].second;
    if (a == -1) {
      a = u;
    } else {
      b = u;
    }
  }
  if (deg[a] == 1) {
    lvs.erase(make_pair(llen[a], a));
    llen[a] = len;
    lto[a] = b;
    lvs.insert(make_pair(llen[a], a));
  }
  if (deg[b] == 1) {
    lvs.erase(make_pair(llen[b], b));
    llen[b] = len;
    lto[b] = a;
    lvs.insert(make_pair(llen[b], b));
  }
  g[a].push_back(make_pair(b, len));
  g[b].push_back(make_pair(a, len));
}

void solve() {
  for (int i = 0; i < n; i++) {
    if (deg[i] == 2) {
      delVertex(i);
    }
  }
  lvs.clear();
  for (int i = 0; i < n; i++) {
    if (deg[i] == 1) {
      for (int j = 0; j < sz(g[i]); j++) {
        int u = g[i][j].first;
        if (del[u]) {
          continue;
        }
        llen[i] = g[i][j].second;
        lto[i] = g[i][j].first;
        break;
      }
      lvs.insert(make_pair(llen[i], i));
    }
  }
  for (int i = sz(lvs); i <= n; i++) {
    ans[i] = n;
  }
  int cur = n;
  while (sz(lvs) > 2) {
    int v = lvs.begin()->second;
    lvs.erase(lvs.begin());
    cur -= llen[v];
    ans[sz(lvs)] = cur;
    del[v] = true;
    int u = lto[v];
    deg[u]--;
    if (deg[u] == 2) {
      delVertex(u);
    }
  }
  ans[1] = 1;
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
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