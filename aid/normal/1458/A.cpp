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

long long gcd(long long a, long long b) {
  return (b ? gcd(b, a % b) : a);
}

const int maxn = (int) 2e5 + 5;
int n, m;
long long a[maxn], b[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%lld", &b[i]);
  }
  return true;
}

void solve() {
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[0]) {
      swap(a[i], a[0]);
    }
  }
  long long g = 0;
  for (int i = 1; i < n; ++i) {
    g = gcd(g, a[i] - a[0]);
  }
  for (int i = 0; i < m; ++i) {
    long long cur = gcd(g, a[0] + b[i]);
    printf("%lld ", cur);
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