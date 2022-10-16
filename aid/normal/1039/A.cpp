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
long long t;
long long a[maxn];
int x[maxn];

int read() {
  if (scanf("%d%lld", &n, &t) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
    x[i]--;
  }
  return true;
}

long long b[maxn];

void solve() {
  for (int i = 0; i < n;) {
    int j = x[i];
    if (j < i) {
      printf("No\n");
      return;
    }
    if (i == j) {
      b[i] = a[i] + t;
      i++;
      continue;
    }
    for (int k = i; k <= j; k++) {
      if (x[k] != j) {
        printf("No\n");
        return;
      }
    }
    if (j + 1 < n && a[j] == a[j + 1] - 1) {
      printf("No\n");
      return;
    }
    for (int k = i; k < j; k++) {
      b[k] = a[k + 1] + t;
    }
    b[j] = a[j] + t + 1;
    i = j + 1;
  }
  printf("Yes\n");
  for (int i = 0; i < n; i++) {
    printf("%lld ", b[i]);
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