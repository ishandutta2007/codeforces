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

const int maxn = 1005;
int n, s;
int a[maxn], b[maxn];

int read() {
  if (scanf("%d%d", &n, &s) < 2) {
    return false;
  }
  s--;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  return true;
}

void solve() {
  if (!a[0]) {
    printf("NO\n");
    return;
  }
  if (a[s]) {
    printf("YES\n");
    return;
  }
  if (!b[s]) {
    printf("NO\n");
    return;
  }
  for (int i = s + 1; i < n; i++) {
    if (a[i] && b[i]) {
      printf("YES\n");
      return;
    }
  }
  printf("NO\n");
  return;
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