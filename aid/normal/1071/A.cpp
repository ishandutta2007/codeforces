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

long long a, b;

int read() {
  if (scanf("%lld%lld", &a, &b) < 2) {
    return false;
  }
  return true;
}

void solve() {
  long long s = a + b;
  int n = 0;
  while ((long long) (n + 1) * (n + 2) / 2 <= s) {
    n++;
  }
  vector<int> p, q;
  while (n) {
    if (a > (long long) (n - 1) * n / 2) {
      a -= n;
      p.push_back(n);
    } else {
      b -= n;
      q.push_back(n);
    }
    n--;
  }
  assert(a >= 0 && b >= 0);
  printf("%d\n", sz(p));
  for (int i = 0; i < sz(p); i++) {
    printf("%d ", p[i]);
  }
  printf("\n");
  printf("%d\n", sz(q));
  for (int i = 0; i < sz(q); i++) {
    printf("%d ", q[i]);
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