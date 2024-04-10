#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

int bor[4][2];

int get(int x0, int y0, int x1, int y1) {
  printf("? %d %d %d %d\n", x0 + 1, y0 + 1, x1 + 1, y1 + 1);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  return res;
}

bool intersect(int a, int b, int c, int d) {
  return max(a, c) <= min(b, d);
}

bool check(int x00, int y00, int x01, int y01,
           int x10, int y10, int x11, int y11) {
  if (x00 > x01 || y00 > y01 || x10 > x11 || y10 > y11) {
    return false;
  }
  if (intersect(x00, x01, x10, x11) && intersect(y00, y01, y10, y11)) {
    return false;
  }
  int c0 = get(x00, y00, x01, y01), c1 = get(x10, y10, x11, y11);
  if (c0 == 1 && c1 == 1) {
    printf("! %d %d %d %d %d %d %d %d\n", x00 + 1, y00 + 1, x01 + 1, y01 + 1,
           x10 + 1, y10 + 1, x11 + 1, y11 + 1);
    return true;
  }
  return false;
}

void solve() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      int l, r;
      if (i < 2) {
        l = -1;
        r = n - 1;
      }
      else {
        l = 0;
        r = n;
      }
      while (l < r - 1) {
        int m = (l + r) / 2, cnt;
        if (i == 0) {
          cnt = get(0, 0, m, n - 1);
        }
        else if (i == 1) {
          cnt = get(0, 0, n - 1, m);
        }
        else if (i == 2) {
          cnt = get(m, 0, n - 1, n - 1);
        }
        else {
          cnt = get(0, m, n - 1, n - 1);
        }
        if (cnt <= j) {
          if (i < 2) {
            l = m;
          }
          else {
            r = m;
          }
        }
        else {
          if (i < 2) {
            r = m;
          }
          else {
            l = m;
          }
        }
      }
      if (i < 2) {
        bor[i][j] = r;
      }
      else {
        bor[i][j] = l;
      }
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        if (check(bor[2][j], bor[3][k], bor[0][0], bor[1][i],
                  bor[2][j ^ 1], bor[3][k ^ 1], bor[0][1], bor[1][i ^ 1])) {
          return;
        }
      }
    }
  }
}

int main() {
  precalc();
  read();
  solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}