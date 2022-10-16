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

const int maxn = 305;
const int maxlen = (int) 1e5 + 5;
int n, m;
string c[2][maxn][maxn];
char tmp[maxlen];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%s", tmp);
        c[t][i][j] = tmp;
      }
    }
  }
  return true;
}

int t;

void go(int x, int y, int x0, int y0, int x1, int y1, vector<vector<int>> &ans) {
  for (int i = 0; i < sz(c[t][x][y]); i++) {
    if (c[t][x][y][i] == '0') {
      ans.push_back({x, y, x0, y0});
      c[t][x0][y0] += "0";
    } else {
      ans.push_back({x, y, x1, y1});
      c[t][x1][y1] += "1";
    }
  }
  c[t][x][y].clear();
}

vector<vector<int>> solve1() {
  vector<vector<int>> ans;
  go(0, 0, 0, m - 1, 0, m - 1, ans);
  go(n - 1, m - 1, n - 1, 0, n - 1, 0, ans);
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      go(i, j, 0, j, n - 1, j, ans);
    }
  }
  for (int j = 1; j < m - 1; j++) {
    go(0, j, 0, 0, 0, m - 1, ans);
  }
  for (int j = 1; j < m - 1; j++) {
    go(n - 1, j, n - 1, 0, n - 1, m - 1, ans);
  }
  for (int i = 1; i < n - 1; i++) {
    go(i, 0, 0, 0, n - 1, 0, ans);
  }
  for (int i = 1; i < n - 1; i++) {
    go(i, m - 1, 0, m - 1, n - 1, m - 1, ans);
  }
  go(0, m - 1, 0, 0, n - 1, m - 1, ans);
  go(n - 1, 0, 0, 0, n - 1, m - 1, ans);
  return ans;
}

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      reverse(c[0][i][j].begin(), c[0][i][j].end());
    }
  }
  t = 0;
  vector<vector<int>> ans = solve1();
  {
    t = 1;
    vector<vector<int>> ans1 = solve1();
    reverse(ans1.begin(), ans1.end());
    for (int i = 0; i < sz(ans1); i++) {
      swap(ans1[i][0], ans1[i][2]);
      swap(ans1[i][1], ans1[i][3]);
      ans.push_back(ans1[i]);
    }
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    for (int j = 0; j < sz(ans[i]); j++) {
      printf("%d ", ans[i][j] + 1);
    }
    printf("\n");
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