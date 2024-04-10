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

const int maxn = 25;
int n, m;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  return true;
}

const int gox[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int goy[] = {0, 1, 1, 1, 0, -1, -1, -1};

char c[maxn][maxn];
vector<pair<int, int>> ps;

int go(int p) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      c[i][j] = '0';
    }
  }
  int res = 0;
  for (int it = 0; it < sz(ps); ++it) {
    int i = (p + it) % sz(ps);
    int x = ps[i].first, y = ps[i].second;
    bool ok = true;
    for (int dir = 0; dir < 8; ++dir) {
      int xx = x + gox[dir], yy = y + goy[dir];
      if (0 <= xx && xx < n && 0 <= yy && yy < m && c[xx][yy] == '1') {
        ok = false;
        break;
      }
    }
    if (ok) {
      ++res;
      c[x][y] = '1';
    }
  }
  return res;
}

void solve() {
  ps.clear();
  for (int j = 1; j < m; ++j) {
    ps.push_back(make_pair(0, j));
  }
  for (int i = 1; i < n; ++i) {
    ps.push_back(make_pair(i, m - 1));
  }
  for (int j = m - 2; j >= 0; --j) {
    ps.push_back(make_pair(n - 1, j));
  }
  for (int i = n - 2; i >= 0; --i) {
    ps.push_back(make_pair(i, 0));
  }
  int res = 0, best = -1;
  for (int i = 0; i < sz(ps); ++i) {
    int cur = go(i);
    if (cur > res) {
      res = cur;
      best = i;
    }
  }
  go(best);
  for (int i = 0; i < n; ++i) {
    c[i][m] = 0;
    printf("%s\n", c[i]);
  }
  printf("\n");
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