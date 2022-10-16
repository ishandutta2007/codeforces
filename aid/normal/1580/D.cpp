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

const int maxn = 4005;
int n, m;
long long a[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  return true;
}

long long dp[maxn][maxn];
int ts[maxn];

int build(int l, int r) {
  if (l >= r) {
    return n;
  }
  int v = l;
  for (int i = l + 1; i < r; ++i) {
    if (a[i] < a[v]) {
      v = i;
    }
  }
  int ul = build(l, v), ur = build(v + 1, r);
  ts[v] = 1 + ts[ul] + ts[ur];
  for (int i = 0; i <= ts[v]; ++i) {
    dp[v][i] = -infll;
  }
  for (int i = 0; i <= ts[ul]; ++i) {
    for (int j = 0; j <= ts[ur]; ++j) {
      dp[v][i + j] = max(dp[v][i + j], dp[ul][i] + dp[ur][j] - 2 * i * j * a[v]);
    }
  }
  for (int i = 0; i <= ts[ul]; ++i) {
    for (int j = 0; j <= ts[ur]; ++j) {
      dp[v][i + j + 1] = max(dp[v][i + j + 1], dp[ul][i] + dp[ur][j] + (m - (2 * (i + 1) * (j + 1) - 1)) * a[v]);
    }
  }
  return v;
}

void solve() {
  ts[n] = 0;
  dp[n][0] = 0;
  int root = build(0, n);
  printf("%lld\n", dp[root][m]);
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