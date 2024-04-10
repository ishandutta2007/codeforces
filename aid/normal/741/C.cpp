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

const int maxn = (int) 2e5 + 5;
int n;
int es[maxn][2];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &es[i][j]);
      es[i][j]--;
    }
  }
  return true;
}

vector<int> g[maxn];
int ans[maxn];

void dfs(int v) {
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (ans[u] != -1) {
      continue;
    }
    ans[u] = (ans[v] ^ 1);
    dfs(u);
  }
}

void solve() {
  for (int i = 0; i < 2 * n; i++) {
    g[i].clear();
    g[i].push_back(i ^ 1);
  }
  for (int i = 0; i < n; i++) {
    int v = es[i][0], u = es[i][1];
    g[v].push_back(u);
    g[u].push_back(v);
  }
  for (int i = 0; i < 2 * n; i++) {
    ans[i] = -1;
  }
  for (int i = 0; i < 2 * n; i++) {
    if (ans[i] == -1) {
      ans[i] = 0;
      dfs(i);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%d ", ans[es[i][j]] + 1);
    }
    printf("\n");
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