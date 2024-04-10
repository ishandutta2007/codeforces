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

int n, m;

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  return true;
}

vector<vector<int>> a;

void solve1() {
  a.clear();
  a.resize(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    int cur = i * m;
    if (!(m & 1) || (i & 1)) {
      cur++;
    }
    int j = 0;
    for (; j < m && cur < (i + 1) * m; j++, cur += 2) {
      a[i][j] = cur;
    }
    cur = i * m + 1;
    if (!(m & 1) || (i & 1)) {
      cur--;
    }
    for (; j < m && cur < (i + 1) * m; j++, cur += 2) {
      a[i][j] = cur;
    }
    if (!(m & 1) && (i & 1)) {
      reverse(a[i].begin(), a[i].end());
    }
  }
}

const int gox[] = {1, 0, -1, 0};
const int goy[] = {0, 1, 0, -1};

vector<vector<int>> g;
vector<int> used;

bool gen(int x, int y) {
  if (y >= m) {
    x++;
    y = 0;
  }
  if (x >= n) {
    return true;
  }
  for (int i = 0; i < n * m; i++) {
    if (used[i]) {
      continue;
    }
    if (x && g[i][a[x - 1][y]]) {
      continue;
    }
    if (y && g[i][a[x][y - 1]]) {
      continue;
    }
    used[i] = true;
    a[x][y] = i;
    if (gen(x, y + 1)) {
      return true;
    }
    used[i] = false;
    a[x][y] = -1;
  }
  return false;
}

void solve() {
  if (m >= 4) {
    solve1();
  } else if (n >= 4) {
    swap(n, m);
    solve1();
    swap(n, m);
    vector<vector<int>> b(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        auto &cur = b[i][j];
        cur = a[j][i];
        int x = cur / n, y = cur % n;
        cur = y * m + x;
      }
    }
    a = b;
  } else {
    a.clear();
    a.resize(n, vector<int>(m, -1));
    used.clear();
    used.resize(n * m);
    g.clear();
    g.resize(n * m, vector<int>(n * m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int v = i * m + j;
        for (int dir = 0; dir < 4; dir++) {
          int x = i + gox[dir], y = j + goy[dir];
          if (0 <= x && x < n && 0 <= y && y < m) {
            int u = x * m + y;
            g[v][u] = true;
          }
        }
      }
    }
    if (!gen(0, 0)) {
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", a[i][j] + 1);
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