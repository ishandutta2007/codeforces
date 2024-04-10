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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 85;
int n, k, m;
vector< pair<int, int> > g[maxn];

int read() {
  if (scanf("%d%d%d", &n, &k, &m) < 3) {
    return false;
  }
  for (int i = 0; i < n + 2; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    g[v].push_back(make_pair(u, w));
  }
  return true;
}

int dp[maxn][maxn][maxn][2];

void solve() {
  for (int i = 0; i < k; i++) {
    for (int l = 0; l < n + 2; l++) {
      for (int r = 0; r < n + 2; r++) {
        for (int side = 0; side < 2; side++) {
          dp[i][l][r][side] = inf;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[0][0][i][1] = 0;
    dp[0][i][n + 1][0] = 0;
  }
  for (int i = 0; i + 1 < k; i++) {
    for (int l = 0; l < n + 2; l++) {
      for (int r = l + 1; r < n + 2; r++) {
        for (int side = 0; side < 2; side++) {
          auto cur = dp[i][l][r][side];
          if (cur >= inf) {
            continue;
          }
          int v = (!side ? l : r);
          for (int j = 0; j < sz(g[v]); j++) {
            int u = g[v][j].first, w = g[v][j].second;
            if (u <= l || u >= r) {
              continue;
            }
            for (int it = 0; it < 2; it++) {
              auto &nxt = (!it ? dp[i + 1][l][u][1] : dp[i + 1][u][r][0]);
              nxt = min(nxt, cur + w);
            }
          }
        }
      }
    }
  }
  int res = inf;
  for (int l = 0; l < n + 2; l++) {
    for (int r = l + 1; r < n + 2; r++) {
      for (int side = 0; side < 2; side++) {
        res = min(res, dp[k - 1][l][r][side]);
      }
    }
  }
  if (res >= inf) {
    res = -1;
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