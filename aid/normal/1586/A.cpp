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

const int maxn = 105;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

bool isPrime(int x) {
  for (int d = 2; d * d <= x; ++d) {
    if (!(x % d)) {
      return false;
    }
  }
  return true;
}

void solve() {
  int s = 0;
  for (int i = 0; i < n; ++i) {
    s += a[i];
  }
  if (!isPrime(s)) {
    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
      printf("%d ", i + 1);
    }
    printf("\n");
    return;
  }
  int p = 0;
  while (!(a[p] & 1)) {
    ++p;
  }
  printf("%d\n", n - 1);
  for (int i = 0; i < n; ++i) {
    if (i != p) {
      printf("%d ", i + 1);
    }
  }
  printf("\n");
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}