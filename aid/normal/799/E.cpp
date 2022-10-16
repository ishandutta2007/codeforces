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

const int maxn = (int) 2e5 + 5;
int n, m, k;
int c[maxn];
int msk[maxn];

int read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
    msk[i] = 0;
  }
  for (int t = 0; t < 2; t++) {
    int cnt;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++) {
      int x;
      scanf("%d", &x);
      x--;
      msk[x] |= (1 << t);
    }
  }
  return true;
}

pair<int, int> tosort[maxn];
int alive[maxn];
vector<int> cs[4];
long long p[4][maxn];

struct node {
  long long sum;
  int cnt;
};

node st[4 * maxn];

void updateNode(int v) {
  st[v].sum = st[2 * v].sum + st[2 * v + 1].sum;
  st[v].cnt = st[2 * v].cnt + st[2 * v + 1].cnt;
}

void buildst(int v, int tl, int tr) {
  if (tl == tr - 1) {
    if (alive[tl]) {
      st[v].sum = c[tl];
      st[v].cnt = 1;
    } else {
      st[v].sum = 0;
      st[v].cnt = 0;
    }
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  updateNode(v);
}

void update(int v, int tl, int tr, int pos) {
  if (tl == tr - 1) {
    st[v].sum = c[tl];
    st[v].cnt = 1;
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    update(2 * v, tl, tm, pos);
  } else {
    update(2 * v + 1, tm, tr, pos);
  }
  updateNode(v);
}

long long get(int v, int tl, int tr, int k) {
  if (tl == tr - 1) {
    if (!k) {
      return 0;
    } else if (k <= st[v].cnt) {
      return st[v].sum;
    } else {
      return infll;
    }
  }
  int tm = (tl + tr) / 2;
  if (st[2 * v].cnt >= k) {
    return get(2 * v, tl, tm, k);
  } else {
    return st[2 * v].sum + get(2 * v + 1, tm, tr, k - st[2 * v].cnt);
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(c[i], msk[i]);
  }
  sort(tosort, tosort + n);
  for (int i = 0; i < n; i++) {
    c[i] = tosort[i].first;
    msk[i] = tosort[i].second;
  }
  for (int t = 0; t < 4; t++) {
    cs[t].clear();
    for (int i = 0; i < n; i++) {
      if (msk[i] == t) {
        cs[t].push_back(i);
      }
    }
    p[t][0] = 0;
    for (int i = 0; i < sz(cs[t]); i++) {
      p[t][i + 1] = p[t][i] + c[cs[t][i]];
    }
  }
  long long res = infll;
  bool fst = true;
  for (int x = 0; x <= min(sz(cs[3]), m); x++) {
    if (k - x > sz(cs[1]) || k - x > sz(cs[2])) {
      continue;
    }
    if (fst) {
      for (int i = 0; i < n; i++) {
        alive[i] = (msk[i] != 3);
      }
      for (int i = 0; i < k - x; i++) {
        alive[cs[1][i]] = false;
        alive[cs[2][i]] = false;
      }
      buildst(1, 0, n);
      fst = false;
    } else {
      if (x <= k) {
        update(1, 0, n, cs[1][k - x]);
        update(1, 0, n, cs[2][k - x]);
      }
    }
    long long cur = infll;
    if (x <= k) {
      if (m - 2 * k + x >= 0) {
        cur = p[3][x] + p[1][k - x] + p[2][k - x] + get(1, 0, n, m - 2 * k + x);
      }
    } else {
      cur = p[3][x] + get(1, 0, n, m - x);
    }
    res = min(res, cur);
  }
  if (res >= infll) {
    res = -1;
  }
  printf("%lld\n", res);
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