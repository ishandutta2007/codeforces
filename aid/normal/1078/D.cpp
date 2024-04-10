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

const int maxn = (int) 1e5 + 5;
int n;
int r[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &r[i]);
  }
  return true;
}

struct seg {
  int l, r;

  seg(): l(-1), r(-1) {}

  seg(int _l, int _r): l(_l), r(_r) {}

  seg operator + (const seg &s) const {
    assert(max(l, s.l) < min(r, s.r));
    return seg(min(l, s.l), max(r, s.r));
  }
};

const int logn = 20;
seg segs[maxn];
seg st[logn][4 * maxn];

void buildst(int t, int v, int tl, int tr) {
  if (tl == tr - 1) {
    st[t][v] = segs[tl];
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(t, 2 * v, tl, tm);
  buildst(t, 2 * v + 1, tm, tr);
  st[t][v] = st[t][2 * v] + st[t][2 * v + 1];
}

seg get(int t, int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[t][v];
  }
  int tm = (tl + tr) / 2;
  if (l < tm) {
    if (r > tm) {
      return get(t, 2 * v, tl, tm, l, tm) + get(t, 2 * v + 1, tm, tr, tm, r);
    } else {
      return get(t, 2 * v, tl, tm, l, r);
    }
  } else {
    return get(t, 2 * v + 1, tm, tr, l, r);
  }
}

seg getSeg(const seg &s, int t) {
  if (s.r - s.l >= n) {
    return s;
  }
  seg res = get(t, 1, 0, n, max(0, s.l), min(n, s.r));
  if (s.l < 0) {
    seg cur = get(t, 1, 0, n, n + s.l, n);
    cur.l -= n;
    cur.r -= n;
    res = res + cur;
  }
  if (s.r > n) {
    seg cur = get(t, 1, 0, n, 0, s.r - n);
    cur.l += n;
    cur.r += n;
    res = res + cur;
  }
  return res;
}

void solve() {
  if (n == 1) {
    printf("0\n");
    return;
  }
  for (int i = 0; i < n; i++) {
    segs[i] = seg(i - r[i], i + r[i] + 1);
  }
  buildst(0, 1, 0, n);
  for (int i = 1; i < logn; i++) {
    for (int j = 0; j < n; j++) {
      seg s = getSeg(seg(j, j + 1), i - 1);
      segs[j] = getSeg(s, i - 1);
    }
    buildst(i, 1, 0, n);
  }
  for (int i = 0; i < n; i++) {
    seg cur(i, i + 1);
    int res = 0;
    for (int j = logn - 1; j >= 0; j--) {
      seg nxt = getSeg(cur, j);
      if (nxt.r - nxt.l < n) {
        res += (1 << j);
        cur = nxt;
      }
    }
    res++;
    printf("%d ", res);
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