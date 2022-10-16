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

const int maxd = 61;
int q;

int read() {
  if (scanf("%d", &q) < 1) {
    return false;
  }
  return true;
}

int getD(long long x) {
  return 63 - __builtin_clzll(x);
}

long long sh[maxd];

void solve() {
  for (int i = 0; i < maxd; i++) {
    sh[i] = 0;
  }
  for (int qq = 0; qq < q; qq++) {
    int t;
    scanf("%d", &t);
    if (t == 3) {
      long long x;
      scanf("%lld", &x);
      int d = getD(x);
      x -= (1ll << d);
      x = (sh[d] + x) % (1ll << d);
      while (d >= 0) {
        long long val = x - sh[d];
        if (val < 0) {
          val += (1ll << d);
        }
        val += (1ll << d);
        printf("%lld ", val);
        d--;
        x >>= 1;
      }
      printf("\n");
    } else {
      long long x, k;
      scanf("%lld%lld", &x, &k);
      int ld = getD(x);
      int rd = (t == 1 ? ld + 1 : maxd);
      for (int d = ld; d < rd; d++) {
        sh[d] = (sh[d] + k) % (1ll << d);
        if (sh[d] < 0) {
          sh[d] += (1ll << d);
        }
        k = k % (1ll << d);
        k *= 2;
      }
    }
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