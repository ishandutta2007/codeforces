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

const int maxn = 3005;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }
  return true;
}

int lst[maxn], nxt[maxn];
int dp[maxn][maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    lst[i] = n;
  }
  for (int i = n - 1; i >= 0; --i) {
    nxt[i] = lst[a[i]];
    lst[a[i]] = i;
  }
  for (int i = 0; i <= n; ++i) {
    dp[i][i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    dp[i][i + 1] = 0;
  }
  for (int len = 2; len <= n; ++len) {
    for (int i = 0; i + len <= n; ++i) {
      int j = i + len;
      auto &cur = dp[i][j];
      cur = dp[i + 1][j];
      for (int k = nxt[i]; k < j; k = nxt[k]) {
        cur = max(cur, 1 + dp[i + 1][k] + dp[k][j]);
      }
    }
  }
  printf("%d\n", n - 1 - dp[0][n]);
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