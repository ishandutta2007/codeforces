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

long long n;

bool read() {
  if (scanf("%lld", &n) < 1) {
    return false;
  }
  n--;
  return true;
}

long long a[4];

void get(int k, long long x) {
  if (!x) {
    for (int i = 0; i < 3; i++) {
      a[i] = 0;
    }
    return;
  }
  int b0 = 63 - __builtin_clzll(x);
  b0 = (b0 & ~1);
  int b1 = (b0 | 1);
  int l = (((x >> b0) & 1) ? (((x >> b1) & 1) ? 2 : 0) : 1);
  if (l != k) {
    get(l, x);
    int sh = (l - k + 3) % 3;
    rotate(a, a + sh, a + 3);
    return;
  }
  long long y = (x & ((1ll << b0) | (1ll << b1)));
  get(k, (x ^ y));
  a[0] ^= (1ll << b0);
  a[1] ^= (1ll << b1);
  a[2] ^= (1ll << b0) ^ (1ll << b1);
}

void solve() {
  int k = n % 3;
  n /= 3;
  long long p = 1;
  long long x;
  while (true) {
    if (n < p) {
      x = p + n;
      break;
    }
    n -= p;
    p *= 4;
  }
  get(0, x);
  printf("%lld\n", a[k]);
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