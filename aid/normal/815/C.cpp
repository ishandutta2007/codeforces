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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 5005;
int n, b;
int c[maxn], d[maxn];
vector<int> g[maxn];

int read() {
  if (scanf("%d%d", &n, &b) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &c[i], &d[i]);
    if (i >= 1) {
      int p;
      scanf("%d", &p);
      p--;
      g[p].push_back(i);
    }
  }
  return true;
}

int ts[maxn];
int dp[2][maxn][maxn];
vector<int> srt[maxn];

vector<int> tmp;

void dfs(int v) {
  ts[v] = 1;
  int maxu = -1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    dfs(u);
    ts[v] += ts[u];
    if (maxu == -1 || ts[maxu] < ts[u]) {
      maxu = u;
    }
  }
  srt[v].clear();
  if (maxu == -1) {
    srt[v].push_back(c[v]);
    dp[0][v][0] = 0;
    dp[0][v][1] = c[v];
    dp[1][v][0] = 0;
    dp[1][v][1] = d[v];
    return;
  }
  {
    srt[v] = srt[maxu];
    int pos = 0;
    while (pos < sz(srt[v]) && srt[v][pos] < c[v]) {
      pos++;
    }
    srt[v].insert(srt[v].begin() + pos, c[v]);
  }
  for (int i = 0; i <= ts[v]; i++) {
    dp[1][v][i] = b + 1;
  }
  dp[1][v][0] = 0;
  for (int i = 0; i <= ts[maxu]; i++) {
    dp[1][v][i + 1] = min(b + 1, dp[1][maxu][i] + d[v]);
  }
  vector< pair<int, int> > cs(sz(g[v]));
  for (int i = 0; i < sz(g[v]); i++) {
    cs[i] = make_pair(ts[g[v][i]], g[v][i]);
  }
  sort(cs.begin(), cs.end(), greater< pair<int, int> >());
  for (int it = 0; it < sz(g[v]); it++) {
    int u = cs[it].second;
    if (u == maxu) {
      continue;
    }
    int k = sz(srt[v]);
    {
      tmp = srt[v];
      srt[v].resize(sz(srt[v]) + sz(srt[u]));
      merge(tmp.begin(), tmp.end(), srt[u].begin(), srt[u].end(), srt[v].begin());
    }
    for (int i = k; i >= 1; i--) {
      for (int j = 1; j <= ts[u]; j++) {
        auto &nxt = dp[1][v][i + j];
        nxt = min(nxt, dp[1][v][i] + dp[1][u][j]);
      }
    }
  }
  dp[0][v][0] = 0;
  for (int i = 0; i < ts[v]; i++) {
    dp[0][v][i + 1] = min(b + 1, dp[0][v][i] + srt[v][i]);
  }
  for (int i = 0; i <= ts[v]; i++) {
    dp[1][v][i] = min(dp[1][v][i], dp[0][v][i]);
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    d[i] = c[i] - d[i];
  }
  dfs(0);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (dp[1][0][i] <= b) {
      res = i;
    }
  }
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