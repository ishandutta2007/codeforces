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
int n, q;
int p[maxn];
int qs[maxn][4];

int read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  for (int i = 0; i < q; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &qs[i][j]);
      if (j < 2) {
        qs[i][j]--;
      }
    }
  }
  return true;
}

long long ans[maxn];
int val[4 * maxn];
vector< pair<pair<int, int>, pair<int, int> > > evs[maxn];
int fen[maxn];

void update(int x, int toadd) {
  for (; x < n; x |= (x + 1)) {
    fen[x] += toadd;
  }
}

int get(int x) {
  int res = 0;
  for (; x >= 0; x = (x & (x + 1)) - 1) {
    res += fen[x];
  }
  return res;
}

void solve() {
  for (int i = 0; i <= n; i++) {
    evs[i].clear();
  }
  for (int i = 0; i < q; i++) {
    int x0 = qs[i][0], y0 = qs[i][1], x1 = qs[i][2], y1 = qs[i][3];
    ans[i] = (long long) n * (n - 1) / 2;
    ans[i] -= (long long) x0 * (x0 - 1) / 2;
    ans[i] -= (long long) y0 * (y0 - 1) / 2;
    ans[i] -= (long long) (n - x1) * (n - x1 - 1) / 2;
    ans[i] -= (long long) (n - y1) * (n - y1 - 1) / 2;
    for (int j = 0; j < 4; j++) {
      val[i * 4 + j] = 0;
    }
    evs[x0].push_back(make_pair(make_pair(0, y0), make_pair(i * 4, 1)));
    evs[x0].push_back(make_pair(make_pair(y1, n), make_pair(i * 4 + 1, 1)));
    evs[x1].push_back(make_pair(make_pair(0, y0), make_pair(i * 4 + 2, -1)));
    evs[n].push_back(make_pair(make_pair(0, y0), make_pair(i * 4 + 2, 1)));
    evs[x1].push_back(make_pair(make_pair(y1, n), make_pair(i * 4 + 3, -1)));
    evs[n].push_back(make_pair(make_pair(y1, n), make_pair(i * 4 + 3, 1)));
  }
  for (int i = 0; i < n; i++) {
    fen[i] = 0;
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < sz(evs[i]); j++) {
      int l = evs[i][j].first.first, r = evs[i][j].first.second, id = evs[i][j].second.first, sgn = evs[i][j].second.second;
      if (l >= r) {
        continue;
      }
      val[id] += sgn * (get(r - 1) - get(l - 1));
    }
    if (i < n) {
      update(p[i], 1);
    }
  }
  for (int i = 0; i < 4 * q; i++) {
    ans[i / 4] += (long long) val[i] * (val[i] - 1) / 2;
  }
  for (int i = 0; i < q; i++) {
    printf("%lld\n", ans[i]);
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