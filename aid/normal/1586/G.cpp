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

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = (int) 4e5 + 5;
int n;
int a[maxn], b[maxn];
int need[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    --a[i];
    --b[i];
    need[i] = false;
  }
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; ++i) {
    int x;
    scanf("%d", &x);
    --x;
    need[x] = true;
  }
  return true;
}

struct node {
  int val, need;
};

node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v].val = 0;
  st[v].need = 0;
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

int getSum(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v].val;
  }
  int tm = (tl + tr) / 2;
  int res = 0;
  if (l < tm) {
    add(res, getSum(2 * v, tl, tm, l, min(r, tm)));
  }
  if (r > tm) {
    add(res, getSum(2 * v + 1, tm, tr, max(l, tm), r));
  }
  return res;
}

int getLast(int v, int tl, int tr, int l, int r) {
  if (!st[v].need) {
    return -1;
  }
  if (tl == tr - 1) {
    return tl;
  }
  int tm = (tl + tr) / 2;
  if (l >= tm) {
    return getLast(2 * v + 1, tm, tr, l, r);
  }
  if (r <= tm) {
    return getLast(2 * v, tl, tm, l, r);
  }
  int res = getLast(2 * v + 1, tm, tr, tm, r);
  if (res >= 0) {
    return res;
  }
  return getLast(2 * v, tl, tm, l, tm);
}

void update(int v, int tl, int tr, int pos, int val, int need) {
  if (tl == tr - 1) {
    add(st[v].val, val);
    st[v].need += need;
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    update(2 * v, tl, tm, pos, val, need);
  } else {
    update(2 * v + 1, tm, tr, pos, val, need);
  }
  st[v].val = st[2 * v].val;
  add(st[v].val, st[2 * v + 1].val);
  st[v].need = st[2 * v].need + st[2 * v + 1].need;
}

int dp[maxn];

int ids[maxn];
int del[maxn];
int srta[maxn], srtb[maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    ids[a[i]] = i;
    ids[b[i]] = i;
    del[i] = false;
    srta[i] = a[i];
    srtb[i] = b[i];
  }
  sort(srta, srta + n);
  sort(srtb, srtb + n);
  buildst(1, 0, 2 * n);
  for (int i = 0; i < n; ++i) {
    int id = ids[srtb[i]];
    dp[id] = getSum(1, 0, 2 * n, a[id], b[id]);
    add(dp[id], 1);
    update(1, 0, 2 * n, a[id], dp[id], need[id]);
  }
  buildst(1, 0, 2 * n);
  for (int i = 0; i < n; ++i) {
    update(1, 0, 2 * n, b[i], dp[i], need[i]);
  }
  int res = 0;
  int l = 0, r = 2 * n;
  int pa = 0, pb = n;
  while (true) {
    while (pa < n && srta[pa] < l) {
      int id = ids[srta[pa]];
      if (!del[id]) {
        update(1, 0, 2 * n, b[id], mod - dp[id], -need[id]);
        del[id] = true;
      }
      ++pa;
    }
    while (pb > 0 && srtb[pb - 1] >= r) {
      int id = ids[srtb[pb - 1]];
      if (!del[id]) {
        update(1, 0, 2 * n, b[id], mod - dp[id], -need[id]);
        del[id] = true;
      }
      --pb;
    }
    int p = getLast(1, 0, 2 * n, l, r);
    if (p < 0) {
      break;
    }
    add(res, getSum(1, 0, 2 * n, 0, p));
    add(res, 1);
    int id = ids[p];
    l = a[id];
    r = b[id];
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