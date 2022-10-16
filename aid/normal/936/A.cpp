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

void precalc() {
}

long long k, d, t;

int read() {
  if (scanf("%lld%lld%lld", &k, &d, &t) < 3) {
    return false;
  }
  return true;
}

void solve() {
  d = (k + d - 1) / d * d;
  long long x = (2 * t) / (d + k);
  ld res = x * d;
  ld r = 1 - (ld) (x * (d + k)) / (2 * t);
  if (r * t < k + eps) {
    res += r * t;
  } else {
    res += k;
    r -= (ld) k / t;
    res += r * 2 * t;
  }
  printf("%.12f\n", (double) res);
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