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

const int maxn = (int) 2e6 + 5;
int f[maxn], inv[maxn], finv[maxn];

void precalc() {
  f[0] = 1;
  for (int i = 1; i < maxn; i++) {
    f[i] = mul(f[i - 1], i);
  }
  inv[1] = 1;
  for (int i = 2; i < maxn; i++) {
    inv[i] = (mod - (long long) (mod / i) * inv[mod % i] % mod) % mod;
  }
  finv[0] = 1;
  for (int i = 1; i < maxn; i++) {
    finv[i] = mul(finv[i - 1], inv[i]);
  }
}

int n, k;

int read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  return true;
}

int dp[maxn], dp1[maxn];
int ans[maxn];
int s[maxn];

void solve() {
  int sum = 0;
  s[0] = 0;
  for (int i = 1; i <= n; i++) {
    ans[i] = f[i];
    dp[i] = f[i - 1];
    if (i > k + 1) {
      add(sum, s[i - k - 1]);
      add(ans[i], mod - mul(sum, f[i - 1]));
      add(dp[i], mod - mul(s[i - k - 1], f[i - 1]));
    }
    dp1[i] = mul(dp[i], mul(finv[i - 1], inv[i + k]));
    s[i] = s[i - 1];
    add(s[i], dp1[i]);
  }
  int res = f[n];
  add(res, mod - ans[n]);
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