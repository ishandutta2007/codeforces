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

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 2e5 + 5;
int n;
int a[maxn], b[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    b[i]--;
  }
  return true;
}

int d[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    if (a[i] != -1) {
      d[a[i]] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (b[i] != -1) {
      d[b[i]] = i + 1;
    }
  }
  if (b[n - 1] != -1) {
    int k = b[n - 1] + 1;
    bool ok = true;
    for (int i = 0; i < k && ok; i++) {
      if (b[n - k + i] != i) {
        ok = false;
      }
    }
    for (int i = k; i < n && ok; i++) {
      if (d[i] > i - k) {
        ok = false;
      }
    }
    if (ok) {
      printf("%d\n", n - k);
      return;
    }
  }
  int res = n;
  for (int i = 0; i < n; i++) {
    res = max(res, d[i] - i + n);
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