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

const int maxn = (int) 2e5 + 5;
int n, l, r;
int a[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &l, &r) < 3) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    a[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    int c;
    scanf("%d", &c);
    --c;
    if (i < l) {
      ++a[c];
    } else {
      --a[c];
    }
  }
  return true;
}

void solve() {
  int bal = l - r;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    while (a[i] >= 2 && bal >= 2) {
      a[i] -= 2;
      bal -= 2;
      ++res;
    }
    while (a[i] <= -2 && bal <= -2) {
      a[i] += 2;
      bal += 2;
      ++res;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0 && bal > 0) {
      a[i] -= 2;
      bal -= 2;
      ++res;
    }
    if (a[i] < 0 && bal < 0) {
      a[i] += 2;
      bal += 2;
      ++res;
    }
  }
  for (int i = 0; i < n; ++i) {
    res += max(a[i], 0);
  }
  printf("%d\n", res);
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