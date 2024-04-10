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

const int maxm = (int) 2e5 + 5, maxn = (int) 1e6 + 5;
int n, k, m;
int ls[maxm], rs[maxm], cs[maxm], ps[maxm];

int read() {
  if (scanf("%d%d%d", &n, &k, &m) < 3) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d%d", &ls[i], &rs[i], &cs[i], &ps[i]);
    ls[i]--;
  }
  return true;
}

pair<pair<int, int>, pair<int, int>> tosort[maxm];
vector<int> evs[maxn];
int alive[maxm];
pair<long long, long long> st[4 * maxm];

void buildst(int v, int tl, int tr) {
  st[v] = make_pair(0ll, 0ll);
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void update(int v, int tl, int tr, int id) {
  if (tl == tr - 1) {
    if (alive[id]) {
      st[v] = make_pair(0ll, 0ll);
    } else {
      st[v] = make_pair((long long) cs[id], (long long) cs[id] * ps[id]);
    }
    alive[id] = !alive[id];
    return;
  }
  int tm = (tl + tr) / 2;
  if (id < tm) {
    update(2 * v, tl, tm, id);
  } else {
    update(2 * v + 1, tm, tr, id);
  }
  st[v].first = st[2 * v].first + st[2 * v + 1].first;
  st[v].second = st[2 * v].second + st[2 * v + 1].second;
}

long long get(int v, int tl, int tr, int &k) {
  if (!k) {
    return 0;
  }
  if (st[v].first <= k) {
    k -= st[v].first;
    return st[v].second;
  }
  if (tl == tr - 1) {
    long long res = (long long) k * ps[tl];
    k = 0;
    return res;
  }
  int tm = (tl + tr) / 2;
  long long res = 0;
  res += get(2 * v, tl, tm, k);
  res += get(2 * v + 1, tm, tr, k);
  return res;
}

void solve() {
  for (int i = 0; i < m; i++) {
    tosort[i] = make_pair(make_pair(ps[i], cs[i]), make_pair(ls[i], rs[i]));
  }
  sort(tosort, tosort + m);
  for (int i = 0; i <= n; i++) {
    evs[i].clear();
  }
  for (int i = 0; i < m; i++) {
    ps[i] = tosort[i].first.first;
    cs[i] = tosort[i].first.second;
    ls[i] = tosort[i].second.first;
    rs[i] = tosort[i].second.second;
    alive[i] = false;
    evs[ls[i]].push_back(i);
    evs[rs[i]].push_back(i);
  }
  buildst(1, 0, m);
  long long res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < sz(evs[i]); j++) {
      int id = evs[i][j];
      update(1, 0, m, id);
    }
    int curk = k;
    res += get(1, 0, m, curk);
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