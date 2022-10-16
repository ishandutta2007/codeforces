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

const int maxn = 5005;
int n, m;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  return true;
}

int getVal(int n) {
  int mx = (n / 2 - 1) * (n / 2);
  if (n & 1) {
    mx += n / 2;
  }
  return mx;
}

int a[maxn];

int getLst(int n, int x) {
  int res = 0;
  for (int i = 1; i <= n && i < x - i; i++) {
    if (x - i <= n) {
      res++;
    }
  }
  return res;
}

const int X = (int) 1e8;

void rec(int n, int m) {
  if (!n) {
    return;
  }
  int x = getVal(n - 1);
  if (m <= x) {
    a[n - 1] = X + (n - 1) * maxn;
    rec(n - 1, m);
    return;
  }
  x = getVal(n);
  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
  }
  int lst = getLst(n - 1, a[n - 1]);
  while (x > m) {
    a[n - 1]++;
    x -= lst;
    lst = getLst(n - 1, a[n - 1]);
    x += lst;
  }
  assert(x == m);
}

void solve() {
  int mx = getVal(n);
  if (m > mx) {
    printf("-1\n");
    return;
  }
  rec(n, m);
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
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