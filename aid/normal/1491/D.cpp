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

int a, b;

bool read() {
  if (scanf("%d%d", &a, &b) < 2) {
    return false;
  }
  return true;
}

const int maxb = 30;

void solve() {
  if (a > b || __builtin_popcount(a) < __builtin_popcount(b)) {
    printf("NO\n");
    return;
  }
  int todel = __builtin_popcount(a) - __builtin_popcount(b);
  bool fst = true;
  for (int bit = maxb - 1; bit >= 0 && todel; --bit) {
    if (!(a & (1 << bit))) {
      continue;
    }
    if (fst) {
      fst = false;
      continue;
    }
    a ^= (1 << bit);
    --todel;
  }
  int bal = 0;
  for (int bit = maxb - 1; bit >= 0; --bit) {
    if (b & (1 << bit)) {
      ++bal;
    }
    if (a & (1 << bit)) {
      --bal;
    }
    if (bal < 0) {
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
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