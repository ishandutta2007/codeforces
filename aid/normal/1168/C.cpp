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

const int maxn = (int) 3e5 + 5;
int n, q;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

const int logn = 20;
int st[4 * maxn][logn];

void buildst(int v, int tl, int tr) {
  if (tl == tr - 1) {
    for (int bit = 0; bit < logn; bit++) {
      if (a[tl] & (1 << bit)) {
        st[v][bit] = a[tl];
      } else {
        st[v][bit] = (1 << bit);
      }
    }
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  for (int bit = 0; bit < logn; bit++) {
    int msk = st[2 * v][bit];
    auto &cur = st[v][bit];
    cur = 0;
    for (int i = 0; i < logn; i++) {
      if (msk & (1 << i)) {
        cur |= st[2 * v + 1][i];
      }
    }
  }
}

int get(int v, int tl, int tr, int l, int r, int x) {
  if (l == tl && r == tr) {
    int res = 0;
    for (int i = 0; i < logn; i++) {
      if (x & (1 << i)) {
        res |= st[v][i];
      }
    }
    return res;
  }
  int tm = (tl + tr) / 2;
  if (l < tm) {
    x = get(2 * v, tl, tm, l, min(r, tm), x);
  }
  if (r > tm) {
    x = get(2 * v + 1, tm, tr, max(l, tm), r, x);
  }
  return x;
}

void solve() {
  buildst(1, 0, n);
  for (int qq = 0; qq < q; qq++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    if (x == y - 1) {
      printf((a[x] & a[y]) ? "Shi\n" : "Fou\n");
      continue;
    }
    printf((get(1, 0, n, x + 1, y, a[x]) & a[y]) ? "Shi\n" : "Fou\n");
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