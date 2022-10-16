#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
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

long long n;
int k;

int read() {
  if (scanf("%lld%d", &n, &k) < 2) {
    return false;
  }
  return true;
}

void solve() {
  long long d;
  for (d = 1; d * d <= n; d++) {
    if (!(n % d)) {
      k--;
      if (!k) {
        printf("%lld\n", d);
        return;
      }
    }
  }
  d--;
  if (d * d == n) {
    d--;
  }
  for (; d > 0; d--) {
    if (!(n % d)) {
      k--;
      if (!k) {
        printf("%lld\n", n / d);
        return;
      }
    }
  }
  printf("-1\n");
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}