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

const int maxn = (int) 1e5 + 5, X = (int) 1e9;
int n, m;
int xs[maxn];
int rs[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &xs[i]);
    xs[i]--;
  }
  int mm = 0;
  for (int i = 0; i < m; i++) {
    int l, r, y;
    scanf("%d%d%d", &l, &r, &y);
    l--;
    y--;
    if (!l) {
      rs[mm] = r;
      mm++;
    }
  }
  m = mm;
  return true;
}

void solve() {
  xs[n++] = X - 1;
  sort(xs, xs + n);
  sort(rs, rs + m);
  int res = inf;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < m && rs[j] <= xs[i]) {
      j++;
    }
    res = min(res, i + m - j);
  }
  printf("%d\n", res);
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