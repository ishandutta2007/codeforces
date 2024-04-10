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

const int maxn = 305;
int n, m;
int a[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  return true;
}

bool inside(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

const int gox[] = {1, 0, -1, 0};
const int goy[] = {0, 1, 0, -1};

int b[maxn][maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      auto &deg = b[i][j];
      deg = 0;
      for (int dir = 0; dir < 4; dir++) {
        int x = i + gox[dir], y = j + goy[dir];
        if (inside(x, y)) {
          deg++;
        }
      }
      if (deg < a[i][j]) {
        printf("NO\n");
        return;
      }
    }
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", b[i][j]);
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