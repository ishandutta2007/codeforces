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

const int maxn = (int) 5e5 + 5;
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

int dp[maxn][2][2];

void dfs(int v, int p) {
  dp[v][0][0] = 1;
  dp[v][0][1] = 0;
  dp[v][1][0] = 0;
  dp[v][1][1] = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs(u, v);
    int ndp[2][2] = {{0, 0}, {0, 0}};
    for (int vt = 0; vt < 2; vt++) {
      for (int ut = 0; ut < 2; ut++) {
        if (!vt && !ut) {
          add(ndp[1][0], mul(dp[v][vt][0], dp[u][ut][0]));
          add(ndp[1][1], mul(dp[v][vt][0], dp[u][ut][1]));
          add(ndp[1][1], mul(dp[v][vt][1], dp[u][ut][0]));
          add(ndp[1][1], mul(dp[v][vt][0], dp[u][ut][0]));
        } else {
          add(ndp[vt][0], mul(dp[v][vt][0], dp[u][ut][0]));
          add(ndp[vt][1], mul(dp[v][vt][0], dp[u][ut][1]));
          add(ndp[vt][1], mul(dp[v][vt][1], dp[u][ut][0]));
        }
        add(ndp[vt][0], mul(dp[v][vt][0], dp[u][ut][0]));
        add(ndp[vt][1], mul(dp[v][vt][0], dp[u][ut][1]));
        add(ndp[vt][1], mul(dp[v][vt][1], dp[u][ut][0]));
      }
    }
    for (int t = 0; t < 2; t++) {
      for (int j = 0; j < 2; j++) {
        dp[v][t][j] = ndp[t][j];
      }
    }
  }
}

void solve() {
  dfs(0, -1);
  int res = dp[0][0][1];
  add(res, dp[0][1][1]);
  res = mul(res, 2);
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