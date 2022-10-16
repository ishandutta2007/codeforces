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

const int maxn = 55, maxb = 60;
int n, k;
long long a[maxn];

int read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  return true;
}

long long s[maxn];
int dp[maxn][maxn];

bool check(long long msk) {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      auto cur = dp[i][j];
      if (!cur) {
        continue;
      }
      for (int l = i + 1; l <= n; l++) {
        if (((s[l] - s[i]) & msk) == msk) {
          dp[l][j + 1] = true;
        }
      }
    }
  }
  return dp[n][k];
}

void solve() {
  s[0] = 0;
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + a[i];
  }
  long long res = 0;
  for (int bit = maxb - 1; bit >= 0; bit--) {
    if (check(res ^ (1ll << bit))) {
      res ^= (1ll << bit);
    }
  }
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