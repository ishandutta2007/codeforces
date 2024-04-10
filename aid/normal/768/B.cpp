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

long long n, l, r;

int read() {
  if (scanf("%lld%lld%lld", &n, &l, &r) < 3) {
    return false;
  }
  l--;
  return true;
}

int get(long long n, long long curlen, long long pos) {
  if (n <= 1) {
    return n;
  }
  long long nlen = curlen / 2;
  if (pos < nlen) {
    return get(n / 2, nlen, pos);
  }
  if (pos == nlen) {
    return (n & 1);
  }
  return get(n / 2, nlen, pos - nlen - 1);
}

void solve() {
  long long len = 1;
  while (len < n) {
    len = 2 * len + 1;
  }
  int res = 0;
  for (long long i = l; i < r; i++) {
    res += get(n, len, i);
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