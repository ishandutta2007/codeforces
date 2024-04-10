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

const int maxn = (int) 1e5 + 5;
int n;
int a[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int l[maxn], r[maxn];
int fen[maxn];

int fenGet(int i) {
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res += fen[i];
  }
  return res;
}

void fenUpdate(int i, int toadd) {
  for (; i < n; i |= (i + 1)) {
    fen[i] += toadd;
  }
}

int pos[maxn];
vector<int> ps[maxn];

struct node {
  int res, l, li, r, ri, cnt, toadd;
};

vector<node> st[maxn];

void updateNode(int t, int v) {
  st[t][v].res = 0;
  st[t][v].l = 0;
  st[t][v].li = 0;
  st[t][v].r = 0;
  st[t][v].ri = 0;
  st[t][v].cnt = 0;
  for (int it = 0; it < 2; it++) {
    int u = 2 * v + it;
    add(st[t][v].res, st[t][u].res);
    add(st[t][v].l, st[t][u].l);
    add(st[t][v].li, st[t][u].li);
    add(st[t][v].r, st[t][u].r);
    add(st[t][v].ri, st[t][u].ri);
    add(st[t][v].cnt, st[t][u].cnt);
  }
  add(st[t][v].res, mul(st[t][2 * v].l, st[t][2 * v + 1].ri));
  add(st[t][v].res, mod - mul(st[t][2 * v].li, st[t][2 * v + 1].r));
  add(st[t][v].res, mod - mul(st[t][2 * v].l, st[t][2 * v + 1].r));
}

void buildst(int t, int v, int tl, int tr) {
  st[t][v].toadd = 0;
  if (tl == tr - 1) {
    int x = ps[t][tl];
    st[t][v].res = 0;
    st[t][v].l = l[x];
    st[t][v].li = mul(l[x], tl);
    st[t][v].r = r[x];
    st[t][v].ri = mul(r[x], tl);
    st[t][v].cnt = 1;
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(t, 2 * v, tl, tm);
  buildst(t, 2 * v + 1, tm, tr);
  updateNode(t, v);
}

void push(int t, int v) {
  if (st[t][v].toadd == 0) {
    return;
  }
  for (int it = 0; it < 2; it++) {
    int u = 2 * v + it;
    add(st[t][u].li, mul(st[t][v].toadd, st[t][u].l));
    add(st[t][u].ri, mul(st[t][v].toadd, st[t][u].r));
    add(st[t][u].toadd, st[t][v].toadd);
  }
  st[t][v].toadd = 0;
}

void update(int t, int v, int tl, int tr, int pos, int i, int tt) {
  if (tl == tr - 1) {
    if (tt) {
      int x = ps[t][tl];
      st[t][v].res = 0;
      st[t][v].l = l[x];
      st[t][v].li = mul(l[x], i);
      st[t][v].r = r[x];
      st[t][v].ri = mul(r[x], i);
      st[t][v].cnt = 1;
    } else {
      st[t][v].res = 0;
      st[t][v].l = 0;
      st[t][v].li = 0;
      st[t][v].r = 0;
      st[t][v].ri = 0;
      st[t][v].cnt = 0;
    }
    return;
  }
  push(t, v);
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    update(t, 2 * v, tl, tm, pos, i, tt);
  } else {
    update(t, 2 * v + 1, tm, tr, pos, i + st[t][2 * v].cnt, tt);
  }
  updateNode(t, v);
}

void add(int t, int v, int tl, int tr, int l, int r, int toadd) {
  if (l == tl && r == tr) {
    add(st[t][v].li, mul(toadd, st[t][v].l));
    add(st[t][v].ri, mul(toadd, st[t][v].r));
    add(st[t][v].toadd, toadd);
    return;
  }
  push(t, v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    add(t, 2 * v, tl, tm, l, min(r, tm), toadd);
  }
  if (r > tm) {
    add(t, 2 * v + 1, tm, tr, max(l, tm), r, toadd);
  }
  updateNode(t, v);
}

void solve() {
  int m;
  {
    vector<int> as;
    for (int i = 0; i < n; i++) {
      as.push_back(a[i]);
    }
    sort(as.begin(), as.end());
    as.erase(unique(as.begin(), as.end()), as.end());
    for (int i = 0; i < n; i++) {
      a[i] = lower_bound(as.begin(), as.end(), a[i]) - as.begin();
    }
    m = sz(as);
  }
  for (int i = 0; i < m; i++) {
    fen[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    l[i] = fenGet(a[i]);
    fenUpdate(a[i], 1);
  }
  for (int i = 0; i < m; i++) {
    fen[i] = 0;
  }
  for (int i = n - 1; i >= 0; i--) {
    r[i] = fenGet(a[i]);
    fenUpdate(a[i], 1);
  }
  for (int i = 0; i < m; i++) {
    ps[i].clear();
    st[i].clear();
  }
  for (int i = 0; i < n; i++) {
    pos[i] = sz(ps[a[i]]);
    ps[a[i]].push_back(i);
  }
  int res = 0;
  for (int i = 0; i < m; i++) {
    st[i].resize(4 * sz(ps[i]) + 10);
    buildst(i, 1, 0, sz(ps[i]));
    add(res, st[i][1].res);
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int t, x;
    scanf("%d%d", &t, &x);
    t--;
    x--;
    int id = a[x];
    int p = pos[x];
    add(res, mod - st[id][1].res);
    update(id, 1, 0, sz(ps[id]), p, 0, t);
    if (p + 1 < sz(ps[id])) {
      add(id, 1, 0, sz(ps[id]), p + 1, sz(ps[id]), (t ? 1 : mod - 1));
    }
    add(res, st[id][1].res);
    printf("%d\n", res);
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