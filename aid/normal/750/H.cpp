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
int n, m, q;
char c[maxn][maxn];

int read() {
  if (scanf("%d%d%d", &n, &m, &q) < 3) {
    return false;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%s", c[i] + 1);
  }
  return true;
}

const int gox[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int goy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int cid[maxn][maxn];
int cs;

bool inside(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

void getComp(int x, int y, int col) {
  cid[x][y] = col;
  for (int dir = 0; dir < 8; dir++) {
    int nx = x + gox[dir], ny = y + goy[dir];
    if (inside(nx, ny) && c[nx][ny] == '#' && cid[nx][ny] == -1) {
      getComp(nx, ny, col);
    }
  }
}

set< pair<int, int> > est;
vector<int> g[maxn][maxn];
vector< pair<int, int> > ps;
int usedps[maxn];
int cps[maxn];
int used[maxn * maxn];
int curu;

void dfsps(int v, int col) {
  cps[v] = col;
  for (int u = 0; u < sz(ps); u++) {
    if (cps[u] == -1 && abs(ps[u].first - ps[v].first) <= 1 && abs(ps[u].second - ps[v].second) <= 1) {
      dfsps(u, col);
    }
  }
}

void dfs(int v, vector<int> &comp) {
  used[v] = curu;
  comp.push_back(v);
  for (int s = 0; s < sz(ps); s++) {
    int sx = ps[s].first, sy = ps[s].second;
    if (!count(g[sx][sy].begin(), g[sx][sy].end(), v)) {
      continue;
    }
    for (int i = 0; i < sz(ps); i++) {
      if (cps[i] != cps[s]) {
        continue;
      }
      int x = ps[i].first, y = ps[i].second;
      if (usedps[i] != curu) {
        usedps[i] = curu;
        comp.push_back(cs + i);
      }
      for (int j = 0; j < sz(g[x][y]); j++) {
        int u = g[x][y][j];
        if (used[u] != curu) {
          dfs(u, comp);
        }
      }
    }
  }
}

void solve() {
  n += 2;
  m += 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (0 < i && i + 1 < n && 0 < j && j + 1 < m) {
        continue;
      }
      c[i][j] = ((i <= 2 && j <= 2) || (i >= n - 3 && j >= m - 3)) ? '.' : '#';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cid[i][j] = -1;
    }
  }
  cs = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (c[i][j] == '#' && cid[i][j] == -1) {
        getComp(i, j, cs++);
      }
    }
  }
  est.clear();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (c[i][j] == '#') {
        continue;
      }
      auto &v = g[i][j];
      v.clear();
      for (int dir = 0; dir < 8; dir++) {
        int x = i + gox[dir], y = j + goy[dir];
        if (inside(x, y) && c[x][y] == '#') {
          v.push_back(cid[x][y]);
        }
      }
      sort(v.begin(), v.end());
      v.erase(unique(v.begin(), v.end()), v.end());
      for (int it0 = 0; it0 < sz(v); it0++) {
        for (int it1 = it0 + 1; it1 < sz(v); it1++) {
          est.insert(make_pair(v[it0], v[it1]));
        }
      }
    }
  }
  int s = cid[0][m - 1], t = cid[n - 1][0];
  for (int qq = 0; qq < q; qq++) {
    ps.clear();
    int k;
    scanf("%d", &k);
    ps.resize(k);
    for (int i = 0; i < k; i++) {
      scanf("%d%d", &ps[i].first, &ps[i].second);
    }
    for (int i = 0; i < k; i++) {
      cps[i] = -1;
    }
    for (int i = 0, id = 0; i < k; i++) {
      if (cps[i] == -1) {
        dfsps(i, id++);
      }
    }
    vector<int> sc, tc;
    curu++;
    dfs(s, sc);
    if (used[t] == curu) {
      printf("NO\n");
      fflush(stdout);
      continue;
    }
    dfs(t, tc);
    bool ok = false;
    for (int i = 0; i < sz(sc) && !ok; i++) {
      for (int j = 0; j < sz(tc) && !ok; j++) {
        int v = sc[i], u = tc[j];
        if (v < cs && u < cs) {
          if (v > u) {
            swap(v, u);
          }
          if (est.count(make_pair(v, u))) {
            ok = true;
          }
          continue;
        }
        if (v < cs) {
          swap(v, u);
        }
        int x = ps[v - cs].first, y = ps[v - cs].second;
        for (int dir = 0; dir < 8; dir++) {
          int nx = x + gox[dir], ny = y + goy[dir];
          if (inside(nx, ny) && c[x][y] == '.') {
            if (u < cs) {
              if (count(g[nx][ny].begin(), g[nx][ny].end(), u)) {
                ok = true;
              }
            } else {
              int needx = ps[u - cs].first, needy = ps[u - cs].second;
              if (abs(nx - needx) <= 1 && abs(ny - needy) <= 1) {
                ok = true;
              }
            }
          }
        }
      }
    }
    if (ok) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
    fflush(stdout);
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