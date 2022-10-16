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

const int maxn = (int) 1e5 + 5;
int n;
int a[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  return true;
}

int prv[maxn];
int lst[maxn];
vector<int> ps[maxn];

struct node {
  int val;
  node *l, *r;

  node(int _val): val(_val), l(0), r(0) {}

  node(node *_l, node *_r): val((_l ? _l->val : 0) + (_r ? _r->val : 0)), l(_l), r(_r) {}
};

node *buildst() {
  node *res = new node(0);
  for (int i = 0; i < 20; i++) {
    res = new node(res, res);
  }
  return res;
}

node *update(node *v, int tl, int tr, int pos, int val) {
  if (tl == tr - 1) {
    return new node(v->val + val);
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    return new node(update(v->l, tl, tm, pos, val), v->r);
  } else {
    return new node(v->l, update(v->r, tm, tr, pos, val));
  }
}

int get(node *v, int tl, int tr, int x) {
  if (tl == tr - 1) {
    if (v->val > x) {
      return tl;
    }
    return inf;
  }
  int tm = (tl + tr) / 2;
  if (v->l->val > x) {
    return get(v->l, tl, tm, x);
  } else {
    return get(v->r, tm, tr, x - v->l->val);
  }
}

node *st[maxn];

int solve(int k) {
  int pos = 0;
  int res = 0;
  while (pos < n) {
    int nxt = get(st[pos], 0, n, pos + k);
    res++;
    pos = nxt;
  }
  return res;
}

void solve() {
  for (int i = 0; i < n; i++) {
    lst[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    prv[i] = lst[a[i]];
    lst[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    ps[i].clear();
  }
  for (int i = 0; i < n; i++) {
    ps[prv[i] + 1].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if (!i) {
      st[i] = buildst();
    } else {
      st[i] = st[i - 1];
    }
    for (int j = 0; j < sz(ps[i]); j++) {
      st[i] = update(st[i], 0, n, ps[i][j], 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", solve(i));
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