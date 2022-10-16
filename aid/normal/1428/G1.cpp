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

const int n = (int) 1e6, l = 6;
const int maxq = (int) 1e5 + 5;
int k;
int f[l];
int q;
int p10[l + 1];
int qs[maxq];

void precalc() {
  p10[0] = 1;
  for (int i = 1; i <= l; ++i) {
    p10[i] = p10[i - 1] * 10;
  }
}

bool read() {
  if (scanf("%d", &k) < 1) {
    return false;
  }
  for (int i = 0; i < l; ++i) {
    scanf("%d", &f[i]);
  }
  scanf("%d", &q);
  for (int qq = 0; qq < q; ++qq) {
    scanf("%d", &qs[qq]);
  }
  return true;
}

long long dp[l + 1][n];

long long getVal(int x, int f) {
  if (x > k * 9) {
    return -infll;
  }
  int nines = x / 9;
  int rem = x % 9;
  long long res = (long long) nines * f * 3ll;
  if (!rem) {
    return res;
  }
  int have = k - nines;
  if (have == 1) {
    if (rem == 6) {
      res += f * 2ll;
    } else if (rem == 3) {
      res += f;
    }
    return res;
  }
  if (rem >= 6) {
    res += f * 2ll;
  } else if (rem >= 3) {
    res += f;
  }
  return res;
}

long long solve(int x) {
  dp[l][0] = 0;
  for (int d = l - 1; d >= 0; --d) {
    int dig = (x / p10[d]) % 10;
    int mx = x / p10[d];
    int nmx = x / p10[d + 1];
    for (int carry = 0; carry <= mx; ++carry) {
      if (!d && carry) {
        break;
      }
      auto &cur = dp[d][carry];
      cur = -infll;
      for (int ncarry = carry / 10; ncarry <= nmx; ++ncarry) {
        int need = (ncarry * 10 + dig) - carry;
        if (need < 0) {
          continue;
        }
        long long val = getVal(need, f[d]);
        if (val >= 0) {
          cur = max(cur, dp[d + 1][ncarry] + val);
        }
      }
    }
  }
  return dp[0][0];
}

void solve() {
  for (int qq = 0; qq < q; ++qq) {
    printf("%lld\n", solve(qs[qq]));
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