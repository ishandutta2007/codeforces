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

const int maxn = (int) 1e5 + 5;
int n, d, b;
int a[maxn];

int read() {
  if (scanf("%d%d%d", &n, &d, &b) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int rem[maxn];

bool check(int k) {
  for (int i = 0; i < n; i++) {
    rem[i] = a[i];
  }
  int pos = 0;
  for (int i = k; i + k < n; i++) {
    int kk = min(i, n - 1 - i);
    pos = max((long long) pos, i - (long long) d * (kk + 1));
    int cur = 0;
    while (cur < b) {
      while (pos < n && !rem[pos]) {
        pos++;
      }
      if (pos >= n || pos > i + (long long) d * (kk + 1)) {
        return false;
      }
      int toadd = min(rem[pos], b - cur);
      rem[pos] -= toadd;
      cur += toadd;
    }
  }
  return true;
}

void solve() {
  int l = -1, r = (n + 1) / 2;
  while (l < r - 1) {
    int m = (l + r) / 2;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  printf("%d\n", r);
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