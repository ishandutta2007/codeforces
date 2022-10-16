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

const int maxn = (int) 3e5 + 5;
int n;
vector<int> g[maxn];

bool read() {
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

int dp[maxn][3];

void dfs(int v, int p) {
  dp[v][0] = 0;
  dp[v][1] = 0;
  dp[v][2] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs(u, v);
    int ndp[3] = {0, 0, 0};
    {
      int tomul = dp[u][1];
      add(tomul, dp[u][2]);
      for (int j = 0; j < 3; j++) {
        add(ndp[j], mul(dp[v][j], tomul));
      }
    }
    {
      for (int j = 0; j < 3; j++) {
        add(ndp[j & 1], mul(dp[v][j], dp[u][1]));
      }
      int x = dp[u][0];
      add(x, dp[u][2]);
      int y = dp[v][0];
      add(y, dp[v][2]);
      add(ndp[1], mul(x, y));
    }
    for (int j = 0; j < 3; j++) {
      dp[v][j] = ndp[j];
    }
  }
}

void solve() {
  dfs(0, -1);
  int res = dp[0][1];
  add(res, dp[0][2]);
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