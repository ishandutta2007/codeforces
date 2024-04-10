#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
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

int n, a, b;

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%d%*c%d", &a, &b);
  return true;
}

int getD(int x, int y) {
  return (x / 10 != y / 10) + (x % 10 != y % 10);
}

void solve() {
  int ansa = -1, ansb = -1, d = inf;
  if (n == 12) {
    for (int h = 1; h <= 12; h++) {
      for (int m = 0; m < 60; m++) {
        int curd = getD(h, a) + getD(m, b);
        if (curd < d) {
          ansa = h;
          ansb = m;
          d = curd;
        }
      }
    }
  } else {
    for (int h = 0; h < 24; h++) {
      for (int m = 0; m < 60; m++) {
        int curd = getD(h, a) + getD(m, b);
        if (curd < d) {
          ansa = h;
          ansb = m;
          d = curd;
        }
      }
    }
  }
  printf("%02d:%02d\n", ansa, ansb);
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}