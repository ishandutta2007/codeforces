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
int p[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  n++;
  p[0] = -1;
  for (int i = 1; i < n; i++) {
    int v;
    scanf("%d", &v);
    p[i] = v;
  }
  return true;
}

int leaf[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    leaf[i] = true;
  }
  for (int i = 1; i < n; i++) {
    leaf[p[i]] = false;
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (leaf[i]) {
      res++;
    }
  }
  printf("%d\n", res);
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