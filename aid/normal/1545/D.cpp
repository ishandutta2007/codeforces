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

const int maxn = 1005;
int n, k;
int xs[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 1) {
    return false;
  }
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &xs[i][j]);
    }
  }
  return true;
}

void getP(vector<long long> &p, long long xi, long long xj, long long y) {
  p[0] += xi * xj * y;
  p[1] -= (xi + xj) * y;
  p[2] += y;
}

void solve() {
  int lst = 0;
  for (int i = 0; i < n; ++i) {
    lst += xs[0][i];
  }
  int v = 0;
  for (int i = 0; i < n; ++i) {
    v += xs[k - 1][i];
  }
  v = (v - lst) / (k - 1);
  int t = 1, delta = 0;
  while (true) {
    int s = 0;
    for (int i = 0; i < n; ++i) {
      s += xs[t][i];
    }
    if (s != lst + v) {
      delta = lst + v - s;
      break;
    }
    lst = s;
    ++t;
  }
  vector<pair<long long, long long>> ps;
  for (int i = 0; sz(ps) < 3; ++i) {
    if (i == t) {
      continue;
    }
    long long cur = 0;
    for (int j = 0; j < n; ++j) {
      cur += (long long) xs[i][j] * xs[i][j];
    }
    ps.push_back(make_pair(i, cur));
  }
  vector<long long> qs = {(ps[0].first - ps[1].first) * (ps[0].first - ps[2].first),
                          (ps[1].first - ps[0].first) * (ps[1].first - ps[2].first),
                          (ps[2].first - ps[0].first) * (ps[2].first - ps[1].first)};
  vector<long long> p(3);
  getP(p, ps[1].first, ps[2].first, ps[0].second * qs[1] * qs[2]);
  getP(p, ps[0].first, ps[2].first, ps[1].second * qs[0] * qs[2]);
  getP(p, ps[0].first, ps[1].first, ps[2].second * qs[0] * qs[1]);
  long long need = p[0] + p[1] * t + p[2] * t * t;
  long long cur = 0;
  for (int i = 0; i < n; ++i) {
    cur += (long long) xs[t][i] * xs[t][i];
  }
  long long qq = qs[0] * qs[1] * qs[2];
  for (int i = 0; i < n; ++i) {
    cur -= (long long) xs[t][i] * xs[t][i];
    xs[t][i] += delta;
    cur += (long long) xs[t][i] * xs[t][i];
    if (cur * qq == need) {
      printf("%d %d\n", t, xs[t][i]);
      fflush(stdout);
      return;
    }
    cur -= (long long) xs[t][i] * xs[t][i];
    xs[t][i] -= delta;
    cur += (long long) xs[t][i] * xs[t][i];
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  read();
  solve();
#ifdef DEBUG
  eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}