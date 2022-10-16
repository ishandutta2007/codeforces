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

const int maxn = 3005;
int x, n;
int have[maxn];

int read() {
  if (scanf("%d%d", &x, &n) < 1) {
    return false;
  }
  for (int i = 0; i < maxn; i++) {
    have[i] = false;
  }
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    have[a]++;
  }
  return true;
}

int a[maxn];
int q[2 * maxn];
int d[2 * maxn];

void solve() {
  n = 0;
  for (int i = 0; i < maxn; i++) {
    if (have[i]) {
      a[n++] = i;
    }
  }
  for (int i = 0; i < n; i++) {
    a[i] -= x;
  }
  if (a[0] > 0 || a[n - 1] < 0) {
    printf("-1\n");
    return;
  }
  int r = 0;
  for (int i = 0; i < 2 * maxn; i++) {
    d[i] = inf;
  }
  for (int i = 0; i < n; i++) {
    if (d[maxn + a[i]] >= inf) {
      d[maxn + a[i]] = 1;
      q[r++] = maxn + a[i];
    }
  }
  for (int l = 0; l < r && d[maxn] >= inf; l++) {
    int v = q[l];
    for (int i = 0; i < n; i++) {
      if (0 <= v + a[i] && v + a[i] < 2 * maxn && d[v + a[i]] >= inf) {
        d[v + a[i]] = d[v] + 1;
        q[r++] = v + a[i];
      }
    }
  }
  assert(d[maxn] < inf);
  printf("%d\n", d[maxn]);
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