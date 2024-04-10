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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e4 + 5;
int n, q;
int ls[maxn], rs[maxn], xs[maxn];

int read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < q; i++) {
    scanf("%d%d%d", &ls[i], &rs[i], &xs[i]);
    ls[i]--;
  }
  return true;
}

bitset<maxn> ans;
vector<int> evs[4 * maxn];

void buildst(int v, int tl, int tr) {
  evs[v].clear();
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void add(int v, int tl, int tr, int l, int r, int x) {
  if (l == tl && r == tr) {
    evs[v].push_back(x);
    return;
  }
  int tm = (tl + tr) / 2;
  if (l < tm) {
    add(2 * v, tl, tm, l, min(r, tm), x);
  }
  if (r > tm) {
    add(2 * v + 1, tm, tr, max(l, tm), r, x);
  }
}

void solve(int v, int tl, int tr, bitset<maxn> bs) {
  for (int i = 0; i < sz(evs[v]); i++) {
    bs |= (bs << evs[v][i]);
  }
  if (tl == tr - 1) {
    ans |= bs;
    return;
  }
  int tm = (tl + tr) / 2;
  solve(2 * v, tl, tm, bs);
  solve(2 * v + 1, tm, tr, bs);
}

void solve() {
  ans.reset();
  buildst(1, 0, n);
  for (int i = 0; i < q; i++) {
    add(1, 0, n, ls[i], rs[i], xs[i]);
  }
  bitset<maxn> bs;
  bs[0] = true;
  solve(1, 0, n, bs);
  vector<int> a;
  for (int i = 1; i <= n; i++) {
    if (ans[i]) {
      a.push_back(i);
    }
  }
  printf("%d\n", sz(a));
  for (int i = 0; i < sz(a); i++) {
    printf("%d ", a[i]);
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