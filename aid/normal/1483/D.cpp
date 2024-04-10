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

const int maxn = 605;
int n, m, q;
int g[maxn][maxn], l[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      g[i][j] = (i == j ? 0 : inf);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      l[i][j] = 0;
    }
  }
  for (int i = 0; i < m; ++i) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    --v;
    --u;
    g[v][u] = w;
    g[u][v] = w;
  }
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    --v;
    --u;
    l[v][u] = w;
    l[u][v] = w;
  }
  return true;
}

int good[maxn][maxn];
long long d[maxn][maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      good[i][j] = false;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      d[i][j] = g[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
      }
    }
  }
  for (int s = 0; s < n; ++s) {
    for (int v = 0; v < n; ++v) {
      long long need = 0;
      for (int t = 0; t < n; ++t) {
        need = max(need, l[s][t] - d[v][t]);
      }
      for (int u = 0; u < n; ++u) {
        if (d[s][u] + g[v][u] <= need) {
          good[v][u] = true;
        }
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (good[i][j] || good[j][i]) {
        ++res;
      }
    }
  }
  printf("%d\n", res);
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