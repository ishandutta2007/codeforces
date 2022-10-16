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

const int n = 31;
int x;
long long c[n];

int read() {
  int n;
  if (scanf("%d%d", &n, &x) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &c[i]);
  }
  for (int i = n; i < ::n; i++) {
    c[i] = infll;
  }
  return true;
}

void solve() {
  for (int i = 1; i < n; i++) {
    c[i] = min(c[i], 2 * c[i - 1]);
  }
  long long res = infll;
  long long cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (x & (1 << i)) {
      cur += c[i];
    } else {
      res = min(res, cur + c[i]);
    }
  }
  res = min(res, cur);
  printf("%lld\n", res);
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