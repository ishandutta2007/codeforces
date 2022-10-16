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

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

const int maxn = 2005;
int n;
int a[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

void solve() {
  int c1 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      c1++;
    }
  }
  if (c1) {
    printf("%d\n", n - c1);
    return;
  }
  int len = inf;
  for (int i = 0; i < n; i++) {
    int g = a[i];
    for (int j = i + 1; j < n; j++) {
      g = gcd(g, a[j]);
      if (g == 1) {
        len = min(len, j - i + 1);
        break;
      }
    }
  }
  if (len >= inf) {
    printf("-1\n");
    return;
  }
  printf("%d\n", n - 1 + len - 1);
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