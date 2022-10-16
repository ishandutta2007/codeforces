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

const int maxn = 70;
int logn, n;
ld pr[maxn][maxn];

int read() {
  if (scanf("%d", &logn) < 1) {
    return false;
  }
  n = (1 << logn);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int p;
      scanf("%d", &p);
      pr[i][j] = (ld) p / 100;
    }
  }
  return true;
}

ld p[4 * maxn][maxn];
ld dp[4 * maxn][maxn];
ld dp1[4 * maxn];

void dfs(int v, int tl, int tr) {
  if (tl == tr - 1) {
    p[v][tl] = 1;
    dp[v][tl] = 0;
    dp1[v] = 0;
    return;
  }
  int tm = (tl + tr) / 2;
  dfs(2 * v, tl, tm);
  dfs(2 * v + 1, tm, tr);
  dp1[v] = 0;
  for (int x = tl; x < tr; x++) {
    {
      auto &pcur = p[v][x];
      pcur = 0;
      for (int xl = tl; xl < tm; xl++) {
        for (int xr = tm; xr < tr; xr++) {
          if (xl != x && xr != x) {
            continue;
          }
          int a = xl, b = xr;
          int va = 2 * v, vb = 2 * v + 1;
          for (int it = 0; it < 2; it++) {
            if (a == x) {
              pcur += p[va][a] * p[vb][b] * pr[a][b];
            }
            swap(a, b);
            swap(va, vb);
          }
        }
      }
    }
    {
      auto &cur = dp[v][x];
      if (x < tm) {
        cur = p[v][x] * (tr - tl) / 2 + dp[2 * v][x] + dp1[2 * v + 1];
      } else {
        cur = p[v][x] * (tr - tl) / 2 + dp1[2 * v]+ dp[2 * v + 1][x];
      }
      dp1[v] = max(dp1[v], cur);
    }
  }
}

void solve() {
  dfs(1, 0, n);
  printf("%.12f\n", (double) dp1[1]);
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