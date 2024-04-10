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
int n, q;
int a[maxn];
vector<pair<int, int>> qs[maxn];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }
  for (int i = 0; i < n; ++i) {
    qs[i].clear();
  }
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    qs[l].push_back(make_pair(r, i));
  }
  return true;
}

int fen[maxn];

void fenAdd(int i, int x) {
  for (; i < n; i |= i + 1) {
    fen[i] += x;
  }
}

int fenGet(int i) {
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res += fen[i];
  }
  return res;
}

struct node {
  int val, toadd;
};

node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v].val = inf;
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
    st[u].val += st[v].toadd;
    st[u].toadd += st[v].toadd;
  }
  st[v].toadd = 0;
}

void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr - 1) {
    st[v].val = val;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    update(2 * v, tl, tm, pos, val);
  } else {
    update(2 * v + 1, tm, tr, pos, val);
  }
  st[v].val = min(st[2 * v].val, st[2 * v + 1].val);
}

void add(int v, int tl, int tr, int l, int r, int toadd) {
  if (l == tl && r == tr) {
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
  st[v].val = min(st[2 * v].val, st[2 * v + 1].val);
}

int get(int v, int tl, int tr) {
  if (st[v].val > 0) {
    return -1;
  }
  if (tl == tr - 1) {
    return tl;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (st[2 * v].val <= 0) {
    return get(2 * v, tl, tm);
  }
  if (st[2 * v + 1].val <= 0) {
    return get(2 * v + 1, tm, tr);
  }
  assert(false);
}

int ans[maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    fen[i] = 0;
  }
  buildst(1, 0, n);
  for (int i = n - 1; i >= 0; --i) {
    int x = i - a[i];
    if (x < 0) {
      x = inf;
    }
    update(1, 0, n, i, x);
    while (true) {
      int pos = get(1, 0, n);
      if (pos == -1) {
        break;
      }
      fenAdd(pos, 1);
      update(1, 0, n, pos, inf);
      add(1, 0, n, pos, n, -1);
    }
    for (int j = 0; j < sz(qs[i]); ++j) {
      int r = qs[i][j].first, id = qs[i][j].second;
      ans[id] = fenGet(n - r - 1);
    }
  }
  for (int i = 0; i < q; ++i) {
    printf("%d\n", ans[i]);
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