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

int n, m, v;
vector<int> ls, es;

int read() {
  int cl, ce;
  if (scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v) < 5) {
    return false;
  }
  ls.clear();
  ls.resize(cl);
  es.clear();
  es.resize(ce);
  for (int it = 0; it < 2; it++) {
    auto &a = (!it ? ls : es);
    for (int i = 0; i < sz(a); i++) {
      scanf("%d", &a[i]);
      a[i]--;
    }
  }
  return true;
}

void solve() {
  int q;
  scanf("%d", &q);
  for (int it = 0; it < q; it++) {
    int x0, y0, x1, y1;
    scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
    x0--;
    y0--;
    x1--;
    y1--;
    if (x0 == x1) {
      printf("%d\n", abs(y1 - y0));
      continue;
    }
    int res = inf;
    for (int it = 0; it < 2; it++) {
      const auto &a = (!it ? ls : es);
      auto iter = lower_bound(a.begin(), a.end(), y0);
      if (iter != a.end()) {
        int y = *iter;
        res = min(res, abs(y - y0) + (!it ? abs(x1 - x0) : (abs(x1 - x0) + v - 1) / v) + abs(y1 - y));
      }
      if (iter != a.begin()) {
        iter--;
        int y = *iter;
        res = min(res, abs(y - y0) + (!it ? abs(x1 - x0) : (abs(x1 - x0) + v - 1) / v) + abs(y1 - y));
      }
    }
    printf("%d\n", res);
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