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
int p[maxn], q[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &q[i]);
    q[i]--;
  }
  return true;
}

struct node {
  int val, toadd;
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
  for (int i = 0; i < 2; i++) {
    int u = 2 * v + i;
    st[u].val += st[v].toadd;
    st[u].toadd += st[v].toadd;
  }
  st[v].toadd = 0;
}

void update(int v, int tl, int tr, int l, int r, int x) {
  if (l == tl && r == tr) {
    st[v].val += x;
    st[v].toadd += x;
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
  st[v].val = max(st[2 * v].val, st[2 * v + 1].val);
}

int pinv[maxn];
int ans[maxn];

void solve() {
  buildst(1, 0, n);
  for (int i = 0; i < n; i++) {
    pinv[p[i]] = i;
  }
  for (int i = n - 1, j = 0; i >= 0; i--) {
    int pos = pinv[i];
    update(1, 0, n, 0, pos + 1, 1);
    while (j < n && st[1].val > 0) {
      ans[j] = i;
      update(1, 0, n, 0, q[j] + 1, -1);
      j++;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i] + 1);
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