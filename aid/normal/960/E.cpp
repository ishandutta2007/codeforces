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

const int maxn = (int) 2e5 + 5;
int n;
int a[maxn];
vector<int> g[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i] = (a[i] + mod) % mod;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

int d[maxn];
int ts[2][maxn];

void dfs0(int v, int p) {
  ts[d[v]][v] = 1;
  ts[d[v] ^ 1][v] = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    d[u] = (d[v] ^ 1);
    dfs0(u, v);
    for (int it = 0; it < 2; it++) {
      ts[it][v] += ts[it][u];
    }
  }
}

int res;

void dfs(int v, int p) {
  int tsp[2] = {ts[0][0] - ts[0][v], ts[1][0] - ts[1][v]};
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    int curts[2];
    if (u == p) {
      for (int it = 0; it < 2; it++) {
        curts[it] = tsp[it];
      }
    } else {
      for (int it = 0; it < 2; it++) {
        curts[it] = ts[it][u];
      }
    }
    add(res, mul(a[v], mul(curts[d[v]], n - curts[0] - curts[1])));
    add(res, mod - mul(a[v], mul(curts[d[v] ^ 1], n - curts[0] - curts[1])));
  }
  add(res, mul(a[v], n));
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs(u, v);
  }
}

void solve() {
  d[0] = 0;
  dfs0(0, -1);
  res = 0;
  dfs(0, -1);
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