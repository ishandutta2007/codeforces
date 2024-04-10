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

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = 105;
int c[maxn][maxn];

void precalc() {
  for (int i = 0; i < maxn; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = c[i - 1][j - 1];
      add(c[i][j], c[i - 1][j]);
    }
  }
}

int n;
vector<int> g[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

int dp[maxn][maxn][maxn];
int ndp[maxn][maxn];
int ts[maxn];

void dfs(int v, int p) {
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs(u, v);
  }
  dp[v][0][1] = 1;
  ts[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    for (int k0 = ts[v] - 1; k0 >= 0; k0--) {
      for (int c0 = ts[v]; c0 >= 1; c0--) {
        auto a = dp[v][k0][c0];
        if (!a) {
          continue;
        }
        for (int k1 = ts[u] - 1; k1 >= 0; k1--) {
          for (int c1 = ts[u]; c1 >= 1; c1--) {
            auto b = dp[u][k1][c1];
            if (!b) {
              continue;
            }
            add(dp[v][k0 + k1][c0 + c1], mul(a, b));
            add(dp[v][k0 + k1 + 1][c0], mul(a, mul(b, c1)));
          }
        }
        dp[v][k0][c0] = 0;
      }
    }
    ts[v] += ts[u];
  }
}

int cnt[maxn];

void solve() {
  memset(dp, 0, sizeof(dp));
  memset(cnt, 0, sizeof(cnt));
  dfs(0, -1);
  cnt[0] = 1;
  for (int k = 1; k < n; k++) {
    int val = 0;
    for (int i = 1; i <= n; i++) {
      add(val, mul(dp[0][k][i], i));
    }
    for (int i = 0; i < k - 1; i++) {
      val = mul(val, n);
    }
    cnt[k] = val;
    for (int eq = 1; eq <= k; eq++) {
      add(cnt[k], mod - mul(cnt[k - eq], c[n - 1 - k + eq][eq]));
    }
  }
  for (int k = 0; k < n; k++) {
    printf("%d ", cnt[n - 1 - k]);
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