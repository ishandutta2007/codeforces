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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxx = 1050;
int n, k, x;
int a[maxx], na[maxx];

int read() {
  if (scanf("%d%d%d", &n, &k, &x) < 3) {
    return false;
  }
  for (int i = 0; i < maxx; i++) {
    a[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int y;
    scanf("%d", &y);
    a[y]++;
  }
  return true;
}

void solve() {
  for (int it = 0; it < k; it++) {
    for (int i = 0; i < maxx; i++) {
      na[i] = 0;
    }
    int cur = 0;
    for (int i = 0; i < maxx; i++) {
      if (a[i]) {
        int toxor = (cur ? a[i] / 2 : (a[i] + 1) / 2);
        na[i ^ x] += toxor;
        na[i] += a[i] - toxor;
        cur ^= (a[i] & 1);
      }
    }
    swap(a, na);
  }
  int resmin = inf, resmax = -inf;
  for (int i = 0; i < maxx; i++) {
    if (a[i]) {
      resmin = min(resmin, i);
      resmax = max(resmax, i);
    }
  }
  printf("%d %d\n", resmax, resmin);
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