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
int n, m;
long long t;
int a[maxn];

int read() {
  if (scanf("%d%d%lld", &n, &m, &t) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

vector<int> evs[maxn];

pair<int, long long> st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v] = make_pair(0, 0ll);
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void update(int v, int tl, int tr, int id) {
  if (tl == tr - 1) {
    st[v] = make_pair(1, (long long) a[id]);
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

int get(int v, int tl, int tr, long long &t) {
  if (!t) {
    return 0;
  }
  if (st[v].second <= t) {
    t -= st[v].second;
    return st[v].first;
  }
  if (tl == tr - 1) {
    t = 0;
    return 0;
  }
  int tm = (tl + tr) / 2;
  int res = 0;
  res += get(2 * v, tl, tm, t);
  res += get(2 * v + 1, tm, tr, t);
  return res;
}

long long get1(int v, int tl, int tr, int &k) {
  if (!k) {
    return 0ll;
  }
  if (st[v].first <= k) {
    k -= st[v].first;
    return st[v].second;
  }
  int tm = (tl + tr) / 2;
  long long res = 0;
  res += get1(2 * v, tl, tm, k);
  res += get1(2 * v + 1, tm, tr, k);
  return res;
}

void solve() {
  vector<int> as;
  for (int i = 0; i < n; i++) {
    evs[a[i]].push_back(i);
    as.push_back(a[i]);
  }
  sort(as.begin(), as.end());
  as.erase(unique(as.begin(), as.end()), as.end());
  buildst(1, 0, n);
  int ansk = 0, ansd = 1;
  for (int it = 0; it < sz(as); it++) {
    int d = as[it];
    for (int i = 0; i < sz(evs[d]); i++) {
      update(1, 0, n, evs[d][i]);
    }
    long long curt = t / 2;
    int k2 = get(1, 0, n, curt);
    k2 -= k2 % m;
    int curk = k2;
    curt = t - get1(1, 0, n, curk);
    int k = get(1, 0, n, curt);
    k = min(k, k2 + m);
    if (k > ansk) {
      ansk = k;
      ansd = d;
    }
  }
  for (int i = 0; i < n; i++) {
    evs[a[i]].clear();
  }
  printf("%d %d\n", ansk, ansd);
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