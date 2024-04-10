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
int n, m, p;
pair<int, int> a[maxn], b[maxn];
pair<pair<int, int>, int> x[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &m, &p) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i].first, &a[i].second);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &b[i].first, &b[i].second);
  }
  for (int i = 0; i < p; i++) {
    scanf("%d%d%d", &x[i].first.first, &x[i].first.second, &x[i].second);
  }
  return true;
}

struct node {
  long long val, toadd;
};

node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v].toadd = 0;
  if (tl == tr - 1) {
    st[v].val = -b[tl].second;
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  st[v].val = max(st[2 * v].val, st[2 * v + 1].val);
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

void add(int v, int tl, int tr, int l, int r, int x) {
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
  st[v].val = max(st[2 * v].val, st[2 * v + 1].val);
}

void addMonster(int x, int c) {
  int pos = lower_bound(b, b + m, make_pair(x + 1, -1)) - b;
  if (pos >= m) {
    return;
  }
  add(1, 0, m, pos, m, c);
}

void solve() {
  sort(a, a + n);
  sort(b, b + m);
  sort(x, x + p);
  buildst(1, 0, m);
  long long res = -infll;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < p && x[j].first.first < a[i].first) {
      addMonster(x[j].first.second, x[j].second);
      j++;
    }
    res = max(res, st[1].val - a[i].second);
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