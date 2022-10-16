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
int n, q;
long long a[maxn];
int ql[maxn], qr[maxn];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    long long x;
    scanf("%lld", &x);
    a[i] -= x;
    a[i] *= -1;
  }
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &ql[i], &qr[i]);
    --ql[i];
  }
  return true;
}

struct node {
  long long mn, mx, toadd;
};

node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v].mn = 0;
  st[v].mx = 0;
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
    st[u].mn += st[v].toadd;
    st[u].mx += st[v].toadd;
    st[u].toadd += st[v].toadd;
  }
  st[v].toadd = 0;
}

void add(int v, int tl, int tr, int l, int r, long long toadd) {
  if (l == tl && r == tr) {
    st[v].mn += toadd;
    st[v].mx += toadd;
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
  st[v].mn = min(st[2 * v].mn, st[2 * v + 1].mn);
  st[v].mx = max(st[2 * v].mx, st[2 * v + 1].mx);
}

void get(int v, int tl, int tr, int l, int r, long long &mn, long long &mx) {
  if (l == tl && r == tr) {
    mn = min(mn, st[v].mn);
    mx = max(mx, st[v].mx);
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    get(2 * v, tl, tm, l, min(r, tm), mn, mx);
  }
  if (r > tm) {
    get(2 * v + 1, tm, tr, max(l, tm), r, mn, mx);
  }
}

long long ans[maxn];
vector<int> qs[maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    qs[i].clear();
  }
  for (int i = 0; i < q; ++i) {
    qs[ql[i]].push_back(i);
  }
  buildst(1, 0, n + 1);
  for (int i = n - 1; i >= 0; --i) {
    add(1, 0, n + 1, i + 1, n + 1, a[i]);
    for (int j = 0; j < sz(qs[i]); ++j) {
      int id = qs[i][j];
      long long mn = infll, mx = -infll;
      get(1, 0, n + 1, qr[id], qr[id] + 1, mn, mx);
      if (mn) {
        ans[id] = -1;
        continue;
      }
      get(1, 0, n + 1, ql[id], qr[id] + 1, mn, mx);
      if (mn < 0) {
        ans[id] = -1;
        continue;
      }
      ans[id] = mx;
    }
  }
  for (int i = 0; i < q; ++i) {
    printf("%lld\n", ans[i]);
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