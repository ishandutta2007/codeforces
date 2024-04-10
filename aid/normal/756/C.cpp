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
int n;

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

struct node {
  int val, pos, toadd;
};

node st[4 * maxn];
int x[maxn];

void buildst(int v, int tl, int tr) {
  st[v].val = 0;
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
  if (st[v].toadd != 0) {
    st[2 * v].val += st[v].toadd;
    st[2 * v].toadd += st[v].toadd;
    st[2 * v + 1].val += st[v].toadd;
    st[2 * v + 1].toadd += st[v].toadd;
    st[v].toadd = 0;
  }
}

void add(int v, int tl, int tr, int l, int r, int toadd) {
  if (tl == l && tr == r) {
    st[v].val += toadd;
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
  if (st[2 * v].val <= st[2 * v + 1].val) {
    st[v].val = st[2 * v].val;
    st[v].pos = st[2 * v].pos;
  } else {
    st[v].val = st[2 * v + 1].val;
    st[v].pos = st[2 * v + 1].pos;
  }
}

int getZero(int v, int tl, int tr, int pos) {
  if (pos <= tl) {
    if (st[v].val) {
      return n + 1;
    }
    return st[v].pos;
  }
  push(v);
  int tm = (tl + tr) / 2;
  int res = n + 1;
  if (pos < tm) {
    res = min(res, getZero(2 * v, tl, tm, pos));
  }
  res = min(res, getZero(2 * v + 1, tm, tr, pos));
  return res;
}

int get(int v, int tl, int tr, int pos) {
  if (tl == tr - 1) {
    return st[v].val;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    return get(2 * v, tl, tm, pos);
  } else {
    return get(2 * v + 1, tm, tr, pos);
  }
}

int getPos(int v, int tl, int tr, int x) {
  if (tl == tr - 1) {
    return tl;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (st[2 * v + 1].val < x) {
    return getPos(2 * v + 1, tm, tr, x);
  }
  return getPos(2 * v, tl, tm, x);
}

void solve() {
  buildst(1, 0, n + 1);
  set<int> b;
  set<int> used;
  for (int i = 0; i < n; i++) {
    int p, t;
    scanf("%d%d", &p, &t);
    p--;
    if (t) {
      scanf("%d", &x[p]);
      auto it = b.lower_bound(p);
      int l = p + 1, r = (it == b.end() ? n + 1 : *it + 1);
      add(1, 0, n + 1, l, r, 1);
      if (it != b.end()) {
        b.erase(it);
      }
    } else {
      int l = p + 1, r = getZero(1, 0, n + 1, p);
      if (l < r) {
        add(1, 0, n + 1, l, r, -1);
      }
      if (r <= n) {
        int pos = (r == p ? p : r - 1);
        b.insert(pos);
      }
    }
    used.insert(p);
    int bal = get(1, 0, n + 1, n);
    if (!bal) {
      printf("-1\n");
      continue;
    }
    int pos = *used.lower_bound(getPos(1, 0, n + 1, bal));
    printf("%d\n", x[pos]);
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