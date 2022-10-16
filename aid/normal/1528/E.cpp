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

const int maxn = (int) 1e6 + 5;
int dp[maxn], dp2[maxn], dp3[maxn];

void precalc() {
  dp[0] = 1;
  dp2[0] = 0;
  dp3[0] = 1;
  for (int n = 1; n < maxn; ++n) {
    dp[n] = dp[n - 1];
    add(dp[n], 1);
    dp[n] = mul(dp[n], dp[n - 1]);
    dp3[n] = dp[n - 1];
    add(dp3[n], 2);
    dp3[n] = mul(dp3[n], dp[n]);
    dp[n] = mul(dp[n], (mod + 1) / 2);
    dp2[n] = dp[n];
    add(dp[n], 1);
    add(dp2[n], mod - dp[n - 1]);
    dp3[n] = mul(dp3[n], (mod + 1) / 2);
    dp3[n] = mul(dp3[n], (mod + 1) / 3);
    add(dp3[n], 1);
  }
  for (int n = maxn - 1; n > 0; --n) {
    add(dp[n], mod - dp[n - 1]);
    add(dp2[n], mod - dp2[n - 1]);
    add(dp3[n], mod - dp3[n - 1]);
  }
}

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

void solve() {
  int res = mul(dp3[n + 1], 2);
  add(res, mod - 1);
  int s = 0;
  for (int i = 2; i < n; ++i) {
    add(s, dp2[i]);
    add(res, mul(s, dp2[n + 1 - i]));
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