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

const int maxn = 2005;
char tmp[maxn];
int n;
int a[maxn], b[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", tmp);
  for (int i = 0; i < n; ++i) {
    if (tmp[i] == '?') {
      a[i] = -1;
      continue;
    }
    a[i] = ((tmp[i] - '0') ^ (i & 1));
  }
  scanf("%s", tmp);
  for (int i = 0; i < n; ++i) {
    if (tmp[i] == '?') {
      b[i] = -1;
      continue;
    }
    b[i] = ((tmp[i] - '0') ^ (i & 1));
  }
  return true;
}

int dp[maxn][maxn][2], cnt[maxn][maxn][2];

void solve() {
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int t = 0; t < 2; ++t) {
        dp[i][j][t] = 0;
        cnt[i][j][t] = 0;
      }
    }
  }
  cnt[0][0][0] = 1;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int t = 0; t < 2; ++t) {
        auto cur = dp[i][j][t], curcnt = cnt[i][j][t];
        if (!cur && !curcnt) {
          continue;
        }
        if (!t) {
          if (i < n && a[i] != 1) {
            add(dp[i + 1][j][t], cur);
            add(cnt[i + 1][j][t], curcnt);
          }
          if (i < n && a[i] != 0) {
            add(dp[i][j][1], cur);
            add(cnt[i][j][1], curcnt);
          }
          if (i >= n) {
            if (j < n && b[j] != 1) {
              add(dp[i][j + 1][t], cur);
              add(cnt[i][j + 1][t], curcnt);
            }
          }
        } else {
          if (j < n && b[j] != 1) {
            add(dp[i][j + 1][t], cur);
            add(cnt[i][j + 1][t], curcnt);
          }
          if (j < n && b[j] != 0) {
            add(dp[i + 1][j + 1][0], cur);
            add(dp[i + 1][j + 1][0], mul(curcnt, abs(j - i)));
            add(cnt[i + 1][j + 1][0], curcnt);
          }
        }
      }
    }
  }
  printf("%d\n", dp[n][n][0]);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}