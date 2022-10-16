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

const int maxn = 4005;
int c[maxn][maxn];
int f[maxn];

void precalc() {
  for (int i = 0; i < maxn; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = c[i - 1][j - 1];
      add(c[i][j], c[i - 1][j]);
    }
  }
  f[0] = 1;
  for (int i = 1; i < maxn; i++) {
    f[i] = mul(f[i - 1], i);
  }
}

int n, m;
int rs[maxn], cs[maxn];

bool read() {
  int k;
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    rs[i] = false;
  }
  for (int i = 0; i < m; i++) {
    cs[i] = false;
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 2; j++) {
      int x, y;
      scanf("%d%d", &x, &y);
      x--;
      y--;
      rs[x] = true;
      cs[y] = true;
    }
  }
  return true;
}

int ndp[2][maxn];

void getDp(int n, int a[maxn], int dp[maxn]) {
  memset(ndp, 0, sizeof(ndp));
  for (int i = 0; i <= n; i++) {
    dp[i] = 0;
  }
  dp[0] = 1;
  for (int i = 0; i <= n; i++) {
    for (int x = 0; x <= n; x++) {
      add(dp[x], ndp[i & 1][x]);
      ndp[i & 1][x] = 0;
    }
    if (i + 1 < n && !a[i] && !a[i + 1]) {
      for (int x = 0; x <= n; x++) {
        auto cur = dp[x];
        if (!cur) {
          continue;
        }
        add(ndp[i & 1][x + 1], cur);
      }
    }
  }
}

int rdp[maxn], cdp[maxn];

void solve() {
  getDp(n, rs, rdp);
  getDp(m, cs, cdp);
  int cx = 0;
  for (int i = 0; i < n; i++) {
    if (!rs[i]) {
      cx++;
    }
  }
  int cy = 0;
  for (int i = 0; i < m; i++) {
    if (!cs[i]) {
      cy++;
    }
  }
  int res = 0;
  for (int i = 0; i <= n; i++) {
    auto x = rdp[i];
    if (!x) {
      continue;
    }
    for (int j = 0; j <= m; j++) {
      auto y = cdp[j];
      if (!y) {
        continue;
      }
      if (i + 2 * j > cy || 2 * i + j > cx) {
        continue;
      }
      int cur = mul(x, y);
      cur = mul(cur, c[cy - 2 * j][i]);
      cur = mul(cur, f[i]);
      cur = mul(cur, c[cx - 2 * i][j]);
      cur = mul(cur, f[j]);
      add(res, cur);
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