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

const int maxn = 405;
int n, m;
vector<int> g[maxn];
int d[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    g[i].clear();
    for (int j = 0; j < n; ++j) {
      d[i][j] = inf;
    }
    d[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    g[v].push_back(u);
    g[u].push_back(v);
    d[v][u] = 1;
    d[u][v] = 1;
  }
  return true;
}

int ans[maxn][maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
      }
    }
  }
  for (int x = 0; x < n; ++x) {
    for (int y = x; y < n; ++y) {
      auto &cur = ans[x][y];
      cur = 1;
      int cnt = 0;
      for (int v = 0; v < n; ++v) {
        if (d[x][y] == d[x][v] + d[v][y]) {
          ++cnt;
          continue;
        }
        int val = 0;
        for (int i = 0; i < sz(g[v]); ++i) {
          int u = g[v][i];
          if (d[x][v] == d[x][u] + 1 && d[y][v] == d[y][u] + 1) {
            ++val;
          }
        }
        cur = mul(cur, val);
      }
      if (cnt != d[x][y] + 1) {
        cur = 0;
      }
      ans[y][x] = cur;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
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