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
int n, m;
char c[maxn][maxn];

bool read() {
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

int d[3][maxn][maxn];
int dd[3][3];
vector<pair<int, int>> q;

bool inside(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (isdigit(c[i][j])) {
        c[i][j]--;
      }
    }
  }
  for (int t = 0; t < 3; t++) {
    q.clear();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        d[t][i][j] = inf;
        if ((int) c[i][j] == (int) '0' + t) {
          d[t][i][j] = 0;
          q.push_back(make_pair(i, j));
        }
      }
    }
    for (int l = 0; l < sz(q); l++) {
      int x = q[l].first, y = q[l].second;
      for (int dir = 0; dir < 4; dir++) {
        int nx = x + gox[dir], ny = y + goy[dir];
        if (!inside(nx, ny) || c[nx][ny] == '#' || d[t][nx][ny] != inf) {
          continue;
        }
        d[t][nx][ny] = d[t][x][y] + 1;
        q.push_back(make_pair(nx, ny));
      }
    }
    for (int tt = 0; tt < 3; tt++) {
      dd[t][tt] = inf;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (c[i][j] == '.' || c[i][j] == '#') {
          continue;
        }
        int tt = c[i][j] - '0';
        if (d[t][i][j] < inf) {
          dd[t][tt] = min(dd[t][tt], d[t][i][j] - 1);
        }
      }
    }
  }
  int res = inf;
  res = min(res, dd[0][1] + dd[0][2]);
  res = min(res, dd[1][0] + dd[1][2]);
  res = min(res, dd[2][0] + dd[2][1]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (d[0][i][j] < inf && d[1][i][j] < inf && d[2][i][j] < inf) {
        res = min(res, d[0][i][j] + d[1][i][j] + d[2][i][j] - 2);
      }
    }
  }
  if (res >= inf - 5) {
    res = -1;
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