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

const int maxn = (int) 1e5 + 5;
int n, u;
int a[maxn];

int read() {
  if (scanf("%d%d", &n, &u) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

void solve() {
  int p = -1, q = -1;
  for (int i = 0, k = 0; i < n; i++) {
    while (k + 1 < n && a[k + 1] - a[i] <= u) {
      k++;
    }
    if (k > i + 1) {
      int x = a[k] - a[i + 1], y = a[k] - a[i];
      if (p == -1 || (long long) x * q > (long long) p * y) {
        p = x;
        q = y;
      }
    }
  }
  if (p == -1) {
    printf("-1\n");
    return;
  }
  printf("%.12f\n", (double) p / q);
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