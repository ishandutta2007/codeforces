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

const int mod = 998244353;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = 3005;
int n;
int a[maxn][maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  return true;
}

pair<int, int> es[maxn * maxn];
int p[maxn], ts[maxn], e[maxn], good[maxn];
vector<int> g[maxn];
int vs;

int get(int x) {
  return (p[x] == x ? x : get(p[x]));
}

bool unite(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y) {
    ++e[x];
    return false;
  }
  int z = vs++;
  p[z] = z;
  ts[z] = ts[x] + ts[y];
  e[z] = e[x] + e[y] + 1;
  p[x] = z;
  p[y] = z;
  return true;
}

vector<int> dp[maxn];
vector<int> ndp;

void dfs(int v) {
  dp[v] = {!g[v].empty()};
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    dfs(u);
    ndp.clear();
    ndp.resize(sz(dp[v]) + sz(dp[u]) - 1);
    for (int x = 0; x < sz(dp[v]); ++x) {
      for (int y = 0; y < sz(dp[u]); ++y) {
        add(ndp[x + y], mul(dp[v][x], dp[u][y]));
      }
    }
    swap(dp[v], ndp);
  }
  if (good[v]) {
    if (sz(dp[v]) <= 1) {
      dp[v].resize(2, 0);
    }
    add(dp[v][1], 1);
  }
}

void solve() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      es[a[i][j] - 1] = make_pair(i, j);
    }
  }
  for (int i = 0; i < n; ++i) {
    p[i] = i;
    ts[i] = 1;
    e[i] = 0;
  }
  vs = n;
  for (int i = 0; i < n * (n - 1) / 2; ++i) {
    int v = es[i].first, u = es[i].second;
    unite(v, u);
  }
  for (int i = 0; i < vs; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < vs; ++i) {
    good[i] = (e[i] == ts[i] * (ts[i] - 1) / 2);
    if (p[i] != i) {
      g[p[i]].push_back(i);
    }
  }
  int root = get(0);
  dfs(root);
  for (int i = 1; i <= n; ++i) {
    printf("%d ", dp[root][i]);
  }
  printf("\n");
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