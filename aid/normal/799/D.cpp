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

const int maxn = (int) 1e5 + 5;
int n;
int x, y, h, w;
int a[maxn];

int read() {
  if (scanf("%d%d%d%d%d", &x, &y, &h, &w, &n) < 5) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

void add(map<int, int> &ndp, int nx, int ny) {
  if (!ndp.count(nx)) {
    ndp[nx] = ny;
    return;
  }
  auto &val = ndp[nx];
  val = min(val, ny);
}

int solve1() {
  map<int, int> dp, ndp;
  dp[(x + w - 1) / w] = (y + h - 1) / h;
  for (int i = 0; i < n; i++) {
    ndp.clear();
    for (auto it = dp.begin(); it != dp.end(); it++) {
      int curx = it->first, cury = it->second;
      if (curx <= 1 && cury <= 1) {
        return i;
      }
      add(ndp, (curx + a[i] - 1) / a[i], cury);
      add(ndp, curx, (cury + a[i] - 1) / a[i]);
    }
    dp = ndp;
  }
  for (auto it = dp.begin(); it != dp.end(); it++) {
    int curx = it->first, cury = it->second;
    if (curx <= 1 && cury <= 1) {
      return n;
    }
  }
  return inf;
}

void solve() {
  sort(a, a + n, greater<int>());
  n = min(n, 50);
  int res = solve1();
  swap(x, y);
  res = min(res, solve1());
  if (res >= inf) {
    res = -1;
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