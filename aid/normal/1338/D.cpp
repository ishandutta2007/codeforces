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

const int maxn = (int) 1e5 + 5;
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

int dp[maxn][2];

void dfs0(int v, int p) {
  auto &cur0 = dp[v][0];
  auto &cur1 = dp[v][1];
  cur0 = 0;
  cur1 = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs0(u, v);
    cur0 = max(cur0, max(dp[u][0], dp[u][1]));
    cur1 = max(cur1, dp[u][0]);
  }
  int deg = sz(g[v]) - (p != -1);
  cur0 += max(0, deg - 1);
  cur1++;
}

int res;

void update(int d[2][2], int t, int x) {
  if (d[t][0] < x) {
    d[t][1] = d[t][0];
    d[t][0] = x;
  } else if (d[t][1] < x) {
    d[t][1] = x;
  }
}

void dfs1(int v, int p, int up0, int up1) {
  int d[2][2] = {{0, 0}, {0, 0}};
  update(d, 0, max(up0, up1));
  update(d, 1, up0);
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    update(d, 0, max(dp[u][0], dp[u][1]));
    update(d, 1, dp[u][0]);
  }
  res = max(res, d[1][0] + 1);
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    int d0 = (d[0][0] == max(dp[u][0], dp[u][1]) ? d[0][1] : d[0][0]);
    int d1 = (d[1][0] == dp[u][0] ? d[1][1] : d[1][0]);
    d0 += max(0, sz(g[v]) - 2);
    d1++;
    dfs1(u, v, d0, d1);
  }
}

void solve() {
  dfs0(0, -1);
  res = dp[0][1];
  dfs1(0, -1, 0, 0);
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