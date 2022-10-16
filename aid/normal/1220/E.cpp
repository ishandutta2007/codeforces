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

const int maxn = (int) 2e5 + 5;
int n, m;
int w[maxn];
vector<int> g[maxn];
int s;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  scanf("%d", &s);
  s--;
  return true;
}

long long dp[maxn];
int del[maxn];
int deg[maxn];
vector<int> q;

void solve() {
  q.clear();
  for (int i = 0; i < n; i++) {
    dp[i] = 0;
    del[i] = false;
    deg[i] = sz(g[i]);
    if (i != s && deg[i] == 1) {
      q.push_back(i);
    }
  }
  for (int l = 0; l < sz(q); l++) {
    int v = q[l];
    del[v] = true;
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (del[u]) {
        continue;
      }
      dp[u] = max(dp[u], w[v] + dp[v]);
      deg[u]--;
      if (u != s && deg[u] == 1) {
        q.push_back(u);
      }
    }
  }
  long long mx = 0;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    if (!del[i]) {
      res += w[i];
      mx = max(mx, dp[i]);
    }
  }
  res += mx;
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