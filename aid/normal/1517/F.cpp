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

const int mod = 998244353;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = 305;
int n;
vector<int> g[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

int d;
int dp[maxn][maxn][2];
int ndp[maxn][2];
int dep[maxn];

void dfs(int v, int p) {
  dep[v] = 0;
  dp[v][0][0] = 1;
  dp[v][0][1] = 1;
  for (int it = 0; it < sz(g[v]); ++it) {
    int u = g[v][it];
    if (u == p) {
      continue;
    }
    dfs(u, v);
    int ndep = min(max(dep[v], dep[u] + 1), d);
    for (int i = 0; i <= ndep; ++i) {
      for (int t = 0; t < 2; ++t) {
        ndp[i][t] = 0;
      }
    }
    for (int x = 0; x <= dep[v]; ++x) {
      for (int xt = 0; xt < 2; ++xt) {
        if (xt && x >= d) {
          continue;
        }
        auto curx = dp[v][x][xt];
        for (int y = 0; y <= dep[u]; ++y) {
          for (int yt = 0; yt < 2; ++yt) {
            if (yt && y >= d) {
              continue;
            }
            auto cury = dp[u][y][yt];
            int z, zt;
            if (xt == yt) {
              zt = xt;
              if (xt) {
                z = max(x, y + 1);
              } else {
                z = min(x, y + 1);
              }
            } else {
              int dist = x + y + 1;
              if (dist <= d) {
                zt = 0;
                z = (xt == 0 ? x : y + 1);
              } else {
                zt = 1;
                z = (xt == 1 ? x : y + 1);
              }
            }
            z = min(z, ndep);
            add(ndp[z][zt], mul(curx, cury));
          }
        }
      }
    }
    for (int i = 0; i <= ndep; ++i) {
      for (int t = 0; t < 2; ++t) {
        dp[v][i][t] = ndp[i][t];
      }
    }
    dep[v] = ndep;
  }
}

void solve() {
  int p2n = 1;
  for (int i = 0; i < n; ++i) {
    p2n = mul(p2n, 2);
  }
  int res = 0;
  for (d = 1; d < n; ++d) {
    dfs(0, -1);
    int cur = p2n;
    for (int i = 0; i <= dep[0]; ++i) {
      add(cur, mod - dp[0][i][0]);
    }
    add(res, cur);
  }
  for (int i = 0; i < n; ++i) {
    res = mul(res, (mod + 1) / 2);
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