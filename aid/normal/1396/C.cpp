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

const int maxn = (int) 1e6 + 5;
int n;
long long r[3];
long long d;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < 3; ++i) {
    scanf("%lld", &r[i]);
  }
  scanf("%lld", &d);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

long long dp[maxn][2];

void solve() {
  for (int i = 0; i <= n; ++i) {
    for (int t = 0; t < 2; ++t) {
      dp[i][t] = infll;
    }
  }
  dp[1][0] = a[0] * r[0] + r[2];
  dp[1][1] = min(r[1], (a[0] + 1) * r[0]);
  for (int i = 1; i < n; ++i) {
    {
      auto cur = dp[i][0];
      cur += d;
      dp[i + 1][0] = min(dp[i + 1][0], cur + a[i] * r[0] + r[2]);
      dp[i + 1][1] = min(dp[i + 1][1], cur + min(r[1], (a[i] + 1) * r[0]));
    }
    {
      auto cur = dp[i][1];
      cur += 3 * d + r[0];
      dp[i + 1][0] = min(dp[i + 1][0], cur + min(a[i] * r[0] + r[2], min(r[1], (a[i] + 1) * r[0]) + r[0]));
      if (i + 1 >= n) {
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + 2 * d + r[0] + a[i] * r[0] + r[2]);
      }
    }
  }
  auto res = dp[n][0];
  res = min(res, dp[n][1] + 2 * d + r[0]);
  printf("%lld\n", res);
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