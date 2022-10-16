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

const int maxn = (int) 2e5 + 5;
int n;
vector<pair<int, int>> g[maxn];

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
    g[v].push_back(make_pair(i, u));
    g[u].push_back(make_pair(i, v));
  }
  return true;
}

int dp[maxn][2], dp1[maxn];

void dfs(int v, int p) {
  sort(g[v].begin(), g[v].end());
  {
    int d[2][2] = {{1, 0}, {0, 0}};
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i].second;
      if (u == p) {
        int nd[2][2] = {{0, 0}, {0, 0}};
        for (int a = 0; a < 2; a++) {
          auto cur = d[a][0];
          if (a) {
            add(nd[a][0], cur);
          } else {
            add(nd[a][1], cur);
            add(nd[1][0], cur);
          }
        }
        for (int a = 0; a < 2; a++) {
          for (int b = 0; b < 2; b++) {
            d[a][b] = nd[a][b];
          }
        }
        continue;
      }
      dfs(u, v);
      int nd[2][2] = {{0, 0}, {0, 0}};
      for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          auto cur = d[a][b];
          if (a) {
            add(nd[a][b], mul(cur, dp1[u]));
          } else {
            add(nd[a][b], mul(cur, dp[u][0]));
            add(nd[1][b], mul(cur, dp[u][1]));
          }
        }
      }
      for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          d[a][b] = nd[a][b];
        }
      }
    }
    dp[v][0] = d[0][0];
    add(dp[v][0], d[1][0]);
    dp[v][1] = d[0][1];
    add(dp[v][1], d[1][1]);
  }
  {
    int d[2] = {1, 0};
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i].second;
      if (u == p) {
        continue;
      }
      int nd[2] = {0, 0};
      for (int a = 0; a < 2; a++) {
        auto cur = d[a];
        if (a) {
          add(nd[a], mul(cur, dp1[u]));
        } else {
          add(nd[a], mul(cur, dp[u][0]));
          add(nd[1], mul(cur, dp[u][1]));
        }
      }
      for (int a = 0; a < 2; a++) {
        d[a] = nd[a];
      }
    }
    dp1[v] = d[0];
    add(dp1[v], d[1]);
  }
}

void solve() {
  dfs(0, -1);
  printf("%d\n", dp[0][0]);
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