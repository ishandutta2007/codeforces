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

const int maxn = 505;
int n, m, mod;

bool read() {
  if (scanf("%d%d%d", &n, &m, &mod) < 3) {
    return false;
  }
  return true;
}

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int c[maxn][maxn];

struct T {
  int cnt, sum;

  T(): cnt(0), sum(0) {}

  T(int x): cnt(x), sum(0) {}

  T(int c, int s): cnt(c), sum(s) {}

  T operator * (const T &t) const {
    int s = mul(cnt, t.sum);
    add(s, mul(sum, t.cnt));
    return T(mul(cnt, t.cnt), s);
  }

  T operator + (const T &t) const {
    int c = cnt;
    add(c, t.cnt);
    int s = sum;
    add(s, t.sum);
    return T(c, s);
  }
};

T dp[maxn];
T pdp[maxn][maxn];

void solve() {
  {
    for (int i = 0; i <= m; ++i) {
      c[i][0] = 1;
      for (int j = 1; j <= i; ++j) {
        c[i][j] = c[i - 1][j - 1];
        add(c[i][j], c[i - 1][j]);
      }
    }
  }
  {
    dp[0] = T(1);
    for (int k = 1; k <= m; ++k) {
      auto &cur = dp[k];
      cur = T(0);
      for (int i = 0; i < k; ++i) {
        auto x = dp[i] * dp[k - i - 1];
        x = x * T(c[k - 1][i]);
        for (int j = 0; j < k; ++j) {
          auto y = x * T(1 + (j == i), abs(i - j));
          cur = cur + y;
        }
      }
      eprintf("%d %d\n", dp[k].cnt, dp[k].sum);
    }
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      pdp[i][j] = T(0);
    }
  }
  pdp[0][0] = T(1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      auto cur = pdp[i][j];
      if (!cur.cnt && !cur.sum) {
        continue;
      }
      {
        auto &nxt = pdp[i + 1][j];
        nxt = nxt + cur;
      }
      for (int k = 1; j + k <= m && i + k <= n; ++k) {
        auto &nxt = pdp[min(n, i + k + 1)][j + k];
        nxt = nxt + cur * dp[k] * T(c[m - j][k]);
      }
    }
  }
  printf("%d\n", pdp[n][m].sum);
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