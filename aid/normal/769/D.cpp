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

const int maxx = (int) 1e4 + 5;
int n, k;
int a[maxx];
int popcnt[2 * maxx];

void precalc() {
  for (int i = 0; i < 2 * maxx; i++) {
    popcnt[i] = __builtin_popcount(i);
  }
}

int read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[x]++;
  }
  return true;
}

void solve() {
  long long res = 0;
  if (!k) {
    for (int i = 0; i < maxx; i++) {
      res += (long long) a[i] * (a[i] - 1) / 2;
    }
  } else {
    for (int i = 0; i < maxx; i++) {
      if (!a[i]) {
        continue;
      }
      for (int j = i + 1; j < maxx; j++) {
        if (popcnt[i ^ j] == k) {
          res += (long long) a[i] * a[j];
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