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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 1005;
int n, m;
char c[maxn][maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", c[i]);
  }
  return true;
}

const int gox[] = {1, 0, -1, 0};
const int goy[] = {0, 1, 0, -1};

char used[3][4][maxn][maxn];
pair<pair<int, int>, pair<int, int> > q[maxn * maxn * 3 * 4];

bool inside(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

void solve() {
  memset(used, 0, sizeof(used));
  int qr = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (c[i][j] == 'S') {
        q[qr++] = make_pair(make_pair(i, j), make_pair(3, -1));
      }
    }
  }
  for (int ql = 0; ql < qr; ql++) {
    int x = q[ql].first.first;
    int y = q[ql].first.second;
    int cnt = q[ql].second.first;
    int pdir = q[ql].second.second;
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + gox[dir], ny = y + goy[dir];
      if (!inside(nx, ny) || c[nx][ny] == '*') {
        continue;
      }
      int ncnt = cnt - (dir != pdir);
      if (ncnt < 0) {
        continue;
      }
      if (used[ncnt][dir][nx][ny]) {
        continue;
      }
      used[ncnt][dir][nx][ny] = true;
      q[qr++] = make_pair(make_pair(nx, ny), make_pair(ncnt, dir));
      if (c[nx][ny] == 'T') {
        printf("YES\n");
        return;
      }
    }
  }
  printf("NO\n");
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