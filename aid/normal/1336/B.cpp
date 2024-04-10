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
int n[3];
int a[3][maxn];

bool read() {
  if (scanf("%d%d%d", &n[0], &n[1], &n[2]) < 3) {
    return false;
  }
  for (int t = 0; t < 3; t++) {
    for (int i = 0; i < n[t]; i++) {
      scanf("%d", &a[t][i]);
    }
  }
  return true;
}

int p[4];

long long get(long long x, long long y, long long z) {
  return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
}

void solve() {
  for (int t = 0; t < 3; t++) {
    sort(a[t], a[t] + n[t]);
  }
  for (int i = 0; i < 3; i++) {
    p[i] = i;
  }
  long long res = 3 * infll;
  while (true) {
    for (int i = -1, j = 0, k = 0; j < n[p[1]]; j++) {
      while (i + 1 < n[p[0]] && a[p[0]][i + 1] <= a[p[1]][j]) {
        i++;
      }
      while (k < n[p[2]] && a[p[2]][k] < a[p[1]][j]) {
        k++;
      }
      if (i >= 0 && k < n[p[2]]) {
        res = min(res, get(a[p[0]][i], a[p[1]][j], a[p[2]][k]));
      }
    }
    if (!next_permutation(p, p + 3)) {
      break;
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