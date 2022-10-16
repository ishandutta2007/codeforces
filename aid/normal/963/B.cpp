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

const int maxn = (int) 2e5 + 5;
int n;
vector<int> g[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n; i++) {
    int p;
    scanf("%d", &p);
    p--;
    if (p >= 0) {
      g[p].push_back(i);
      g[i].push_back(p);
    }
  }
  return true;
}

int dp[maxn][2];

void dfs(int v, int p) {
  dp[v][0] = false;
  dp[v][1] = false;
  bool ok = true;
  bool found = false;
  int cnt = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs(u, v);
    if (dp[u][0] && dp[u][1]) {
      found = true;
    }
    if (!dp[u][0] && !dp[u][1]) {
      ok = false;
    }
    cnt += dp[u][0];
  }
  if (!ok) {
    return;
  }
  if (found) {
    dp[v][0] = true;
    dp[v][1] = true;
    return;
  }
  dp[v][cnt & 1] = true;
}

void getAns(int v, int p, int t) {
  assert(dp[v][t]);
  int cnt = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    cnt += dp[u][0];
  }
  if ((cnt & 1) == t) {
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (u == p) {
        continue;
      }
      if (!dp[u][0]) {
        getAns(u, v, 1);
      }
    }
    printf("%d\n", v + 1);
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (u == p) {
        continue;
      }
      if (dp[u][0]) {
        getAns(u, v, 0);
      }
    }
  } else {
    bool found = false;
    int id = -1;
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (u == p) {
        continue;
      }
      if (!found && dp[u][0] && dp[u][1]) {
        found = true;
        id = u;
        getAns(u, v, 1);
      }
      if (!dp[u][0]) {
        getAns(u, v, 1);
      }
    }
    assert(found);
    printf("%d\n", v + 1);
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (u == p || u == id) {
        continue;
      }
      if (dp[u][0]) {
        getAns(u, v, 0);
      }
    }
  }
}

void solve() {
  dfs(0, -1);
  if (dp[0][0]) {
    printf("YES\n");
    getAns(0, -1, 0);
  } else {
    printf("NO\n");
  }
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