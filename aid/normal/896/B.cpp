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
int n, m, c;

int read() {
  if (scanf("%d%d%d", &n, &m, &c) < 3) {
    return false;
  }
  return true;
}

int a[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    a[i] = -1;
  }
  for (int it = 0; it < m; it++) {
    int x;
    scanf("%d", &x);
    x--;
    int pos;
    if (x < c / 2) {
      pos = 0;
      while (pos < n && a[pos] != -1 && a[pos] <= x) {
        pos++;
      }
      if (pos >= n) {
        pos--;
      }
    } else {
      pos = n - 1;
      while (pos >= 0 && a[pos] != -1 && a[pos] >= x) {
        pos--;
      }
      if (pos < 0) {
        pos++;
      }
    }
    a[pos] = x;
    printf("%d\n", pos + 1);
    fflush(stdout);
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (a[i] == -1) {
        ok = false;
        break;
      }
    }
    if (ok) {
      break;
    }
  }
}

int main() {
  precalc();
  read();
  solve();
#ifdef DEBUG
  eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}