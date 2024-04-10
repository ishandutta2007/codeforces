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

  point(int _x, int _y): x(_x), y(_y) {}

  bool read() {
    return scanf("%d%d", &x, &y) == 2;
  }

  point operator + (const point &p) const {
    return point(x + p.x, y + p.y);
  }

  point operator - (const point &p) const {
    return point(x - p.x, y - p.y);
  }

  long long operator ^ (const point &p) const {
    return (long long) x * p.y - (long long) y * p.x;
  }

  long long operator * (const point &p) const {
    return (long long) x * p.x + (long long) y * p.y;
  }

  long long slen() const {
    return *this * *this;
  }

  int type() const {
    return x < 0 || (x == 0 && y < 0);
  }
};

bool operator < (const point &a, const point &b) {
  if (a.type() != b.type()) {
    return a.type() < b.type();
  }
  long long cp = (a ^ b);
  if (cp) {
    return cp > 0;
  }
  return a.slen() < b.slen();
}

const int maxn = 305;
int n;
point ps[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    ps[i].read();
  }
  return true;
}

int cntl[maxn][maxn];
int cnt1[maxn][maxn][maxn];
int cnt[maxn][maxn][maxn];
pair<point, int> qs[3 * maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      auto &cur = cntl[i][j];
      if (j == i) {
        cur = -1;
        continue;
      }
      cur = 0;
      for (int k = 0; k < n; k++) {
        if (((ps[j] - ps[i]) ^ (ps[k] - ps[i])) > 0) {
          cur++;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        cnt1[i][j][k] = -1;
        cnt[i][j][k] = -1;
      }
    }
  }
  for (int s = 0; s < n; s++) {
    for (int i = 0; i < n; i++) {
      qs[i] = make_pair(ps[i] - ps[s], i);
    }
    sort(qs, qs + n);
    rotate(qs, qs + 1, qs + n);
    for (int i = 0; i < 2 * (n - 1); i++) {
      qs[n - 1 + i] = qs[i];
    }
    for (int i = 0, ii = 0; i < n - 1; i++) {
      ii = max(i, ii);
      while (ii < i + n - 1 && (qs[i].first ^ qs[ii].first) >= 0) {
        ii++;
      }
      for (int j = i + 1, jj = 0; j < i + n - 1; j++) {
        if ((qs[i].first ^ qs[j].first) <= 0) {
          break;
        }
        jj = max(j, jj);
        while (jj < j + n - 1 && (qs[j].first ^ qs[jj].first) >= 0) {
          jj++;
        }
        cnt1[s][qs[i].second][qs[j].second] = jj - ii;
      }
    }
  }
  long long res = 1;
  for (int i = 0; i < 5; i++) {
    res *= n - i;
  }
  for (int i = 1; i <= 5; i++) {
    res /= i;
  }
  long long x = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == i) {
        continue;
      }
      for (int k = 0; k < n; k++) {
        if (k == j || k == i) {
          continue;
        }
        if (((ps[j] - ps[i]) ^ (ps[k] - ps[i])) <= 0) {
          continue;
        }
        auto &cur = cnt[i][j][k];
        cur = n - 3;
        cur -= cntl[j][i];
        cur -= cntl[k][j];
        cur -= cntl[i][k];
        assert(cnt1[i][j][k] != -1);
        cur += cnt1[i][j][k];
        assert(cnt1[j][k][i] != -1);
        cur += cnt1[j][k][i];
        assert(cnt1[k][i][j] != -1);
        cur += cnt1[k][i][j];
        x += cur * (cur - 1) / 2;
      }
    }
  }
  x /= 3;
  res -= x;
  x = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == i) {
        continue;
      }
      for (int k = 0; k < n; k++) {
        if (k == i || k == j) {
          continue;
        }
        if (((ps[j] - ps[i]) ^ (ps[k] - ps[i])) <= 0) {
          continue;
        }
        long long cur = cntl[j][i];
        cur -= cnt1[i][j][k];
        cur -= cnt1[j][k][i];
        cur *= cnt[i][j][k];
        x += cur;
      }
    }
  }
  x /= 2;
  res -= x;
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