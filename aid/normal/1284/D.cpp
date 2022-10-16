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
int n;
int ls[2][maxn], rs[2][maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d%d", &ls[j][i], &rs[j][i]);
      rs[j][i]++;
    }
  }
  return true;
}

vector<int> xs[2];

struct node {
  int val, toadd;
};

node st[8 * maxn];

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

int get(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v].val;
  }
  push(v);
  int tm = (tl + tr) / 2, res = 0;
  if (l < tm) {
    res = max(res, get(2 * v, tl, tm, l, min(r, tm)));
  }
  if (r > tm) {
    res = max(res, get(2 * v + 1, tm, tr, max(l, tm), r));
  }
  return res;
}

vector<pair<int, pair<int, int>>> evs;

bool solve2() {
  evs.clear();
  for (int i = 0; i < n; i++) {
    evs.push_back(make_pair(ls[0][i], make_pair(1, i)));
    evs.push_back(make_pair(rs[0][i], make_pair(0, i)));
  }
  sort(evs.begin(), evs.end());
  buildst(1, 0, sz(xs[1]));
  for (int i = sz(evs) - 1; i >= 0; i--) {
    int id = evs[i].second.second;
    if (evs[i].second.first) {
      update(1, 0, sz(xs[1]), ls[1][id], rs[1][id], 1);
    } else {
      if (get(1, 0, sz(xs[1]), ls[1][id], rs[1][id])) {
        return true;
      }
    }
  }
  return false;
}

bool solve1() {
  for (int dir = 0; dir < 2; dir++) {
    if (solve2()) {
      return true;
    }
    for (int i = 0; i < n; i++) {
      int nl = sz(xs[0]) - rs[0][i], nr = sz(xs[0]) - ls[0][i];
      ls[0][i] = nl;
      rs[0][i] = nr;
    }
  }
  return false;
}

void solve() {
  for (int t = 0; t < 2; t++) {
    xs[t].clear();
    for (int i = 0; i < n; i++) {
      xs[t].push_back(ls[t][i]);
      xs[t].push_back(rs[t][i]);
    }
    sort(xs[t].begin(), xs[t].end());
    xs[t].erase(unique(xs[t].begin(), xs[t].end()), xs[t].end());
    for (int i = 0; i < n; i++) {
      ls[t][i] = lower_bound(xs[t].begin(), xs[t].end(), ls[t][i]) - xs[t].begin();
      rs[t][i] = lower_bound(xs[t].begin(), xs[t].end(), rs[t][i]) - xs[t].begin();
    }
  }
  for (int t = 0; t < 2; t++) {
    if (solve1()) {
      printf("NO\n");
      return;
    }
    for (int i = 0; i < n; i++) {
      swap(ls[0][i], ls[1][i]);
      swap(rs[0][i], rs[1][i]);
    }
    swap(xs[0], xs[1]);
  }
  printf("YES\n");
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