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

const int logs = 60;
long long s;

int read() {
  if (scanf("%lld", &s) < 1) {
    return false;
  }
  return true;
}

long long dp[logs + 1][2 * logs][2];

long long get(int a, int b, int popcnt, long long sum) {
  //eprintf("a = %d, b = %d, popcnt = %d, sum = %lld\n", a, b, popcnt, sum);
  if (sum < 0) {
    return 0;
  }
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  for (int i = 0; i < logs; i++) {
    int mx = i < a ? 2 : 1;
    int my = i < b ? 2 : 1;
    for (int j = 0; j <= popcnt; j++) {
      for (int carry = 0; carry < 2; carry++) {
        for (int x = 0; x < mx; x++) {
          for (int y = 0; y < my; y++) {
            if (((x + y + carry) & 1) == ((sum >> i) & 1) && j + x + y <= popcnt) {
              dp[i + 1][j + x + y][(x + y + carry) >> 1] += dp[i][j][carry];
            }
          }
        }
      }
    }
  }
  //eprintf("res = %lld\n", dp[logs][popcnt][0]);
  return dp[logs][popcnt][0];
}

void solve() {
  long long res = 0;
  for (int a = 0; a < logs; a++) {
    for (int b = 0; b < logs; b++) {
      long long q = (1ll << (a + 1)) + (1ll << (b + 1)) - 3;
      long long x = s / q;
      if (!x) {
        continue;
      }
      long long r = s % q;
      int aa = a, bb = b;
      if (aa) {
        aa--;
      }
      if (bb) {
        r -= (1ll << bb) - 1;
        bb--;
      }
      for (int popcnt = 0; popcnt <= aa + bb; popcnt++) {
        if (!((r + popcnt) & 1)) {
          res += get(aa, bb, popcnt, (r + popcnt) / 2);
        }
      }
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