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

const int maxn = (int) 1e6 + 5;
char tmp[maxn];
int n, m;
vector<string> c;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  c.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    c[i] = tmp;
  }
  return true;
}

const int gox[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int goy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool inside(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

vector<vector<int>> d, dd;
vector<pair<int, int>> q;

bool check(int t) {
  q.clear();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dd[i][j] = inf;
      if (d[i][j] >= t) {
        dd[i][j] = 0;
        q.push_back(make_pair(i, j));
      }
    }
  }
  for (int l = 0; l < sz(q); l++) {
    int x = q[l].first, y = q[l].second;
    if (dd[x][y] >= t) {
      break;
    }
    for (int dir = 0; dir < 8; dir++) {
      int nx = x + gox[dir], ny = y + goy[dir];
      if (!inside(nx, ny) || dd[nx][ny] < inf) {
        continue;
      }
      dd[nx][ny] = dd[x][y] + 1;
      q.push_back(make_pair(nx, ny));
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dd[i][j] >= inf && c[i][j] == 'X') {
        return false;
      }
    }
  }
  return true;
}

void solve() {
  d = vector<vector<int>>(n, vector<int>(m, inf));
  dd = vector<vector<int>>(n, vector<int>(m, inf));
  q.clear();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (c[i][j] == 'X') {
        bool ok = false;
        for (int dir = 0; dir < 8; dir++) {
          int ni = i + gox[dir], nj = j + goy[dir];
          if (!inside(ni, nj) || c[ni][nj] == '.') {
            ok = true;
            break;
          }
        }
        if (ok) {
          d[i][j] = 0;
          q.push_back(make_pair(i, j));
        }
      } else {
        d[i][j] = -1;
      }
    }
  }
  for (int l = 0; l < sz(q); l++) {
    int x = q[l].first, y = q[l].second;
    for (int dir = 0; dir < 8; dir++) {
      int nx = x + gox[dir], ny = y + goy[dir];
      if (!inside(nx, ny) || d[nx][ny] < inf) {
        continue;
      }
      d[nx][ny] = d[x][y] + 1;
      q.push_back(make_pair(nx, ny));
    }
  }
  int l = 0, r = d[q.back().first][q.back().second] + 1;
  while (l < r - 1) {
    int mm = (l + r) / 2;
    if (check(mm)) {
      l = mm;
    } else {
      r = mm;
    }
  }
  int t = l;
  printf("%d\n", t);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c[i][j] = (d[i][j] < t ? '.' : 'X');
    }
    printf("%s\n", c[i].c_str());
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