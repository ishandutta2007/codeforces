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
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

struct node {
  long long sum;
  int cnt;
  long long toadd;
};

node st[4 * maxn + 5];

void buildst(int v, int tl, int tr) {
  st[v].sum = 0;
  st[v].cnt = 0;
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
  for (int i = 0; i < 2; ++i) {
    int u = 2 * v + i;
    st[u].toadd += st[v].toadd;
  }
  st[v].toadd = 0;
}

void get(int v, int tl, int tr, int l, int r, int toadd, long long &sum, int &cnt) {
  if (l == tl && r == tr) {
    sum += st[v].sum;
    cnt += st[v].cnt;
    st[v].toadd += toadd;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    get(2 * v, tl, tm, l, min(r, tm), toadd, sum, cnt);
  }
  if (r > tm) {
    get(2 * v + 1, tm, tr, max(l, tm), r, toadd, sum, cnt);
  }
}

long long getAdd(int v, int tl, int tr, int pos) {
  if (tl == tr - 1) {
    return st[v].toadd;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    return getAdd(2 * v, tl, tm, pos);
  } else {
    return getAdd(2 * v + 1, tm, tr, pos);
  }
}

void add(int v, int tl, int tr, int pos) {
  if (tl == tr - 1) {
    st[v].sum += pos;
    ++st[v].cnt;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    add(2 * v, tl, tm, pos);
  } else {
    add(2 * v + 1, tm, tr, pos);
  }
  st[v].sum = st[2 * v].sum + st[2 * v + 1].sum;
  st[v].cnt = st[2 * v].cnt + st[2 * v + 1].cnt;
}

void solve() {
  buildst(1, 0, maxn);
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    res += (long long) x * i;
    res -= getAdd(1, 0, maxn, x);
    for (int j = 0; j * x < maxn; ++j) {
      int l = j * x, r = min(maxn, (j + 1) * x);
      long long sum = 0;
      int cnt = 0;
      get(1, 0, maxn, l, r, l, sum, cnt);
      res += sum - (long long) l * cnt;
    }
    add(1, 0, maxn, x);
    printf("%lld ", res);
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