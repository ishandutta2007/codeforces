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

const int maxn = 55;
int n, m;
int g[maxn][maxn];
char tmp[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    for (int j = 0; j < m; j++) {
      g[i][j] = (tmp[j] == '#');
    }
  }
  return true;
}

int used[2][maxn];
int g0[maxn][maxn];
vector<int> vs[2];

void solve() {
  for (int i = 0; i < n; i++) {
    used[0][i] = false;
  }
  for (int i = 0; i < m; i++) {
    used[1][i] = false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      g0[i][j] = false;
    }
  }
  for (int v = 0; v < n; v++) {
    if (used[0][v]) {
      continue;
    }
    int u;
    for (u = 0; u < m; u++) {
      if (g[v][u]) {
        break;
      }
    }
    if (u >= m) {
      continue;
    }
    vs[0].clear();
    vs[1].clear();
    for (int i = 0; i < n; i++) {
      if (g[i][u]) {
        if (used[0][i]) {
          printf("No\n");
          return;
        }
        vs[0].push_back(i);
      }
    }
    for (int i = 0; i < m; i++) {
      if (g[v][i]) {
        if (used[1][i]) {
          printf("No\n");
          return;
        }
        vs[1].push_back(i);
      }
    }
    for (int i = 0; i < sz(vs[0]); i++) {
      for (int j = 0; j < sz(vs[1]); j++) {
        if (!g[vs[0][i]][vs[1][j]]) {
          printf("No\n");
          return;
        }
        g0[vs[0][i]][vs[1][j]] = true;
      }
    }
    for (int t = 0; t < 2; t++) {
      for (int i = 0; i < sz(vs[t]); i++) {
        used[t][vs[t][i]] = true;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g0[i][j] != g[i][j]) {
        printf("No\n");
        return;
      }
    }
  }
  printf("Yes\n");
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