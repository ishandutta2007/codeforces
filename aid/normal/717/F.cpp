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

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define TASK "text"

const int inf = (int)1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld)-1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

struct Node {
  int odd, even;
  int updodd, updeven;
};

const int maxn = (int) 2e5 + 5;
int n;
int a[maxn];
Node st[4 * maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

void buildst(int v, int tl, int tr) {
  st[v].updodd = 0;
  st[v].updeven = 0;
  if (tl == tr - 1) {
    if (tl & 1) {
      st[v].odd = a[tl];
      st[v].even = inf;
    }
    else {
      st[v].odd = inf;
      st[v].even = a[tl];
    }
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  st[v].odd = min(st[2 * v].odd, st[2 * v + 1].odd);
  st[v].even = min(st[2 * v].even, st[2 * v + 1].even);
}

void push(int v) {
  if (st[v].updodd) {
    st[2 * v].updodd += st[v].updodd;
    st[2 * v].odd += st[v].updodd;
    st[2 * v + 1].updodd += st[v].updodd;
    st[2 * v + 1].odd += st[v].updodd;
    st[v].updodd = 0;
  }
  if (st[v].updeven) {
    st[2 * v].updeven += st[v].updeven;
    st[2 * v].even += st[v].updeven;
    st[2 * v + 1].updeven += st[v].updeven;
    st[2 * v + 1].even += st[v].updeven;
    st[v].updeven = 0;
  }
}

void update(int v, int tl, int tr, int l, int r, int addodd, int addeven) {
  if (l == tl && r == tr) {
    st[v].updodd += addodd;
    st[v].odd += addodd;
    st[v].updeven += addeven;
    st[v].even += addeven;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    update(2 * v, tl, tm, l, min(r, tm), addodd, addeven);
  }
  if (r > tm) {
    update(2 * v + 1, tm, tr, max(l, tm), r, addodd, addeven);
  }
  st[v].odd = min(st[2 * v].odd, st[2 * v + 1].odd);
  st[v].even = min(st[2 * v].even, st[2 * v + 1].even);
}

pair<int, int> get(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return make_pair(st[v].odd, st[v].even);
  }
  push(v);
  int tm = (tl + tr) / 2;
  pair<int, int> res = make_pair(inf, inf);
  if (l < tm) {
    pair<int, int> p = get(2 * v, tl, tm, l, min(r, tm));
    res.first = min(res.first, p.first);
    res.second = min(res.second, p.second);
  }
  if (r > tm) {
    pair<int, int> p = get(2 * v + 1, tm, tr, max(l, tm), r);
    res.first = min(res.first, p.first);
    res.second = min(res.second, p.second);
  }
  return res;
}

void solve() {
  for (int i = 1; i < n; i++) {
    a[i] = a[i] - a[i - 1];
  }
  for (int i = 1; i < n; i += 2) {
    a[i]--;
  }
  buildst(1, 0, n);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int l, r, k;
      scanf("%d%d%d", &l, &r, &k);
      r++;
      if (l & 1) {
        update(1, 0, n, l, r, k, 0);
      } else {
        update(1, 0, n, l, r, 0, k);
      }
      if ((l & 1) != (r & 1) && r < n) {
        if (r & 1) {
          update(1, 0, n, r, n, -k, k);
        } else {
          update(1, 0, n, r, n, k, -k);
        }
      }
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      r++;
      pair<int, int> p = get(1, 0, n, l, r);
      int ll = -1;
      if (l) {
        pair<int, int> pl = get(1, 0, n, l - 1, l);
        ll = ((l - 1) & 1)? pl.first : pl.second;
      }
      pair<int, int> pr = get(1, 0, n, r - 1, r);
      if (l & 1) {
        p.first += ll;
        p.second -= ll;
        pr.first += ll;
        pr.second -= ll;
      } else {
        p.first -= ll;
        p.second += ll;
        pr.first -= ll;
        pr.second += ll;
      }
      int rr = ((r - 1) & 1)? pr.first : pr.second;
      int ans = (p.first >= 0 && p.second >= 0 && rr == 0);
      printf("%d\n", ans);
    }
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
    eprintf("Time %.2f\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}