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
int deg[maxn];
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    deg[i] = 0;
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    deg[v]++;
    deg[u]++;
    if (v > u) {
      swap(v, u);
    }
    g[v].push_back(u);
  }
  return true;
}

void solve() {
  long long res = 0;
  for (int i = 0; i < n; i++) {
    res += (long long) sz(g[i]) * (deg[i] - sz(g[i]));
  }
  printf("%lld\n", res);
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; qq++) {
    int v;
    scanf("%d", &v);
    v--;
    res -= (long long) sz(g[v]) * (deg[v] - sz(g[v]));
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      res -= (long long) sz(g[u]) * (deg[u] - sz(g[u]));
      g[u].push_back(v);
      res += (long long) sz(g[u]) * (deg[u] - sz(g[u]));
    }
    g[v].clear();
    printf("%lld\n", res);
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