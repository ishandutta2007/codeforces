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

long long gcd(long long a, long long b) {
  return (b ? gcd(b, a % b) : a);
}

long long n, k;
long long a, b;

bool read() {
  if (scanf("%lld%lld%lld%lld", &n, &k, &a, &b) < 4) {
    return false;
  }
  return true;
}

void solve() {
  long long mn = n * k, mx = 1;
  for (int ss = -1; ss <= 1; ss += 2) {
    long long s = (n * k + ss * a) % (n * k);
    for (int yy = -1; yy <= 1; yy += 2) {
      long long y = (k + yy * b) % k;
      for (long long x = 0; x < n; x++) {
        long long t = x * k + y;
        long long l = (t + n * k - s) % (n * k);
        long long cur = n * k / gcd(l, n * k);
        mn = min(mn, cur);
        mx = max(mx, cur);
      }
    }
  }
  printf("%lld %lld\n", mn, mx);
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