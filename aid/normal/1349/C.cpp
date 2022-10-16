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
int n, m, t;
char c[maxn][maxn];

bool read() {
  if (scanf("%d%d%d", &n, &m, &t) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", c[i]);
  }
  return true;
}

const int gox[] = {1, 0, -1, 0};
const int goy[] = {0, 1, 0, -1};

int d[maxn][maxn];
vector<pair<int, int>> q;

bool inside(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

void solve() {
  q.clear();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bool ok = false;
      for (int dir = 0; dir < 4; dir++) {
        int x = i + gox[dir], y = j + goy[dir];
        if (inside(x, y) && c[x][y] == c[i][j]) {
          ok = true;
          break;
        }
      }
      if (ok) {
        d[i][j] = 0;
        q.push_back(make_pair(i, j));
      } else {
        d[i][j] = inf;
      }
    }
  }
  for (int l = 0; l < sz(q); l++) {
    int x = q[l].first, y = q[l].second;
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + gox[dir], ny = y + goy[dir];
      if (inside(nx, ny) && d[nx][ny] >= inf) {
        d[nx][ny] = d[x][y] + 1;
        q.push_back(make_pair(nx, ny));
      }
    }
  }
  for (int tt = 0; tt < t; tt++) {
    int x, y;
    long long p;
    scanf("%d%d%lld", &x, &y, &p);
    x--;
    y--;
    if (d[x][y] >= inf || p <= d[x][y]) {
      printf("%c\n", c[x][y]);
    } else {
      int z = (((int) (c[x][y] - '0')) ^ ((p - d[x][y]) & 1));
      printf("%d\n", z);
    }
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