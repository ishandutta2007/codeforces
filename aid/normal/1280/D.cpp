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

const int maxn = 3005;
int n, m;
int a[maxn];
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    a[i] = 0;
    g[i].clear();
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[i] -= x;
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[i] += x;
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

int ts[maxn];
pair<int, long long> dp[maxn][maxn];
pair<int, long long> ndp[maxn];

void dfs(int v, int p) {
  ts[v] = 1;
  dp[v][1] = make_pair(0, (long long) a[v]);
  for (int it = 0; it < sz(g[v]); it++) {
    int u = g[v][it];
    if (u == p) {
      continue;
    }
    dfs(u, v);
    int kv = min(ts[v], m) + 1, ku = min(ts[u], m) + 1;
    int kk = min(ts[v] + ts[u], m) + 1;
    for (int i = 1; i < kk; i++) {
      ndp[i] = make_pair(-1, -1ll);
    }
    for (int i = 1; i < kv; i++) {
      for (int j = 1; j < ku && i + j - 1 < kk; j++) {
        if (i + j < kk) {
          ndp[i + j] = max(ndp[i + j], make_pair(dp[v][i].first + dp[u][j].first + (dp[u][j].second > 0), dp[v][i].second));
        }
        ndp[i + j - 1] = max(ndp[i + j - 1], make_pair(dp[v][i].first + dp[u][j].first, dp[v][i].second + dp[u][j].second));
      }
    }
    for (int i = 1; i < kk; i++) {
      dp[v][i] = ndp[i];
    }
    ts[v] += ts[u];
  }
}

void solve() {
  dfs(0, -1);
  printf("%d\n", dp[0][m].first + (dp[0][m].second > 0));
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}