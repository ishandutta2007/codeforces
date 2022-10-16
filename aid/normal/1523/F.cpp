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

struct point {
  int x, y;

  point(): x(0), y(0) {}

  point(int xx, int yy): x(xx), y(yy) {}

  point operator - (const point &p) const {
    return point(x - p.x, y - p.y);
  }

  int len() const {
    return abs(x) + abs(y);
  }

  bool operator < (const point &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
};

const int maxn = 14, pown = (1 << maxn), maxm = 105;
int n, m;
point ps[maxn];
pair<int, point> qs[maxm];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &ps[i].x, &ps[i].y);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &qs[i].second.x, &qs[i].second.y, &qs[i].first);
  }
  return true;
}

int dqs[pown][maxm], dps[pown][maxn];
int dpp[pown][maxm], dpq[pown][maxm];
int res;

void goDpq(int msk, int pos) {
  auto cur = dpq[msk][pos];
  if (cur < 0) {
    return;
  }
  res = max(res, cur);
  for (int npos = pos + 1; npos < m; ++npos) {
    if ((qs[npos].second - qs[pos].second).len() <= qs[npos].first - qs[pos].first) {
      auto &nxt = dpq[msk][npos];
      nxt = max(nxt, cur + 1);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (msk & (1 << i)) {
      continue;
    }
    auto &nxt = dpp[msk | (1 << i)][cur];
    nxt = min(nxt, qs[pos].first + (ps[i] - qs[pos].second).len());
  }
  {
    auto &nxt = dpp[msk][cur];
    nxt = min(nxt, qs[pos].first);
  }
}

void solve() {
  sort(qs, qs + m);
  {
    for (int msk = 0; msk < (1 << n); ++msk) {
      for (int i = 0; i < m; ++i) {
        auto &cur = dqs[msk][i];
        cur = inf;
        for (int j = 0; j < n; ++j) {
          if (msk & (1 << j)) {
            cur = min(cur, (qs[i].second - ps[j]).len());
          }
        }
      }
      for (int i = 0; i < n; ++i) {
        auto &cur = dps[msk][i];
        cur = inf;
        for (int j = 0; j < n; ++j) {
          if (msk & (1 << j)) {
            cur = min(cur, (ps[i] - ps[j]).len());
          }
        }
      }
    }
  }
  for (int msk = 0; msk < (1 << n); ++msk) {
    for (int k = 0; k <= m; ++k) {
      dpp[msk][k] = inf;
    }
    for (int pos = 0; pos < m; ++pos) {
      dpq[msk][pos] = -1;
    }
  }
  for (int pos = 0; pos < m; ++pos) {
    dpq[0][pos] = 1;
  }
  res = 1;
  for (int msk = 0; msk < (1 << n); ++msk) {
    if (!(msk & (msk - 1))) {
      dpp[msk][0] = 0;
    }
    int pos = 0;
    for (int k = 0; k <= m; ++k) {
      while (pos < m && qs[pos].first <= dpp[msk][k]) {
        goDpq(msk, pos++);
      }
      auto cur = dpp[msk][k];
      if (cur >= inf) {
        break;
      }
      for (int npos = pos; npos < m; ++npos) {
        if (cur + dqs[msk][npos] <= qs[npos].first) {
          auto &nxt = dpq[msk][npos];
          nxt = max(nxt, k + 1);
        }
      }
      for (int i = 0; i < n; ++i) {
        if (msk & (1 << i)) {
          continue;
        }
        auto &nxt = dpp[msk | (1 << i)][k];
        nxt = min(nxt, cur + dps[msk][i]);
      }
    }
    while (pos < m) {
      goDpq(msk, pos++);
    }
  }
  printf("%d\n", res);
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