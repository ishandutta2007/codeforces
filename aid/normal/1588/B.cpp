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

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

long long ask(int l, int r) {
  printf("? %d %d\n", l + 1, r);
  fflush(stdout);
  long long res;
  scanf("%lld", &res);
  if (res < 0) {
    exit(0);
  }
  return res;
}

int get(long long x) {
  int l = 0, r = n;
  while (l < r - 1) {
    int m = (l + r) / 2;
    if ((long long) m * (m - 1) / 2 > x) {
      r = m;
    } else {
      l = m;
    }
  }
  assert((long long) l * (l - 1) / 2 == x);
  return l;
}

void solve() {
  long long all = ask(0, n);
  int l = 0, r = n;
  long long p = -1;
  while (true) {
    int m = (l + r) / 2;
    long long x = ask(0, m);
    if (!x) {
      l = m;
      continue;
    }
    if (x == all) {
      r = m;
      continue;
    }
    long long y;
    int pos;
    if (p == -1) {
      y = ask(0, m + 1);
      int d = y - x;
      pos = m - d;
      if (y == (long long) d * (d + 1) / 2) {
        p = pos;
        l = m;
        continue;
      }
    } else {
      long long z = (m - p) * (m - p - 1) / 2;
      if (x == z) {
        l = m;
        continue;
      }
      y = ask(0, m + 1);
      int d = y - x;
      pos = m - d;
    }
    long long lval = ask(0, pos);
    int a = get(lval);
    int b = get(all - lval);
    printf("! %d %d %d\n", pos - a + 1, pos + 1, pos + b);
    fflush(stdout);
    break;
  }
}

int main() {
  precalc();
  int t;
  scanf("%d", &t);
  for (int tt = 0; tt < t; ++tt) {
    read();
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}