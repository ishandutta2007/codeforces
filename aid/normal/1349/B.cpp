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

const int maxn = (int) 1e5 + 5;
int n, x;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &x) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int b[5];

void solve() {
  if (n == 1) {
    if (a[0] == x) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
    return;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == x) {
      cnt++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 2; j <= 3; j++) {
      if (i + j > n) {
        break;
      }
      int curc = cnt;
      for (int k = 0; k < j; k++) {
        b[k] = a[i + k];
        if (a[i + k] == x) {
          curc--;
        }
      }
      sort(b, b + j);
      int y = b[(j - 1) / 2];
      if (y == x || (y > x && curc)) {
        printf("yes\n");
        return;
      }
    }
  }
  printf("no\n");
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