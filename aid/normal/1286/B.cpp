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

const int maxn = 2005;
int n;
int c[maxn];
vector<int> g[maxn];
int root;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  root = -1;
  for (int i = 0; i < n; i++) {
    int p;
    scanf("%d%d", &p, &c[i]);
    p--;
    if (p == -1) {
      root = i;
    } else {
      g[p].push_back(i);
    }
  }
  return true;
}

int ts[maxn];
int a[maxn];
vector<int> vs[maxn];

bool dfs(int v) {
  ts[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (!dfs(u)) {
      return false;
    }
    ts[v] += ts[u];
  }
  if (c[v] >= ts[v]) {
    return false;
  }
  vs[v].clear();
  int k = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    for (int j = 0; j < sz(vs[u]); j++) {
      int w = vs[u][j];
      a[w] += k;
      vs[v].push_back(w);
    }
    vs[u].clear();
    k += ts[u];
  }
  for (int i = 0; i < sz(vs[v]); i++) {
    int u = vs[v][i];
    if (a[u] >= c[v]) {
      a[u]++;
    }
  }
  a[v] = c[v];
  vs[v].push_back(v);
  return true;
}

void solve() {
  if (!dfs(root)) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i] + 1);
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