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

const int maxn = 55;
int n, m;
char c[2][maxn][maxn];
char nc[2][maxn][maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int it = 0; it < 2; it++) {
    for (int i = 0; i < n; i++) {
      scanf("%s", &c[it][i]);
    }
  }
  return true;
}

int used[maxn][maxn];
int t;

pair<int, int> p(int x, int y) {
  char ch = c[t][x][y];
  if (ch == 'D') {
    x--;
  } else if (ch == 'U') {
    x++;
  } else if (ch == 'R') {
    y--;
  } else {
    y++;
  }
  return make_pair(x, y);
}

pair<int, int> need(int x, int y) {
  if (!(x & 1)) {
    x++;
  } else {
    x--;
  }
  return make_pair(x, y);
}

void change(int x, int y, vector< pair<int, int> > &res) {
  res.push_back(make_pair(x, y));
  if (c[t][x][y] == 'L') {
    assert(c[t][x][y + 1] == 'R');
    assert(c[t][x + 1][y] == 'L');
    assert(c[t][x + 1][y + 1] == 'R');
    c[t][x][y] = 'U';
    c[t][x][y + 1] = 'U';
    c[t][x + 1][y] = 'D';
    c[t][x + 1][y + 1] = 'D';
  } else if (c[t][x][y] == 'U') {
    assert(c[t][x][y + 1] == 'U');
    assert(c[t][x + 1][y] == 'D');
    assert(c[t][x + 1][y + 1] == 'D');
    c[t][x][y] = 'L';
    c[t][x][y + 1] = 'R';
    c[t][x + 1][y] = 'L';
    c[t][x + 1][y + 1] = 'R';
  } else {
    assert(false);
  }
}

vector< pair<int, int> > solve(int t) {
  ::t = t;
  vector< pair<int, int> > res;
  while (true) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        used[i][j] = false;
      }
    }
    pair<int, int> s = make_pair(-1, -1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!used[i][j] && p(i, j) != need(i, j)) {
          int x = i, y = j;
          vector< pair<int, int> > comp;
          eprintf("comp:\n");
          while (!used[x][y]) {
            eprintf("%d %d\n", x, y);
            comp.push_back(make_pair(x, y));
            used[x][y] = true;
            pair<int, int> nxt = p(x, y);
            x = nxt.first;
            y = nxt.second;
            eprintf("%d %d\n", x, y);
            assert(!used[x][y]);
            comp.push_back(make_pair(x, y));
            used[x][y] = true;
            nxt = need(x, y);
            x = nxt.first;
            y = nxt.second;
          }
          pair<int, int> cur = comp[0];
          for (int k = 1; k < sz(comp); k++) {
            cur = min(cur, comp[k]);
          }
          s = max(s, cur);
        }
      }
    }
    if (s.first == -1) {
      break;
    }
    int x = s.first, y = s.second;
    assert(p(x, y) == make_pair(x, y + 1));
    if (p(x + 1, y) == make_pair(x + 1, y + 1)) {
      change(x, y, res);
      continue;
    }
    assert(p(x + 1, y) == make_pair(x + 2, y));
    if (p(x + 1, y + 1) == make_pair(x + 2, y + 1)) {
      change(x + 1, y, res);
      change(x, y, res);
      continue;
    }
    assert(p(x + 1, y + 1) == make_pair(x + 1, y + 2));
    if (p(x + 2, y + 1) == make_pair(x + 3, y + 1)) {
      assert(p(x + 2, y + 2) == make_pair(x + 3, y + 2));
      change(x + 2, y + 1, res);
      change(x + 1, y + 1, res);
      change(x + 1, y, res);
      change(x, y, res);
      continue;
    }
    assert(p(x + 2, y + 1) == make_pair(x + 2, y + 2));
    change(x + 1, y + 1, res);
    change(x + 1, y, res);
    change(x, y, res);
  }
  return res;
}

void solve() {
  bool rev = false;
  if (n & 1) {
    rev = true;
    for (int it = 0; it < 2; it++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          nc[it][j][i] = (c[it][i][j] == 'L' ? 'U' : (c[it][i][j] == 'R' ? 'D' : (c[it][i][j] == 'U' ? 'L' : 'R')));
        }
      }
    }
    swap(c, nc);
    swap(n, m);
  }
  vector< pair<int, int> > res = solve(0), res1 = solve(1);
  reverse(res1.begin(), res1.end());
  for (int i = 0; i < sz(res1); i++) {
    res.push_back(res1[i]);
  }
  if (rev) {
    for (int i = 0; i < sz(res); i++) {
      swap(res[i].first, res[i].second);
    }
  }
  printf("%d\n", sz(res));
  for (int i = 0; i < sz(res); i++) {
    printf("%d %d\n", res[i].first + 1, res[i].second + 1);
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