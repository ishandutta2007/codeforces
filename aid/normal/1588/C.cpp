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
  long long val, toadd;
  int cnt;
};

node st[2][4 * maxn];

void buildst(int t, int v, int tl, int tr) {
  st[t][v].val = 0;
  st[t][v].toadd = 0;
  st[t][v].cnt = tr - tl;
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(t, 2 * v, tl, tm);
  buildst(t, 2 * v + 1, tm, tr);
}

void push(int t, int v) {
  if (!st[t][v].toadd) {
    return;
  }
  for (int i = 0; i < 2; ++i) {
    int u = 2 * v + i;
    st[t][u].val += st[t][v].toadd;
    st[t][u].toadd += st[t][v].toadd;
  }
  st[t][v].toadd = 0;
}

void add(int t, int v, int tl, int tr, int l, int r, long long toadd) {
  if (l == tl && r == tr) {
    st[t][v].val += toadd;
    st[t][v].toadd += toadd;
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
  if (st[t][2 * v].val < st[t][2 * v + 1].val) {
    st[t][v].val = st[t][2 * v].val;
    st[t][v].cnt = st[t][2 * v].cnt;
  } else if (st[t][2 * v + 1].val < st[t][2 * v].val) {
    st[t][v].val = st[t][2 * v + 1].val;
    st[t][v].cnt = st[t][2 * v + 1].cnt;
  } else {
    st[t][v].val = st[t][2 * v].val;
    st[t][v].cnt = st[t][2 * v].cnt + st[t][2 * v + 1].cnt;
  }
}

int getNeg(int t, int v, int tl, int tr) {
  if (st[t][v].val >= 0) {
    return tl;
  }
  if (tl == tr - 1) {
    return tr;
  }
  push(t, v);
  int tm = (tl + tr) / 2;
  if (st[t][2 * v + 1].val < 0) {
    return getNeg(t, 2 * v + 1, tm, tr);
  }
  return getNeg(t, 2 * v, tl, tm);
}

pair<long long, int> get(int t, int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return make_pair(st[t][v].val, st[t][v].cnt);
  }
  push(t, v);
  int tm = (tl + tr) / 2;
  pair<long long, int> res = make_pair(infll, 0);
  if (l < tm) {
    auto p = get(t, 2 * v, tl, tm, l, min(r, tm));
    if (p.first < res.first) {
      res.first = p.first;
      res.second = 0;
    }
    if (p.first == res.first) {
      res.second += p.second;
    }
  }
  if (r > tm) {
    auto p = get(t, 2 * v + 1, tm, tr, max(l, tm), r);
    if (p.first < res.first) {
      res.first = p.first;
      res.second = 0;
    }
    if (p.first == res.first) {
      res.second += p.second;
    }
  }
  return res;
}

void solve() {
  long long res = 0;
  buildst(0, 1, 0, n);
  buildst(1, 1, 0, n);
  for (int i = 0; i < n; ++i) {
    add((i & 1), 1, 0, n, 0, i + 1, a[i]);
    add(!(i & 1), 1, 0, n, i, i + 1, infll);
    add(!(i & 1), 1, 0, n, 0, i + 1, -a[i]);
    int j = max(getNeg(0, 1, 0, n), getNeg(1, 1, 0, n));
    for (int t = 0; t < 2; ++t) {
      auto p = get(t, 1, 0, n, j, i + 1);
      if (p.first == 0) {
        res += p.second;
      }
    }
  }
  printf("%lld\n", res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}