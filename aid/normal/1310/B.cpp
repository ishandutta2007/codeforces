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

const int maxn = 17, pown = (1 << maxn);
int n, k;
int a[pown];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < (1 << n); i++) {
    a[i] = false;
  }
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    x--;
    a[x] = true;
  }
  return true;
}

vector<int> rec(int l, int r) {
  if (l + 2 == r) {
    int cnt = a[l] + a[l + 1];
    if (cnt == 0) {
      return {0, -inf, -inf, -inf};
    } else if (cnt == 1) {
      return {-inf, 1, 1, -inf};
    } else if (cnt == 2) {
      return {-inf, -inf, -inf, 1};
    }
  }
  int m = (l + r) / 2;
  auto pl = rec(l, m), pr = rec(m, r);
  vector<int> res(4, -inf);
  for (int ml = 0; ml < 4; ml++) {
    if (pl[ml] < 0) {
      continue;
    }
    for (int mr = 0; mr < 4; mr++) {
      if (pr[mr] < 0) {
        continue;
      }
      for (int win = 0; win < 8; win++) {
        int cur = pl[ml] + pr[mr];
        int wl = (ml & 1), wr = (mr & 1);
        int ll = ((ml >> 1) & 1), lr = ((mr >> 1) & 1);
        int w = ((win & 1) ? wl : wr);
        int l = ((win & 1) ? wr : wl);
        if (wl || wr) {
          cur++;
        }
        int w1 = ((win & 2) ? ll : lr);
        if (ll || lr) {
          cur++;
        }
        int w2 = ((win & 4) ? l : w1);
        if (l || w1) {
          cur++;
        }
        int msk = w + (w2 << 1);
        res[msk] = max(res[msk], cur);
      }
    }
  }
  return res;
}

void solve() {
  auto p = rec(0, (1 << n));
  int res = -inf;
  for (int i = 0; i < 4; i++) {
    res = max(res, p[i] + (i ? 1 : 0));
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