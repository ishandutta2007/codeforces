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

const int maxn = 2005;
int n;
int a[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  return true;
}

int pref[2][maxn], suff[2][maxn];

void solve() {
  for (int t = 0; t < 2; t++) {
    pref[t][0] = 0;
    for (int i = 0; i < n; i++) {
      pref[t][i + 1] = pref[t][i] + (a[i] == t);
    }
    suff[t][n] = 0;
    for (int i = n - 1; i >= 0; i--) {
      suff[t][i] = suff[t][i + 1] + (a[i] == t);
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    int d0 = 0, d1 = 0;
    for (int j = i; j < n; j++) {
      if (a[j] == 0) {
        d0 = max(d0 + 1, d1 + 1);
      } else {
        d1++;
        d0 = max(d0, d1);
      }
      res = max(res, pref[0][i] + d0 + suff[1][j + 1]);
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