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

const int maxn = (int) 2e5 + 5;
int n;
long long s[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &s[i]);
  }
  return true;
}

struct node {
  long long val, toadd;
  int pos;
};

node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v].toadd = 0;
  if (tl == tr - 1) {
    st[v].val = s[tl];
    st[v].pos = tl;
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  if (st[2 * v].val < st[2 * v + 1].val) {
    st[v].val = st[2 * v].val;
    st[v].pos = st[2 * v].pos;
  } else {
    st[v].val = st[2 * v + 1].val;
    st[v].pos = st[2 * v + 1].pos;
  }
}

void push(int v) {
  if (!st[v].toadd) {
    return;
  }
  for (int i = 0; i < 2; i++) {
    int u = 2 * v + i;
    st[u].val += st[v].toadd;
    st[u].toadd += st[v].toadd;
  }
  st[v].toadd = 0;
}

void add(int v, int tl, int tr, int l, int r, long long x) {
  if (l == tl && r == tr) {
    st[v].val += x;
    st[v].toadd += x;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    add(2 * v, tl, tm, l, min(r, tm), x);
  }
  if (r > tm) {
    add(2 * v + 1, tm, tr, max(l, tm), r, x);
  }
  if (st[2 * v].val < st[2 * v + 1].val) {
    st[v].val = st[2 * v].val;
    st[v].pos = st[2 * v].pos;
  } else {
    st[v].val = st[2 * v + 1].val;
    st[v].pos = st[2 * v + 1].pos;
  }
}

int ans[maxn];

void solve() {
  buildst(1, 0, n);
  for (int x = 1; x <= n; x++) {
    int pos = st[1].pos;
    ans[pos] = x;
    add(1, 0, n, pos, pos + 1, infll);
    if (pos + 1 < n) {
      add(1, 0, n, pos + 1, n, -x);
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
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