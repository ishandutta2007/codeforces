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

int gcd(int a, int b) {
  return (b ? gcd(b, a % b) : a);
}

const int maxn = (int) 1e5 + 5, maxd = 55;
int n, m, d;
vector<int> g[maxn], gr[maxn];
long long msks[maxn];
char tmp[maxd];

bool read() {
  if (scanf("%d%d%d", &n, &m, &d) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
    gr[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    gr[u].push_back(v);
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    auto &cur = msks[i];
    cur = 0;
    for (int j = 0; j < d; j++) {
      if (tmp[j] == '1') {
        cur |= (1ll << j);
      }
    }
  }
  return true;
}

int used[maxn];
vector<int> p;
int cid[maxn];
int ds[maxn];

void dfs0(int v) {
  used[v] = true;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (!used[u]) { 
      dfs0(u);
    }
  }
  p.push_back(v);
}

void dfs1(int v, int curc) {
  cid[v] = curc;
  for (int i = 0; i < sz(gr[v]); i++) {
    int u = gr[v][i];
    if (cid[u] == -1) {
      ds[u] = ds[v] - 1;
      dfs1(u, curc);
    }
  }
}

int gs[maxn];
int cnt[maxn][maxd];
vector<pair<int, int>> gc[maxn];
int dp[maxn][maxd];

void solve() {
  for (int i = 0; i < n; i++) {
    used[i] = false;
    cid[i] = -1;
  }
  p.clear();
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs0(i);
    }
  }
  reverse(p.begin(), p.end());
  int cs = 0;
  for (int i = 0; i < n; i++) {
    int v = p[i];
    if (cid[v] == -1) {
      ds[v] = 0;
      dfs1(v, cs++);
    }
  }
  for (int i = 0; i < cs; i++) {
    gs[i] = d;
    for (int j = 0; j < d; j++) {
      cnt[i][j] = 0;
    }
    gc[i].clear();
  }
  for (int v = 0; v < n; v++) {
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (cid[u] != cid[v]) {
        continue;
      }
      int curc = cid[v];
      int x = abs(ds[u] - ds[v] - 1);
      gs[curc] = gcd(gs[curc], x);
    }
  }
  for (int v = 0; v < n; v++) {
    ds[v] = ((ds[v] % gs[cid[v]]) + gs[cid[v]]) % gs[cid[v]];
  }
  for (int v = 0; v < n; v++) {
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (cid[u] != cid[v]) {
        gc[cid[v]].push_back(make_pair(cid[u], ((ds[v] + 1 - ds[u]) % d + d) % d));
      }
    }
    int gg = gs[cid[v]];
    for (int i = 0; i < d; i++) {
      if (msks[v] & (1ll << i)) {
        msks[v] |= (1ll << (i % gg));
      }
    }
    for (int i = 0; i < gg; i++) {
      int x = (i + gg - ds[v]) % gg;
      if (msks[v] & (1ll << i)) {
        cnt[cid[v]][x]++;
      }
    }
  }
  memset(dp, -1, sizeof(dp));
  dp[cid[0]][(gs[cid[0]] - ds[0]) % gs[cid[0]]] = 0;
  int res = 0;
  for (int v = 0; v < cs; v++) {
    for (int i = 0; i < d; i++) {
      int ii = i % gs[v];
      dp[v][ii] = max(dp[v][ii], dp[v][i]);
    }
    for (int i = 0; i < gs[v]; i++) {
      if (dp[v][i] >= 0) {
        dp[v][i] += cnt[v][i];
      }
    }
    for (int i = 0; i < d; i++) {
      int ii = i % gs[v];
      dp[v][i] = dp[v][ii];
    }
    for (int i = 0; i < d; i++) {
      auto &cur = dp[v][i];
      if (cur < 0) {
        continue;
      }
      res = max(res, cur);
      for (int j = 0; j < sz(gc[v]); j++) {
        int u = gc[v][j].first, w = gc[v][j].second;
        auto &nxt = dp[u][(i + w) % d];
        nxt = max(nxt, cur);
      }
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