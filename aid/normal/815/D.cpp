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

const int maxn = (int) 5e5 + 5;
int n, mx[3];
int xs[maxn][3];

int read() {
  if (scanf("%d%d%d%d", &n, &mx[0], &mx[1], &mx[2]) < 4) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &xs[i][j]);
      xs[i][j]--;
    }
  }
  return true;
}

int h[maxn];
long long s[maxn];
vector<int> evs[maxn];

void solve() {
  for (int i = 0; i < maxn; i++) {
    h[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    h[xs[i][1]] = max(h[xs[i][1]], xs[i][2]);
  }
  for (int i = maxn - 2; i >= 0; i--) {
    h[i] = max(h[i], h[i + 1]);
  }
  s[0] = 0;
  for (int i = 0; i + 1 < maxn; i++) {
    s[i + 1] = s[i] + h[i];
  }
  for (int i = 0; i < maxn; i++) {
    evs[i].clear();
  }
  for (int i = 0; i < n; i++) {
    evs[xs[i][0]].push_back(i);
  }
  int x0 = 0, y0 = 0;
  int l = 0, r = mx[1];
  long long res = 0;
  for (int i = mx[0] - 1; i >= 0; i--) {
    for (int j = 0; j < sz(evs[i]); j++) {
      int id = evs[i][j];
      x0 = max(x0, xs[id][1] + 1);
      y0 = max(y0, xs[id][2] + 1);
    }
    l = x0;
    r = max(l, r);
    while (l < r && h[r - 1] < y0) {
      r--;
    }
    long long was = res;
    res += (long long) (mx[1] - x0) * (mx[2] - y0) - ((s[r] - s[l]) - (long long) (r - l) * (y0 - 1));
  }
  printf("%lld\n", res);
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