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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

long long l, r;

int read() {
  unsigned long long x;
  if (scanf("%llx", &x) < 1) {
    return false;
  }
  l = x;
  scanf("%llx", &x);
  r = x;
  return true;
}

const int d = 15;
const int len = 17;
long long dp[len + 1][2][2];
int s[len];

long long solve1(long long n) {
  memset(s, 0, sizeof(s));
  for (int pos = 0; n; pos++) {
    s[pos] = (n & 15);
    n >>= 4;
  }
  long long res = 0;
  for (int maxd = 0; maxd <= d; maxd++) {
    memset(dp, 0, sizeof(dp));
    dp[len][0][0] = 1;
    for (int i = len; i > 0; i--) {
      for (int less = 0; less < 2; less++) {
        for (int wasd = 0; wasd < 2; wasd++) {
          auto cur = dp[i][less][wasd];
          if (!cur) {
            continue;
          }
          int dd = maxd;
          if (!less) {
            dd = min(dd, s[i - 1]);
          }
          int bit = -1;
          if (maxd / 4 == i - 1) {
            bit = maxd % 4;
          }
          for (int dig = 0; dig <= dd; dig++) {
            if (bit != -1 && !(dig & (1 << bit))) {
              continue;
            }
            auto &nxt = dp[i - 1][less || dig < s[i - 1]][wasd || dig == maxd];
            nxt += cur;
          }
        }
      }
    }
    res += dp[0][1][1];
  }
  return res;
}

void solve() {
  long long res = solve1(r + 1) - solve1(l);
  printf("%lld\n", res);
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