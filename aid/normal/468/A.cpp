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

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

void solve() {
  if (n < 4) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  if (n == 5) {
    printf("%d + %d = %d\n", 5, 1, 6);
    printf("%d - %d = %d\n", 3, 2, 1);
    printf("%d * %d = %d\n", 6, 4, 24);
    printf("%d * %d = %d\n", 24, 1, 24);
    return;
  }
  printf("%d * %d = %d\n", 2, 3, 6);
  printf("%d * %d = %d\n", 6, 4, 24);
  int cnt = 1;
  for (int i = 5; i + 1 <= n; i += 2) {
    printf("%d - %d = %d\n", i + 1, i, 1);
    cnt++;
  }
  while (cnt > 2) {
    printf("%d * %d = %d\n", 1, 1, 1);
    cnt--;
  }
  if (cnt == 2) {
    printf("%d - %d = %d\n", 1, 1, 0);
    if (n & 1) {
      printf("%d * %d = %d\n", 0, n, 0);
    }
    printf("%d - %d = %d\n", 24, 0, 24);
  } else {
    printf("%d * %d = %d\n", 24, 1, 24);
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