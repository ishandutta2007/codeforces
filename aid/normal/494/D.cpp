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

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = (int) 1e5 + 5;
int n;
vector<pair<int, int>> g[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
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

const int logn = 20;
int tin[maxn], tout[maxn], t;
int ps[maxn][logn];
int dep[maxn];
int dp[maxn][2][3];

void dfs(int v, int p) {
  tin[v] = t++;
  ps[v][0] = (p == -1 ? v : p);
  for (int i = 1; i < logn; i++) {
    ps[v][i] = ps[ps[v][i - 1]][i - 1];
  }
  auto dpv = dp[v][0];
  dpv[0] = 1;
  dpv[1] = 0;
  dpv[2] = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, w = g[v][i].second;
    if (u == p) {
      continue;
    }
    dep[u] = dep[v];
    add(dep[u], w);
    dfs(u, v);
    auto dpu = dp[u][0];
    add(dpv[0], dpu[0]);
    add(dpv[1], dpu[1]);
    add(dpv[1], mul(w, dpu[0]));
    add(dpv[2], dpu[2]);
    add(dpv[2], mul(2, mul(w, dpu[1])));
    add(dpv[2], mul(mul(w, w), dpu[0]));
  }
  tout[v] = t;
}

void dfs1(int v, int p, vector<int> up) {
  auto dpv = dp[v][1];
  dpv[0] = up[0];
  dpv[1] = up[1];
  dpv[2] = up[2];
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, w = g[v][i].second;
    if (u == p) {
      continue;
    }
    auto dpu = dp[u][0];
    vector<int> nup = {dp[v][0][0], dp[v][0][1], dp[v][0][2]};
    add(nup[0], mod - dpu[0]);
    add(nup[1], mod - dpu[1]);
    add(nup[1], mod - mul(w, dpu[0]));
    add(nup[2], mod - dpu[2]);
    add(nup[2], mod - mul(2, mul(w, dpu[1])));
    add(nup[2], mod - mul(mul(w, w), dpu[0]));
    add(nup[0], up[0]);
    add(nup[1], up[1]);
    add(nup[2], up[2]);
    add(nup[2], mul(2, mul(w, nup[1])));
    add(nup[2], mul(mul(w, w), nup[0]));
    add(nup[1], mul(w, nup[0]));
    dfs1(u, v, nup);
  }
}

bool anc(int v, int u) {
  return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int lca(int v, int u) {
  if (anc(v, u)) {
    return v;
  }
  if (anc(u, v)) {
    return u;
  }
  for (int i = logn - 1; i >= 0; i--) {
    if (!anc(ps[v][i], u)) {
      v = ps[v][i];
    }
  }
  return ps[v][0];
}

int dist(int v, int u) {
  int w = lca(v, u);
  int res = dep[v];
  add(res, dep[u]);
  add(res, mod - mul(2, dep[w]));
  return res;
}

void solve() {
  t = 0;
  dep[0] = 0;
  dfs(0, -1);
  dfs1(0, -1, {0, 0, 0});
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; qq++) {
    int v, u;
    scanf("%d%d", &u, &v);
    v--;
    u--;
    int d = dist(v, u);
    int res = 0;
    if (anc(v, u)) {
      res = dp[u][0][2];
      add(res, dp[u][1][2]);
      vector<int> dpv = {dp[v][1][0], dp[v][1][1], dp[v][1][2]};
      add(dpv[2], mul(2, mul(d, dpv[1])));
      add(dpv[2], mul(mul(d, d), dpv[0]));
      add(dpv[1], mul(d, dpv[0]));
      add(res, mod - mul(2, dpv[2]));
    } else {
      res = dp[u][0][2];
      add(res, dp[u][1][2]);
      res = mul(res, mod - 1);
      vector<int> dpv = {dp[v][0][0], dp[v][0][1], dp[v][0][2]};
      add(dpv[2], mul(2, mul(d, dpv[1])));
      add(dpv[2], mul(mul(d, d), dpv[0]));
      add(dpv[1], mul(d, dpv[0]));
      add(res, mul(2, dpv[2]));
    }
    printf("%d\n", res);
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