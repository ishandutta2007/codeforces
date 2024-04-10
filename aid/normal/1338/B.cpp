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
int n;
vector<int> g[maxn];

bool read() {
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

int col[maxn];

void dfs(int v, int p) {
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    col[u] = (col[v] ^ 1);
    dfs(u, v);
  }
}

int used[maxn];

void solve() {
  col[0] = 0;
  dfs(0, -1);
  int cols = 0;
  for (int v = 0; v < n; v++) {
    if (sz(g[v]) != 1) {
      continue;
    }
    cols |= (1 << col[v]);
  }
  int mn = (cols == 3 ? 3 : 1);
  int mx = n - 1;
  for (int v = 0; v < n; v++) {
    used[v] = false;
  }
  for (int v = 0; v < n; v++) {
    if (sz(g[v]) != 1) {
      continue;
    }
    int u = g[v][0];
    if (used[u]) {
      mx--;
    }
    used[u] = true;
  }
  printf("%d %d\n", mn, mx);
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