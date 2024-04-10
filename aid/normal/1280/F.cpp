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

const int maxn = 20;
int n;
int a[2][2 * maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2 * n + 1; j++) {
      scanf(" ");
      char c = getchar();
      if (c == 'E') {
        a[i][j] = -1;
        continue;
      }
      ungetc(c, stdin);
      scanf("%d", &a[i][j]);
      a[i][j]--;
    }
  }
  return true;
}

const int gox[] = {1, 0, -1, 0};
const int goy[] = {0, 1, 0, -1};
const string chs = "drul";

string ans;
vector<string> ops;
int rots[2][2];
int ex, ey;

void getPos(int id, int &x, int &y) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2 * n + 1; j++) {
      if (a[i][j] == id) {
        x = i;
        y = j;
        return;
      }
    }
  }
  assert(false);
}

void move(int dir) {
  int nx = ex + gox[dir], ny = ey + goy[dir];
  swap(a[ex][ey], a[nx][ny]);
  ex = nx;
  ey = ny;
  ans += chs[dir];
}

void rot(int c, int dir) {
  if (!c) {
    int tmp = a[0][0];
    if (!dir) {
      for (int i = 0; i < n; i++) {
        a[0][i] = a[0][i + 1];
      }
      a[0][n] = a[1][n - 1];
      for (int i = n - 1; i > 0; i--) {
        a[1][i] = a[1][i - 1];
      }
      a[1][0] = tmp;
    } else {
      a[0][0] = a[1][0];
      for (int i = 0; i < n - 1; i++) {
        a[1][i] = a[1][i + 1];
      }
      a[1][n - 1] = a[0][n];
      for (int i = n; i > 1; i--) {
        a[0][i] = a[0][i - 1];
      }
      a[0][1] = tmp;
    }
  } else {
    int tmp = a[0][2 * n];
    if (!dir) {
      for (int i = 2 * n; i > n; i--) {
        a[0][i] = a[0][i - 1];
      }
      a[0][n] = a[1][n + 1];
      for (int i = n + 1; i < 2 * n; i++) {
        a[1][i] = a[1][i + 1];
      }
      a[1][2 * n] = tmp;
    } else {
      a[0][2 * n] = a[1][2 * n];
      for (int i = 2 * n; i > n + 1; i--) {
        a[1][i] = a[1][i - 1];
      }
      a[1][n + 1] = a[0][n];
      for (int i = n; i < 2 * n - 1; i++) {
        a[0][i] = a[0][i + 1];
      }
      a[0][2 * n - 1] = tmp;
    }
  }
  ans += (char) ('A' + rots[c][dir]);
}

void moveToMiddle(int id) {
  int x, y;
  getPos(id, x, y);
  while (a[0][n] != id) {
    rot(y > n, 0);
  }
}

int t;

void swp(int i, int j, int x, int y, int c) {
  if (j == i) {
    return;
  }
  moveToMiddle(i);
  rot(!c, t);
  int bad = a[0][n];
  moveToMiddle(j);
  rot(!c, !t);
  moveToMiddle(bad);
  rot(!c, t);
  while (a[x][y] != i) {
    rot(c, 0);
  }
  t = !t;
}

void solve() {
  ans = "";
  ops.clear();
  getPos(-1, ex, ey);
  {
    while (ey != n) {
      move(ey < n ? 1 : 3);
    }
    if (!ex) {
      move(0);
    }
  }
  for (int c = 0; c < 2; c++) {
    for (int dir = 0; dir < 2; dir++) {
      rots[c][dir] = sz(ops);
      string s;
      if (dir) {
        s += 'u';
      }
      for (int i = 0; i < n; i++) {
        s += (c ? 'r' : 'l');
      }
      if (!dir) {
        s += 'u';
      }
      if (dir) {
        s += 'd';
      }
      for (int i = 0; i < n; i++) {
        s += (c ? 'l' : 'r');
      }
      if (!dir) {
        s += 'd';
      }
      ops.push_back(s);
    }
  }
  for (int i = 0; i < n; i++) {
    swp(i, a[0][i], 0, i, 0);
  }
  for (int i = 0; i < n; i++) {
    swp(2 * n + 1 + i, a[1][i], 1, i, 0);
  }
  for (int i = 0; i < n; i++) {
    swp(n + 1 + i, a[0][n + 1 + i], 0, n + 1 + i, 1);
  }
  for (int i = 0; i < n; i++) {
    swp(3 * n + 1 + i, a[1][n + 1 + i], 1, n + 1 + i, 1);
  }
  if (a[0][0] != 0) {
    printf("SURGERY FAILED\n");
    return;
  }
  for (int i = 0; i < n; i++) {
    move(1);
  }
  printf("SURGERY COMPLETE\n");
  printf("%s\n", ans.c_str());
  for (int i = 0; i < sz(ops); i++) {
    printf("%c %s\n", (char) ('A' + i), ops[i].c_str());
  }
  printf("DONE\n");
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