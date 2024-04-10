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

const int maxn = (int) 1e5 + 5;
char tmp[maxn];
int n, q;
string s;

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

int st[4 * maxn][3][3];

int go(int i, char c) {
  if (i == c - 'a') {
    ++i;
  }
  return i;
}

void recalcLeaf(int v, char c) {
  for (int i = 0; i < 3; ++i) {
    for (int j = i; j < 3; ++j) {
      st[v][i][j] = inf;
    }
    for (char cc = 'a'; cc <= 'c'; ++cc) {
      int j = go(i, cc);
      if (j >= 3) {
        continue;
      }
      auto &cur = st[v][i][j];
      cur = min(cur, (int) (cc != c));
    }
  }
}

void recalc(int v) {
  for (int i = 0; i < 3; ++i) {
    for (int j = i; j < 3; ++j) {
      auto &cur = st[v][i][j];
      cur = inf;
      for (int k = i; k <= j; ++k) {
        cur = min(cur, st[2 * v][i][k] + st[2 * v + 1][k][j]);
      }
    }
  }
}

void buildst(int v, int tl, int tr) {
  if (tl == tr - 1) {
    recalcLeaf(v, s[tl]);
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  recalc(v);
}

void update(int v, int tl, int tr, int pos, char c) {
  if (tl == tr - 1) {
    s[pos] = c;
    recalcLeaf(v, c);
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    update(2 * v, tl, tm, pos, c);
  } else {
    update(2 * v + 1, tm, tr, pos, c);
  }
  recalc(v);
}

void solve() {
  buildst(1, 0, n);
  for (int qq = 0; qq < q; ++qq) {
    int i;
    scanf("%d%s", &i, tmp);
    --i;
    char c = tmp[0];
    update(1, 0, n, i, c);
    int res = inf;
    for (int j = 0; j < 3; ++j) {
      res = min(res, st[1][0][j]);
    }
    printf("%d\n", res);
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