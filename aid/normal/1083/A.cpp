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

const int maxn = (int) 3e5 + 5;
int n;
int w[maxn];
vector<pair<int, int>> g[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
    scanf("%d", &w[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u, c;
    scanf("%d%d%d", &v, &u, &c);
    v--;
    u--;
    g[v].push_back(make_pair(u, c));
    g[u].push_back(make_pair(v, c));
  }
  return true;
}

long long dp[maxn];

void getDp(int v, int p) {
  dp[v] = w[v];
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, c = g[v][i].second;
    if (u == p) {
      continue;
    }
    getDp(u, v);
    if (dp[u] >= c) {
      dp[v] = max(dp[v], dp[u] - c + w[v]);
    }
  }
}

long long res;

void dfs(int v, int p, long long dpup) {
  res = max(res, dpup);
  pair<long long, int> mx[2] = {make_pair(dpup, p), make_pair(-1ll, -1)};
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, c = g[v][i].second;
    if (u == p) {
      continue;
    }
    if (dp[u] < c) {
      continue;
    }
    pair<long long, int> cur = make_pair(dp[u] - c + w[v], u);
    if (cur > mx[0]) {
      mx[1] = mx[0];
      mx[0] = cur;
    } else if (cur > mx[1]) {
      mx[1] = cur;
    }
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, c = g[v][i].second;
    if (u == p) {
      continue;
    }
    long long cur = (mx[0].second == u ? mx[1].first : mx[0].first);
    if (cur < c) {
      cur = w[u];
    } else {
      cur = cur - c + w[u];
    }
    dfs(u, v, cur);
  }
}

void solve() {
  getDp(0, -1);
  res = 0;
  dfs(0, -1, w[0]);
  printf("%lld\n", res);
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