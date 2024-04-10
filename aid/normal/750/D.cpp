#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
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

const int maxn = 35, maxx = 310;
int n;
int t[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i]);
  }
  t[0]--;
  return true;
}

const int gox[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int goy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int c[maxx][maxx];
int f[2][maxx][maxx][8];

void solve() {
  for (int i = 0; i < maxx; i++) {
    for (int j = 0; j < maxx; j++) {
      c[i][j] = false;
      for (int k = 0; k < 8; k++) {
        f[0][i][j][k] = false;
      }
    }
  }
  c[maxx / 2][maxx / 2] = true;
  f[0][maxx / 2][maxx / 2][3] = true;
  for (int i = 0; i < n; i++) {
    for (int x = 0; x < maxx; x++) {
      for (int y = 0; y < maxx; y++) {
        for (int d = 0; d < 8; d++) {
          f[(i + 1) & 1][x][y][d] = false;
        }
      }
    }
    for (int x = 0; x < maxx; x++) {
      for (int y = 0; y < maxx; y++) {
        for (int d = 0; d < 8; d++) {
          if (f[i & 1][x][y][d]) {
            int xx = x, yy = y;
            for (int j = 0; j < t[i]; j++) {
              xx += gox[d];
              yy += goy[d];
              c[xx][yy] = true;
            }
            f[(i + 1) & 1][xx][yy][(d + 7) % 8] = true;
            f[(i + 1) & 1][xx][yy][(d + 1) % 8] = true;
          }
        }
      }
    }
  }
  int res = 0;
  for (int i = 0; i < maxx; i++) {
    for (int j = 0; j < maxx; j++) {
      res += c[i][j];
    }
  }
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}