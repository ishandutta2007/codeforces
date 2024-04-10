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

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e5 + 5;
int n;
long long a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  return true;
}

void solve() {
  if (n == 1) {
    printf("%d %d\n", 1, 1);
    printf("%lld\n", -a[0]);
    printf("%d %d\n", 1, 1);
    printf("%lld\n", 0ll);
    printf("%d %d\n", 1, 1);
    printf("%lld\n", 0ll);
    return;
  }
  printf("%d %d\n", 1, n - 1);
  for (int i = 0; i < n - 1; ++i) {
    long long r = a[i] % n;
    long long x = r * (n - 1);
    printf("%lld ", x);
    a[i] += x;
  }
  printf("\n");
  printf("%d %d\n", n, n);
  printf("%lld\n", -a[n - 1]);
  a[n - 1] = 0;
  printf("%d %d\n", 1, n);
  for (int i = 0; i < n; ++i) {
    assert(!(a[i] % n));
    printf("%lld ", -a[i]);
  }
  printf("\n");
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