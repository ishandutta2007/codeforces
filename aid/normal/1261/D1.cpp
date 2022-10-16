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

const int maxn = (int) 2e5 + 5;
int p2[maxn];
int f[maxn], inv[maxn], finv[maxn];

void precalc() {
  p2[0] = 1;
  for (int i = 1; i < maxn; i++) {
    p2[i] = mul(p2[i - 1], 2);
  }
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

int c(int n, int k) {
  return mul(f[n], mul(finv[k], finv[n - k]));
}

int n, k;
int h[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &h[i]);
  }
  return true;
}

void solve() {
  if (k == 1) {
    printf("0\n");
    return;
  }
  int m = 0;
  for (int i = 0; i < n; i++) {
    if (h[i] != h[(i + 1) % n]) {
      m++;
    }
  }
  int res = 0;
  int kk = 1;
  for (int i = 0; i < m; i++) {
    int cur;
    int x = m - i;
    if (x & 1) {
      cur = p2[x - 1];
    } else {
      cur = p2[x];
      add(cur, mod - c(x, x / 2));
      cur = mul(cur, (mod + 1) / 2);
    }
    cur = mul(cur, c(m, i));
    cur = mul(cur, kk);
    add(res, cur);
    kk = mul(kk, (k - 2) % mod);
  }
  for (int i = 0; i < n - m; i++) {
    res = mul(res, k % mod);
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