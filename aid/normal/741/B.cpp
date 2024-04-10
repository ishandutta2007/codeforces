#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e3 + 5;
int n, m, w;
vector<int> g[maxn];
int a[maxn], b[maxn];

int read() {
  if (scanf("%d%d%d", &n, &m, &w) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
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
  return true;
}

int cs;
int ca[maxn], cb[maxn];
vector< pair<int, int> > cv[maxn];
int used[maxn];

void dfs(int v, int c) {
  ca[c] += a[v];
  cb[c] += b[v];
  cv[c].push_back(make_pair(a[v], b[v]));
  used[v] = true;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (!used[u]) {
      dfs(u, c);
    }
  }
}

int dp[maxn][maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    cv[i].clear();
    ca[i] = 0;
    cb[i] = 0;
    used[i] = false;
  }
  cs = 0;
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    dfs(i, cs++);
  }
  for (int i = 0; i <= w; i++) {
    dp[0][i] = 0;
  }
  for (int i = 0; i < cs; i++) {
    for (int j = 0; j <= w; j++) {
      dp[i + 1][j] = dp[i][j];
    }
    for (int j = 0; j <= w; j++) {
      if (j + ca[i] <= w) {
        dp[i + 1][j + ca[i]] = max(dp[i + 1][j + ca[i]], dp[i][j] + cb[i]);
      }
      for (int k = 0; k < sz(cv[i]); k++) {
        int aa = cv[i][k].first, bb = cv[i][k].second;
        if (j + aa <= w) {
          dp[i + 1][j + aa] = max(dp[i + 1][j + aa], dp[i][j] + bb);
        }
      }
    }
  }
  int res = 0;
  for (int i = 0; i <= w; i++) {
    res = max(res, dp[cs][i]);
  }
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}