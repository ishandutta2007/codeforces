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
int n, m;
int g[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      g[i][j] = inf;
    }
  }
  for (int i = 0; i < m; ++i) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    g[v][u] = w;
  }
  return true;
}

int d[maxn];
int used[maxn];
int a[maxn];

void solve() {
  for (int s = 0; s < n; ++s) {
    for (int v = 0; v < n; ++v) {
      d[v] = inf;
      used[v] = false;
    }
    d[s] = 0;
    for (int it = 0; it < n; ++it) {
      int v = -1;
      for (int i = 0; i < n; ++i) {
        if (!used[i] && (v == -1 || d[i] < d[v])) {
          v = i;
        }
      }
      used[v] = true;
      for (int i = 0; i < n; ++i) {
        a[(i + d[v]) % n] = g[v][i];
      }
      int dist = a[0];
      for (int i = 1; i < n; ++i) {
        dist = min(dist, a[i] + (n - i));
      }
      d[0] = min(d[0], d[v] + dist);
      for (int u = 1; u < n; ++u) {
        ++dist;
        if (a[u] < inf) {
          dist = min(dist, a[u]);
        }
        d[u] = min(d[u], d[v] + dist);
      }
    }
    for (int v = 0; v < n; ++v) {
      printf("%d ", d[v]);
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