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

const int maxn = (int) 1e5 + 5, maxm = 12;
int n, m;
int a[maxm][maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
      a[i][j]--;
    }
  }
  return true;
}

int b[maxm][maxn];

void solve() {
  for (int t = 0; t < m; t++) {
    for (int i = 0; i < n; i++) {
      b[t][a[t][i]] = i;
    }
  }
  long long res = 0;
  for (int j = 0; j < n;) {
    int i = j;
    while (j < n) {
      bool ok = true;
      int val = a[0][j];
      for (int t = 0; t < m; t++) {
        int pos = b[t][a[0][i]] + j - i;
        if (pos >= n || a[t][pos] != val) {
          ok = false;
        }
      }
      if (!ok) {
        break;
      }
      j++;
    }
    res += (long long) (j - i) * (j - i + 1) / 2;
  }
  printf("%lld\n", res);
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