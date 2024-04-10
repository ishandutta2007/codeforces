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

int n, m, k;

int read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  return true;
}

void solve() {
  int x = n, y = m;
  {
    int g = gcd(x, k);
    x /= g;
    k /= g;
  }
  {
    int g = gcd(y, k);
    y /= g;
    k /= g;
  }
  if (k > 2) {
    printf("NO\n");
    return;
  }
  if (k == 1) {
    if (2 * x <= n) {
      x *= 2;
    } else {
      assert(2 * y <= m);
      y *= 2;
    }
  }
  printf("YES\n");
  printf("0 0\n");
  printf("%d %d\n", x, 0);
  printf("%d %d\n", 0, y);
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