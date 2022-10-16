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

const int maxn = 105, sigma = 26;
int n, m;
vector< pair<int, int> > g[maxn];
char tmp[10];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d%s", &v, &u, tmp);
    v--;
    u--;
    g[v].push_back(make_pair(u, tmp[0] - 'a'));
  }
  return true;
}

int dp[sigma][maxn][maxn];

int get(int c, int v, int u) {
  auto &cur = dp[c][v][u];
  if (cur != -1) {
    return cur;
  }
  cur = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int nv = g[v][i].first, nc = g[v][i].second;
    if (nc < c) {
      continue;
    }
    if (!get(nc, u, nv)) {
      return cur = 1;
    }
  }
  return cur;
}

void solve() {
  for (int i = 0; i < sigma; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        dp[i][j][k] = -1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf(get(0, i, j) ? "A" : "B");
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