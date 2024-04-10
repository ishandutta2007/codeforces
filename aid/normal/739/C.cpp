#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
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

const int maxn = (int) 3e5 + 5;
int n;
int a[maxn];
long long d[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

struct node {
  int val, pref, suff;
};

node st[4 * maxn];

void updateNode(int v, int tl, int tm, int tr) {
  st[v].val = max(st[2 * v].val, st[2 * v + 1].val);
  if (d[tm - 1] > 0 || d[tm] < 0) {
    st[v].val = max(st[v].val, st[2 * v].suff + st[2 * v + 1].pref);
  }
  if (st[2 * v].pref == tm - tl && (d[tm - 1] > 0 || d[tm] < 0)) {
    st[v].pref = tm - tl + st[2 * v + 1].pref;
  } else {
    st[v].pref = st[2 * v].pref;
  }
  if (st[2 * v + 1].suff == tr - tm && (d[tm - 1] > 0 || d[tm] < 0)) {
    st[v].suff = st[2 * v].suff + tr - tm;
  } else {
    st[v].suff = st[2 * v + 1].suff;
  }
}

void buildst(int v, int tl, int tr) {
  if (tl == tr - 1) {
    st[v].val = !!d[tl];
    st[v].pref = st[v].val;
    st[v].suff = st[v].val;
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  updateNode(v, tl, tm, tr);
}

void update(int v, int tl, int tr, int pos, int toadd) {
  if (tl == tr - 1) {
    d[tl] += toadd;
    st[v].val = !!d[tl];
    st[v].pref = st[v].val;
    st[v].suff = st[v].val;
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    update(2 * v, tl, tm, pos, toadd);
  } else {
    update(2 * v + 1, tm, tr, pos, toadd);
  }
  updateNode(v, tl, tm, tr);
}

void solve() {
  if (n == 1) {
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      int l, r, toadd;
      scanf("%d%d%d", &l, &r, &toadd);
      printf("1\n");
    }
    return;
  }
  for (int i = 0; i < n - 1; i++) {
    d[i] = a[i + 1] - a[i];
  }
  n--;
  buildst(1, 0, n);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int l, r, toadd;
    scanf("%d%d%d", &l, &r, &toadd);
    l--;
    if (l) {
      update(1, 0, n, l - 1, toadd);
    }
    if (r < n + 1) {
      update(1, 0, n, r - 1, -toadd);
    }
    printf("%d\n", st[1].val + 1);
  }
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}