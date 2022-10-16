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

int n, k;

int read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  return true;
}

void solve() {
  if (k == 1 || k > 3) {
    printf("-1\n");
    return;
  }
  if (n <= 3) {
    printf("-1\n");
    return;
  }
  if (n == 4) {
    if (k == 2) {
      printf("-1\n");
      return;
    }
    printf("%d\n", n - 1);
    for (int i = 0; i + 1 < n; i++) {
      printf("%d %d\n", i + 1, i + 2);
    }
    return;
  }
  if (k == 2) {
    printf("%d\n", n - 1);
    for (int i = 0; i + 1 < n; i++) {
      printf("%d %d\n", i + 1, i + 2);
    }
    return;
  }
  printf("%d\n", 2 * (n - 2));
  for (int i = 0; i + 1 < n - 1; i++) {
    printf("%d %d\n", i + 1, i + 2);
  }
  for (int i = 1; i < n - 1; i++) {
    printf("%d %d\n", i + 1, n);
  }
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