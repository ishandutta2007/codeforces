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
char tmp[maxn];
int n, q;
string t, s;
int qs[maxn][2];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  scanf("%s", tmp);
  t = tmp;
  scanf("%s", tmp);
  s = tmp;
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &qs[i][0], &qs[i][1]);
    --qs[i][0];
  }
  return true;
}

struct node {
  int upd, sum, len;
};

node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v].upd = -1;
  st[v].len = tr - tl;
  if (tl == tr - 1) {
    st[v].sum = (s[tl] - '0');
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  st[v].sum = st[2 * v].sum + st[2 * v + 1].sum;
}

void updateNode(int v, int x) {
  st[v].upd = x;
  st[v].sum = st[v].len * x;
}

void push(int v) {
  if (st[v].upd == -1) {
    return;
  }
  for (int i = 0; i < 2; ++i) {
    int u = 2 * v + i;
    updateNode(u, st[v].upd);
  }
  st[v].upd = -1;
}

int get(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v].sum;
  }
  push(v);
  int tm = (tl + tr) / 2;
  int res = 0;
  if (l < tm) {
    res += get(2 * v, tl, tm, l, min(r, tm));
  }
  if (r > tm) {
    res += get(2 * v + 1, tm, tr, max(l, tm), r);
  }
  return res;
}

void update(int v, int tl, int tr, int l, int r, int x) {
  if (l == tl && r == tr) {
    updateNode(v, x);
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    update(2 * v, tl, tm, l, min(r, tm), x);
  }
  if (r > tm) {
    update(2 * v + 1, tm, tr, max(l, tm), r, x);
  }
  st[v].sum = st[2 * v].sum + st[2 * v + 1].sum;
}

bool check(int v, int tl, int tr) {
  if (tl == tr - 1) {
    return st[v].sum == (t[tl] - '0');
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (!check(2 * v, tl, tm) || !check(2 * v + 1, tm, tr)) {
    return false;
  }
  return true;
}

void solve() {
  buildst(1, 0, n);
  for (int i = q - 1; i >= 0; --i) {
    int l = qs[i][0], r = qs[i][1];
    int s = get(1, 0, n, l, r);
    if (2 * s == (r - l)) {
      printf("NO\n");
      return;
    }
    if (2 * s < r - l) {
      update(1, 0, n, l, r, 0);
    } else {
      update(1, 0, n, l, r, 1);
    }
  }
  if (!check(1, 0, n)) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
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