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

int n, t, k, d;

int read() {
  if (scanf("%d%d%d%d", &n, &t, &k, &d) < 4) {
    return false;
  }
  return true;
}

void solve() {
  int t1 = (n + k - 1) / k * t;
  int t2 = 0;
  int cnt = 0;
  while (cnt < n) {
    t2++;
    if (!(t2 % t)) {
      cnt += k;
    }
    if (t2 > d && !((t2 - d) % t)) {
      cnt += k;
    }
  }
  if (t2 < t1) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
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