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

const int gox[] = {1, 0, -1, 0};
const int goy[] = {0, 1, 0, -1};

const int maxn = 2005;
int n, m;
int sx, sy;
int l, r;
char c[maxn][maxn];

int read() {
  if (scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &l, &r) < 6) {
    return false;
  }
  sx--;
  sy--;
  for (int i = 0; i < n; i++) {
    scanf("%s", c[i]);
  }
  return true;
}

bool inside(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

int d[maxn][maxn];
pair<int, int> q[2 * maxn * maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      d[i][j] = inf;
    }
  }
  int ql = maxn * maxn, qr = ql;
  d[sx][sy] = 0;
  q[qr++] = make_pair(sx, sy);
  while (ql < qr) {
    int x = q[ql].first, y = q[ql].second;
    ql++;
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + gox[dir], ny = y + goy[dir];
      int w = (dir == 1);
      if (!inside(nx, ny) || c[nx][ny] == '*' || d[nx][ny] <= d[x][y] + w) {
        continue;
      }
      d[nx][ny] = d[x][y] + w;
      if (w) {
        q[qr++] = make_pair(nx, ny);
      } else {
        q[--ql] = make_pair(nx, ny);
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int curr = d[i][j];
      int curl = sy - j + curr;
      if (curl <= l && curr <= r) {
        res++;
      }
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