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
int h[maxn];
int b[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &h[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }
  return true;
}

struct node {
  long long val, toadd;
};

node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v].val = 0;
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

void update(int v, int tl, int tr, int l, int r, long long toadd) {
  if (l == tl && r == tr) {
    st[v].val += toadd;
    st[v].toadd += toadd;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    update(2 * v, tl, tm, l, min(r, tm), toadd);
  }
  if (r > tm) {
    update(2 * v + 1, tm, tr, max(l, tm), r, toadd);
  }
  st[v].val = max(st[2 * v].val, st[2 * v + 1].val);
}

long long get(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v].val;
  }
  push(v);
  int tm = (tl + tr) / 2;
  long long res = -infll;
  if (l < tm) {
    res = max(res, get(2 * v, tl, tm, l, min(r, tm)));
  }
  if (r > tm) {
    res = max(res, get(2 * v + 1, tm, tr, max(l, tm), r));
  }
  return res;
}

long long dp[maxn];
vector<int> stck;

void solve() {
  buildst(1, 0, n);
  dp[0] = 0;
  stck.clear();
  stck.push_back(-1);
  for (int i = 0; i < n; ++i) {
    while (stck.back() >= 0 && h[i] < h[stck.back()]) {
      int l = stck[sz(stck) - 2] + 1, r = stck.back() + 1;
      long long toadd = b[i] - b[stck.back()];
      update(1, 0, n, l, r, toadd);
      stck.pop_back();
    }
    stck.push_back(i);
    update(1, 0, n, i, i + 1, dp[i] + b[i]);
    dp[i + 1] = get(1, 0, n, 0, i + 1);
  }
  printf("%lld\n", dp[n]);
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