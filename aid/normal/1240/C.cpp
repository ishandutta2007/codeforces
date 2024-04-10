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

const int maxn = (int) 5e5 + 5;
int n, k;
vector<pair<int, int>> g[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    v--;
    u--;
    g[v].push_back(make_pair(u, w));
    g[u].push_back(make_pair(v, w));
  }
  return true;
}

long long dp[maxn][2];
vector<long long> a;

void dfs(int v, int p, int pe) {
  long long cur = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, w = g[v][i].second;
    if (u == p) {
      continue;
    }
    dfs(u, v, w);
  }
  a.clear();
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first;
    if (u == p) {
      continue;
    }
    cur += dp[u][0];
    a.push_back(dp[u][1] - dp[u][0]);
  }
  sort(a.begin(), a.end(), greater<long long>());
  dp[v][0] = cur;
  for (int i = 0; i < sz(a) && i < k; i++) {
    dp[v][0] += a[i];
  }
  dp[v][1] = cur + pe;
  for (int i = 0; i < sz(a) && i < k - 1; i++) {
    dp[v][1] += a[i];
  }
  dp[v][1] = max(dp[v][1], dp[v][0]);
}

void solve() {
  dfs(0, -1, 0);
  printf("%lld\n", dp[0][0]);
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