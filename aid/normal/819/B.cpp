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

const int maxn = (int) 1e6 + 5;
int n;
int p[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  return true;
}

struct node {
  int val, pos, toadd;
};

node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v].val = inf;
  st[v].pos = tl;
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
  for (int it = 0; it < 2; it++) {
    int u = 2 * v + it;
    st[u].toadd += st[v].toadd;
    st[u].val += st[v].toadd;
  }
  st[v].toadd = 0;
}

void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr - 1) {
    st[v].val = val;
    st[v].pos = tl;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    update(2 * v, tl, tm, pos, val);
  } else {
    update(2 * v + 1, tm, tr, pos, val);
  }
  if (st[2 * v].val < st[2 * v + 1].val) {
    st[v].val = st[2 * v].val;
    st[v].pos = st[2 * v].pos;
  } else {
    st[v].val = st[2 * v + 1].val;
    st[v].pos = st[2 * v + 1].pos;
  }
}

bool del0(int v, int tl, int tr) {
  if (st[v].val) {
    return false;
  }
  if (tl == tr - 1) {
    st[v].val = inf;
    st[v].pos = tl;
    return true;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (!del0(2 * v, tl, tm)) {
    if (!del0(2 * v + 1, tm, tr)) {
      assert(false);
    }
  }
  if (st[2 * v].val < st[2 * v + 1].val) {
    st[v].val = st[2 * v].val;
    st[v].pos = st[2 * v].pos;
  } else {
    st[v].val = st[2 * v + 1].val;
    st[v].pos = st[2 * v + 1].pos;
  }
  return true;
}

void solve() {
  buildst(1, 0, n);
  long long cur = 0;
  int cntup = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] <= i) {
      cur += i - p[i];
      cntup++;
    } else {
      cur += p[i] - i;
      update(1, 0, n, i, p[i] - i);
    }
  }
  long long res = cur;
  int ans = 0;
  for (int i = 0; i + 1 < n; i++) {
    cur += (cntup - 1) - (n - cntup);
    int pos = n - i - 1;
    cur -= n - 1 - p[pos];
    cur += p[pos];
    cntup--;
    st[1].toadd--;
    st[1].val--;
    update(1, 0, n, pos, p[pos]);
    while (del0(1, 0, n)) {
      cntup++;
    }
    if (cur < res) {
      res = cur;
      ans = i + 1;
    }
  }
  printf("%lld %d\n", res, ans);
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