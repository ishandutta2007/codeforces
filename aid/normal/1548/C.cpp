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

const int maxn = (int) 3e6 + 5;
int f[maxn], inv[maxn], finv[maxn];

int c(int n, int k) {
  return mul(f[n], mul(finv[k], finv[n - k]));
}

void precalc() {
  f[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    f[i] = mul(f[i - 1], i);
  }
  inv[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    inv[i] = (mod - (long long) (mod / i) * inv[mod % i] % mod) % mod;
  }
  finv[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    finv[i] = mul(finv[i - 1], inv[i]);
  }
}

int n, q;

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  return true;
}

int ans[maxn];

void solve() {
  ans[0] = n + 1;
  ans[1] = 0;
  for (int i = 1; i <= n; ++i) {
    add(ans[1], 3 * i);
  }
  for (int i = 2; i <= 3 * n; ++i) {
    int s = c(3 * (n + 1), i + 1);
    add(s, mod - ans[i - 2]);
    add(s, mod - mul(3, ans[i - 1]));
    ans[i] = mul(s, inv[3]);
  }
  for (int qq = 0; qq < q; ++qq) {
    int x;
    scanf("%d", &x);
    printf("%d\n", ans[x]);
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