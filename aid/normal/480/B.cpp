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
int n, l, x, y;
int a[maxn];

int read() {
  if (scanf("%d%d%d%d", &n, &l, &x, &y) < 4) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int get(int l, int r, int d) {
  for (int i = 0; i < n; i++) {
    if (a[i] < l || a[i] > r) {
      continue;
    }
    int pos = lower_bound(a, a + n, a[i] + d) - a;
    if (pos >= n || a[pos] != a[i] + d) {
      continue;
    }
    return i;
  }
  return -1;
}

void solve() {
  if (get(0, l, x) != -1) {
    if (get(0, l, y) != -1) {
      printf("0\n");
      return;
    }
    printf("1\n%d\n", y);
    return;
  }
  if (get(0, l, y) != -1) {
    printf("1\n%d\n", x);
    return;
  }
  {
    int pos = get(0, l, x + y);
    if (pos != -1) {
      printf("1\n%d\n", a[pos] + x);
      return;
    }
  }
  {
    int pos = get(x, l, y - x);
    if (pos != -1) {
      printf("1\n%d\n", a[pos] - x);
      return;
    }
  }
  {
    int pos = get(0, l - y, y - x);
    if (pos != -1) {
      printf("1\n%d\n", a[pos] + y);
      return;
    }
  }
  printf("2\n%d %d\n", x, y);
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