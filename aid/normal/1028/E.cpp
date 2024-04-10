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

const int maxn = (int) 2e5 + 5;
int n;
int b[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  return true;
}

long long a[maxn];

void solve() {
  {
    bool eq = true;
    for (int i = 1; i < n; i++) {
      if (b[i] != b[0]) {
        eq = false;
        break;
      }
    }
    if (eq) {
      if (b[0] == 0) {
        printf("YES\n");
        for (int i = 0; i < n; i++) {
          printf("1 ");
        }
        printf("\n");
      } else {
        printf("NO\n");
      }
      return;
    }
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, b[i]);
  }
  int s = -1;
  for (int i = 0; i < n; i++) {
    if (b[i] == mx && b[(i + n - 1) % n] != mx) {
      s = i;
      break;
    }
  }
  assert(s != -1);
  long long cur = 0;
  for (int i = s;;) {
    cur += b[i];
    if (b[i] == 0 && cur == mx) {
      cur *= 2;
    }
    a[i] = cur;
    i = (i + n - 1) % n;
    if (i == s) {
      break;
    }
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    printf("%lld ", a[i]);
  }
  printf("\n");
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