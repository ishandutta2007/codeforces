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

const int maxn = 4e4 + 5, maxk = 55;
int n, k;
int a[maxn];

int read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  return true;
}

struct node {
  int val, toadd;
};

node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v].val = -inf;
  st[v].toadd = 0;
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void push(int v) {
  if (!st[v].toadd) {
    return;
  }
  auto &toadd = st[v].toadd;
  for (int it = 0; it < 2; it++) {
    int u = 2 * v + it;
    st[u].val += toadd;
    st[u].toadd += toadd;
  }
  toadd = 0;
}

void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr - 1) {
    st[v].val = val;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    update(2 * v, tl, tm, pos, val);
  } else {
    update(2 * v + 1, tm, tr, pos, val);
  }
  st[v].val = max(st[2 * v].val, st[2 * v + 1].val);
}

void add(int v, int tl, int tr, int l, int r, int toadd) {
  if (l == tl && r == tr) {
    st[v].val += toadd;
    st[v].toadd += toadd;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    add(2 * v, tl, tm, l, min(r, tm), toadd);
  }
  if (r > tm) {
    add(2 * v + 1, tm, tr, max(l, tm), r, toadd);
  }
  st[v].val = max(st[2 * v].val, st[2 * v + 1].val);
}

int lst[maxn];
int prv[maxn];
int dp[maxn];
int ndp[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    lst[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    prv[i] = lst[a[i]];
    lst[a[i]] = i;
  }
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    dp[i + 1] = dp[i] + (prv[i] == -1);
  }
  for (int it = 1; it < k; it++) {
    buildst(1, 0, n);
    ndp[0] = -inf;
    for (int i = 0; i < n; i++) {
      update(1, 0, n, i, dp[i]);
      add(1, 0, n, prv[i] + 1, n, 1);
      int best = st[1].val;
      if (best < 0) {
        ndp[i + 1] = -inf;
      } else {
        ndp[i + 1] = best;
      }
    }
    swap(dp, ndp);
  }
  printf("%d\n", dp[n]);
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