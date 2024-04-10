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

const int maxn = (int) 1e6 + 5;
int f[maxn], inv[maxn], finv[maxn];

int c(int n, int k) {
  if (k > n || k < 0) {
    return 0;
  }
  return mul(f[n], mul(finv[k], finv[n - k]));
}

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

int n, m, a, b;

bool read() {
  if (scanf("%d%d%d%d", &n, &m, &a, &b) < 4) {
    return false;
  }
  return true;
}

int pm[maxn], pn[maxn];

void solve() {
  pm[0] = 1;
  pn[0] = 1;
  for (int i = 1; i < maxn; i++) {
    pm[i] = mul(pm[i - 1], m);
    pn[i] = mul(pn[i - 1], n);
  }
  int res = 0;
  for (int len = n - 1; len > 0; len--) {
    int cur = (len == n - 1 ? 1 : mul(pn[n - len - 2], len + 1));
    cur = mul(cur, c(n - 2, len - 1));
    cur = mul(cur, f[len - 1]);
    cur = mul(cur, c(m - 1, len - 1));
    cur = mul(cur, pm[n - 1 - len]);
    add(res, cur);
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