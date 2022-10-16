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

int sgn(int x) {
  return (x > 0) - (x < 0);
}

int ask(int x) {
  printf("? %d\n", x + 1);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  return res;
}

int get(int x) {
  return ask(x + n) - ask(x);
}

void solve() {
  n /= 2;
  int val = get(0);
  if (val & 1) {
    printf("! -1\n");
    fflush(stdout);
    return;
  }
  if (!val) {
    printf("! %d\n", 1);
    fflush(stdout);
    return;
  }
  int l = 0, r = n;
  while (true) {
    int m = (l + r) / 2;
    int cur = get(m);
    if (!cur) {
      printf("! %d\n", m + 1);
      fflush(stdout);
      return;
    }
    if (sgn(cur) == sgn(val)) {
      l = m;
    } else {
      r = m;
    }
  }
}

int main() {
  precalc();
  read();
  solve();
#ifdef DEBUG
  eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}