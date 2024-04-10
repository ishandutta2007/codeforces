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

long long n, k;

int read() {
  if (scanf("%lld%lld", &n, &k) < 2) {
    return false;
  }
  return true;
}

long long phi(long long n) {
  long long res = 1;
  for (long long i = 2; i * i <= n; i++) {
    if (!(n % i)) {
      res *= i - 1;
      n /= i;
      while (!(n % i)) {
        res *= i;
        n /= i;
      }
    }
  }
  if (n > 1) {
    res *= n - 1;
  }
  return res;
}

void solve() {
  k = (k + 1) / 2;
  while (k > 0 && n > 1) {
    n = phi(n);
    k--;
  }
  printf("%lld\n", n % ((int) 1e9 + 7));
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