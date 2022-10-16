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

const int maxn = 1005;
int n, h;

int read() {
  if (scanf("%d%d", &n, &h) < 2) {
    return false;
  }
  return true;
}

ld ans[maxn];

void solve() {
  ans[n - 1] = h;
  for (int i = 0; i < n - 1; i++) {
    ans[n - 2 - i] = ans[n - 1 - i] * sqrt((ld) (n - i - 1) / (n - i));
  }
  for (int i = 0; i < n - 1; i++) {
    printf("%.12f ", (double) ans[i]);
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