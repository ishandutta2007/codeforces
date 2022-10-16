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
vector<int> g[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    p--;
    g[p].push_back(i);
  }
  return true;
}

int dp[maxn][2];

void dfs(int v) {
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    dfs(u);
  }
  {
    int dpv[3] = {1, 0, 0};
    for (int it = 0; it < sz(g[v]); it++) {
      int u = g[v][it];
      int ndp[3] = {0, 0, 0};
      for (int i = 0; i < 3; i++) {
        auto cur = dpv[i];
        if (!cur) {
          continue;
        }
        add(ndp[i], mul(dpv[i], dp[u][0]));
        int ni = min(2, i + 1);
        add(ndp[ni], mul(dpv[i], dp[u][1]));
      }
      for (int i = 0; i < 3; i++) {
        dpv[i] = ndp[i];
      }
    }
    dp[v][0] = dpv[0];
    add(dp[v][0], dpv[2]);
  }
  if (g[v].empty()) {
    dp[v][1] = 1;
  } else {
    int dpv[2] = {1, 0};
    for (int it = 0; it < sz(g[v]); it++) {
      int u = g[v][it];
      int ndp[2] = {0, 0};
      for (int i = 0; i < 2; i++) {
        auto cur = dpv[i];
        if (!cur) {
          continue;
        }
        add(ndp[i], mul(dpv[i], dp[u][0]));
        int ni = min(1, i + 1);
        add(ndp[ni], mul(dpv[i], dp[u][1]));
      }
      for (int i = 0; i < 2; i++) {
        dpv[i] = ndp[i];
      }
    }
    dp[v][1] = dpv[1];
  }
}

void solve() {
  dfs(0);
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