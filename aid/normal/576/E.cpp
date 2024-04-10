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

const int maxn = (int) 5e5 + 5;
int n, m, k, q;
int es[maxn][2];
int qs[maxn][2];

bool read() {
  if (scanf("%d%d%d%d", &n, &m, &k, &q) < 4) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &es[i][j]);
      es[i][j]--;
    }
  }
  for (int i = 0; i < q; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &qs[i][j]);
      qs[i][j]--;
    }
  }
  return true;
}

int lst[maxn];
int col[maxn];
vector<int> st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v].clear();
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void addEdge(int v, int tl, int tr, int l, int r, int e) {
  if (l == tl && r == tr) {
    st[v].push_back(e);
    return;
  }
  int tm = (tl + tr) / 2;
  if (l < tm) {
    addEdge(2 * v, tl, tm, l, min(r, tm), e);
  }
  if (r > tm) {
    addEdge(2 * v + 1, tm, tr, max(l, tm), r, e);
  }
}

const int maxk = 51;
int p[maxk][maxn], w[maxk][maxn], ts[maxk][maxn];
vector<pair<int, int>> stck[maxk];

pair<int, int> get(int c, int x) {
  if (p[c][x] == x) {
    return make_pair(x, 0);
  }
  pair<int, int> res = get(c, p[c][x]);
  res.second ^= w[c][x];
  return res;
}

bool unite(int c, int x, int y) {
  pair<int, int> rx = get(c, x), ry = get(c, y);
  x = rx.first;
  y = ry.first;
  if (x == y) {
    return rx.second != ry.second;
  }
  if (ts[c][x] < ts[c][y]) {
    swap(x, y);
  }
  ts[c][x] += ts[c][y];
  w[c][y] = (rx.second == ry.second);
  p[c][y] = x;
  stck[c].push_back(make_pair(x, y));
  return true;
}

void rollback(int c, int x, int y) {
  p[c][y] = y;
  w[c][y] = 0;
  ts[c][x] -= ts[c][y];
}

void solve(int v, int tl, int tr) {
  vector<int> was(k);
  for (int i = 0; i < k; i++) {
    was[i] = sz(stck[i]);
  }
  for (int i = 0; i < sz(st[v]); i++) {
    int e = st[v][i];
    if (col[e] != -1) {
      assert(unite(col[e], es[e][0], es[e][1]));
    }
  }
  if (tl == tr - 1) {
    if (tl + 1 < q) {
      int e = qs[tl + 1][0], c = qs[tl + 1][1];
      if (unite(c, es[e][0], es[e][1])) {
        col[e] = c;
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
  } else {
    int tm = (tl + tr) / 2;
    solve(2 * v, tl, tm);
    solve(2 * v + 1, tm, tr);
  }
  for (int i = 0; i < k; i++) {
    while (sz(stck[i]) > was[i]) {
      rollback(i, stck[i].back().first, stck[i].back().second);
      stck[i].pop_back();
    }
  }
}

void solve() {
  for (int i = 0; i < m; i++) {
    lst[i] = q;
    col[i] = -1;
  }
  buildst(1, 0, q);
  for (int i = q - 1; i >= 0; i--) {
    int e = qs[i][0];
    addEdge(1, 0, q, i, lst[e], e);
    lst[e] = i;
  }
  printf("YES\n");
  col[qs[0][0]] = qs[0][1];
  for (int c = 0; c < k; c++) {
    for (int i = 0; i < n; i++) {
      p[c][i] = i;
      w[c][i] = 0;
      ts[c][i] = 1;
    }
    stck[c].clear();
  }
  solve(1, 0, q);
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