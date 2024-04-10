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

const int maxn = 6005;
int n;
int xs[maxn], ys[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &xs[i], &ys[i]);
    xs[i] /= 2;
    ys[i] /= 2;
  }
  return true;
}

void solve() {
  long long x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    int cnt[2] = {0, 0};
    for (int j = 0; j < n; ++j) {
      if (j == i) {
        continue;
      }
      int dx = xs[j] - xs[i], dy = ys[j] - ys[i];
      if ((dx & 1) || (dy & 1)) {
        ++cnt[1];
      } else {
        ++cnt[0];
      }
    }
    x += cnt[0] * (cnt[0] - 1) / 2;
    y += cnt[0] * cnt[1];
  }
  x /= 3;
  y /= 2;
  printf("%lld\n", x + y);
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