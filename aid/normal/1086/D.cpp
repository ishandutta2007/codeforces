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
int n, q;
int a[maxn];
char tmp[maxn];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  scanf("%s", tmp);
  for (int i = 0; i < n; i++) {
    a[i] = (tmp[i] == 'R' ? 0 : (tmp[i] == 'P' ? 1 : 2));
  }
  return true;
}

int fen[3][maxn];

void fenAdd(int t, int i, int val) {
  for (; i < n; i |= i + 1) {
    fen[t][i] += val;
  }
}

int fenGet(int t, int i) {
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res += fen[t][i];
  }
  return res;
}

set<int> st[3];
int ls[3], rs[3];

int get() {
  vector<int> ps;
  ps.push_back(0);
  ps.push_back(n);
  for (int i = 0; i < 3; i++) {
    if (st[i].empty()) {
      ls[i] = inf;
      rs[i] = -inf;
      continue;
    }
    ls[i] = *st[i].begin();
    rs[i] = *st[i].rbegin();
    ps.push_back(ls[i]);
    ps.push_back(rs[i]);
  }
  sort(ps.begin(), ps.end());
  ps.erase(unique(ps.begin(), ps.end()), ps.end());
  int res = 0;
  for (int i = 0; i + 1 < sz(ps); i++) {
    int p = ps[i];
    for (int x = 0; x < 3; x++) {
      int lx = (x + 1) % 3;
      int wx = (x + 2) % 3;
      if (ls[lx] <= p && p < ls[wx]) {
        continue;
      }
      if (p < rs[lx] && rs[wx] <= p) {
        continue;
      }
      res += fenGet(x, ps[i + 1] - 1);
      res -= fenGet(x, ps[i] - 1);
    }
  }
  return res;
}

void solve() {
  for (int i = 0; i < 3; i++) {
    st[i].clear();
  }
  memset(fen, 0, sizeof(fen));
  for (int i = 0; i < n; i++) {
    st[a[i]].insert(i);
    fenAdd(a[i], i, 1);
  }
  printf("%d\n", get());
  char tmp[10];
  for (int qq = 0; qq < q; qq++) {
    int p, x;
    scanf("%d%s", &p, tmp);
    p--;
    x = (tmp[0] == 'R' ? 0 : (tmp[0] == 'P' ? 1 : 2));
    int px = a[p];
    st[px].erase(p);
    fenAdd(px, p, -1);
    a[p] = x;
    st[x].insert(p);
    fenAdd(x, p, 1);
    printf("%d\n", get());
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