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

const int maxn = (int) 1e5 + 5;
int n, k;
pair<int, pair<int, int> > p[maxn];

int read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &p[i].second.first, &p[i].first, &p[i].second.second);
  }
  return true;
}

struct node {
  int x, y;
  int ts;
  node *l, *r;

  node(int _x): x(_x), y(mrand()), ts(1), l(0), r(0) {}
};

node *root[maxn];

void recalc(node *v) {
  v->ts = 1;
  if (v->l) {
    v->ts += v->l->ts;
  }
  if (v->r) {
    v->ts += v->r->ts;
  }
}

node *merge(node *l, node *r) {
  if (!l) {
    return r;
  }
  if (!r) {
    return l;
  }
  if (l->y < r->y) {
    l->r = merge(l->r, r);
    recalc(l);
    return l;
  } else {
    r->l = merge(l, r->l);
    recalc(r);
    return r;
  }
}

void split(node *v, int x, node *&l, node *&r) {
  if (!v) {
    l = 0;
    r = 0;
    return;
  }
  if (x <= v->x) {
    split(v->l, x, l, v->l);
    recalc(v);
    r = v;
  } else {
    split(v->r, x, v->r, r);
    recalc(v);
    l = v;
  }
}

int get(node *&v, int l, int r) {
  node *lv, *mv, *rv;
  split(v, l, lv, mv);
  split(mv, r, mv, rv);
  int res = (mv ? mv->ts : 0);
  v = merge(merge(lv, mv), rv);
  return res;
}

void add(node *&v, int x) {
  node *lv, *rv;
  split(v, x, lv, rv);
  v = merge(merge(lv, new node(x)), rv);
}

void solve() {
  for (int i = 0; i < maxn; i++) {
    root[i] = 0;
  }
  sort(p, p + n);
  long long res = 0;
  for (int i = n - 1; i >= 0; i--) {
    int r = p[i].first, x = p[i].second.first, f = p[i].second.second;
    for (int ff = max(0, f - k); ff <= f + k; ff++) {
      res += get(root[ff], x - r, x + r + 1);
    }
    add(root[f], x);
  }
  printf("%lld\n", res);
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