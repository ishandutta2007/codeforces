#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef double ld;

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

const int maxn = 5005, maxm = (int) 1e5 + 5;
int m, n;
int a[maxm];
int ls[maxn], rs[maxn];
ld ps[maxn];

bool read() {
  if (scanf("%d%d", &m, &n) < 2) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    double p;
    scanf("%d%d%lf", &ls[i], &rs[i], &p);
    ls[i]--;
    ps[i] = p;
  }
  return true;
}

int mx;
int ms[maxn];
vector<pair<int, int>> g[maxn];
ld dp[maxn][2 * maxn];

void dfs(int v) {
  sort(g[v].begin(), g[v].end());
  int pos = ls[v];
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].second;
    while (pos < ls[u]) {
      ms[v] = max(ms[v], a[pos]);
      pos++;
    }
    dfs(u);
    pos = rs[u];
  }
  while (pos < rs[v]) {
    ms[v] = max(ms[v], a[pos]);
    pos++;
  }
  for (int x = -maxn + 1; x < maxn; x++) {
    auto &cur = dp[v][maxn + x];
    if (ms[v] > mx + x) {
      cur = 0;
      continue;
    }
    ld cur0 = 1 - ps[v], cur1 = ps[v];
    if (ms[v] + 1 > mx + x) {
      cur1 = 0;
    }
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i].second;
      cur0 *= dp[u][maxn + x];
      cur1 *= dp[u][maxn + x - 1];
    }
    cur = cur0 + cur1;
  }
}

void solve() {
  mx = 0;
  for (int i = 0; i < m; i++) {
    mx = max(mx, a[i]);
  }
  for (int i = 0; i <= n; i++) {
    ms[i] = 0;
    g[i].clear();
  }
  ls[n] = 0;
  rs[n] = m;
  ps[n] = 0;
  for (int v = 0; v < n; v++) {
    int pr = n;
    for (int u = 0; u < n; u++) {
      if (ls[u] == ls[v] && rs[u] == rs[v] && u >= v) {
        continue;
      }
      if ((ls[u] <= ls[v] && rs[v] <= rs[u]) && (ls[pr] <= ls[u] && rs[u] <= rs[pr])) {
        pr = u;
      }
    }
    g[pr].push_back(make_pair(ls[v], v));
  }
  dfs(n);
  ld res = mx;
  for (int x = 0; x < maxn; x++) {
    res += 1 - dp[n][maxn + x];
  }
  printf("%.12f\n", (double) res);
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