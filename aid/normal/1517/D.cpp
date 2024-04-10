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

const int gox[] = {1, 0, -1, 0};
const int goy[] = {0, 1, 0, -1};

const int maxn = 505;
int n, m, k;
int g[maxn][maxn][4];

bool read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j + 1 < m; ++j) {
      int w;
      scanf("%d", &w);
      g[i][j][1] = w;
      g[i][j + 1][3] = w;
    }
  }
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int w;
      scanf("%d", &w);
      g[i][j][0] = w;
      g[i + 1][j][2] = w;
    }
  }
  return true;
}

bool inside(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

int dp[maxn][maxn], ndp[maxn][maxn];

void solve() {
  if (k & 1) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        printf("-1 ");
      }
      printf("\n");
    }
    return;
  }
  k /= 2;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      dp[i][j] = 0;
    }
  }
  for (int it = 0; it < k; ++it) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ndp[i][j] = inf;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        auto cur = dp[i][j];
        for (int dir = 0; dir < 4; ++dir) {
          int ni = i + gox[dir], nj = j + goy[dir];
          if (!inside(ni, nj)) {
            continue;
          }
          auto &nxt = ndp[ni][nj];
          nxt = min(nxt, cur + g[i][j][dir]);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        dp[i][j] = ndp[i][j];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d ", dp[i][j] * 2);
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