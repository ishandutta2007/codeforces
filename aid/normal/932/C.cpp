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

int n, a, b;

int read() {
  if (scanf("%d%d%d", &n, &a, &b) < 3) {
    return false;
  }
  return true;
}

void solve() {
  for (int x = 0; x * a <= n; x++) {
    if ((n - x * a) % b) {
      continue;
    }
    int y = (n - x * a) / b;
    int pos = 0;
    for (int i = 0; i < x; i++) {
      int pos0 = pos;
      for (int j = 0; j + 1 < a; j++) {
        printf("%d ", pos + 2);
        pos++;
      }
      printf("%d ", pos0 + 1);
      pos++;
    }
    for (int i = 0; i < y; i++) {
      int pos0 = pos;
      for (int j = 0; j + 1 < b; j++) {
        printf("%d ", pos + 2);
        pos++;
      }
      printf("%d ", pos0 + 1);
      pos++;
    }
    printf("\n");
    return;
  }
  printf("-1\n");
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