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

int gcd(int a, int b) {
  return (b ? gcd(b, a % b) : a);
}

int la, ra, ta;
int lb, rb, tb;

int read() {
  if (scanf("%d%d%d%d%d%d", &la, &ra, &ta, &lb, &rb, &tb) < 6) {
    return false;
  }
  return true;
}

void solve() {
  int g = gcd(ta, tb);
  int l0 = la % g, r0 = l0 + (ra - la);
  int l1 = lb % g, r1 = l1 + (rb - lb);
  int res = 0;
  {
    int l = max(l0, l1), r = min(r0, r1);
    res = max(res, r - l + 1);
  }
  {
    int l = max(l0, l1 + g), r = min(r0, r1 + g);
    res = max(res, r - l + 1);
  }
  {
    int l = max(l0 + g, l1), r = min(r0 + g, r1);
    res = max(res, r - l + 1);
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