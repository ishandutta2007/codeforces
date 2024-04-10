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

long long n, x, k;

int read() {
  long long l, r;
  if (scanf("%lld%lld%lld%lld", &n, &l, &r, &k) < 4) {
    return false;
  }
  x = (r - l + 1 + n) % n;
  return true;
}

void solve() {
  long long res = -1;
  if (x == 0) {
    if (n < (int) 1e6) {
      for (long long a = 0; a <= n; a++) {
        if (!(k % (n + a))) {
          res = max(res, a);
        }
        if (!((k + 1) % (n + a)) && a) {
          res = max(res, a);
        }
      }
    } else {
      for (long long l = 1; l <= (int) 1e6; l++) {
        if (!(k % l)) {
          long long a = k / l - n;
          if (0 <= a && a <= n) {
            res = max(res, a);
          }
        }
        if (!((k + 1) % l)) {
          long long a = (k + 1) / l - n;
          if (1 <= a && a <= n) {
            res = max(res, a);
          }
        }
      }
    }
  } else {
    if (n < (int) 1e6) {
      for (long long a = 0; a <= n; a++) {
        {
          long long b = k % (n + a) - x;
          if (0 <= b && b <= x && b <= a && a - b <= n - x) {
            res = max(res, a);
          }
        }
        {
          long long b = (k + 1) % (n + a) - x;
          if (1 <= b && b <= x && b <= a && a - b <= n - x) {
            res = max(res, a);
          }
        }
      }
    } else {
      {
        long long b = k - x;
        if (0 <= b && b <= x) {
          long long a = b + n - x;
          res = max(res, a);
        }
      }
      {
        long long b = k + 1 - x;
        if (1 <= b && b <= x) {
          long long a = b + n - x;
          res = max(res, a);
        }
      }
      for (long long l = 1; l <= (int) 1e6; l++) {
        {
          long long r = k - x - l * n;
          if (r >= 0) {
            long long a = min(min(r / l, (n - x + r) / (l + 1)), n);
            long long b = r - l * a;
            if (0 <= a && b <= x && b <= a) {
              res = max(res, a);
            }
          }
        }
        {
          long long r = k + 1 - x - l * n;
          if (r >= 1) {
            long long a = min(min((r - 1) / l, (n - x + r) / (l + 1)), n);
            long long b = r - l * a;
            if (0 <= a && b <= x && b <= a) {
              res = max(res, a);
            }
          }
        }
      }
    }
  }
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