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

long long n;
int q;

int read() {
  if (scanf("%lld%d", &n, &q) < 2) {
    return false;
  }
  return true;
}

long long get(long long x, long long n, int p) {
  if (n == 1) {
    return 0;
  }
  if ((x & 1) == p) {
    return x / 2;
  }
  return (n + 1 - p) / 2 + get(x / 2, (n + p) / 2, (p ^ (n & 1)));
}

void solve() {
  for (int qq = 0; qq < q; qq++) {
    long long x;
    scanf("%lld", &x);
    x--;
    printf("%lld\n", get(x, n, 0) + 1);
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