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

const int maxn = (int) 1e6 + 5;
int n;
long long k;
long long a[maxn];

int read() {
  if (scanf("%d%lld", &n, &k) < 2) {
    return false;
  }
  k--;
  a[0] = 0;
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d%lld", &p, &a[i]);
    p--;
    a[i] ^= a[p];
  }
  return true;
}

const int maxb = 62;
long long b[maxn];

long long get(int bit, long long x) {
  for (int i = 0; i < n; i++) {
    b[i] = ((a[i] & ~((1ll << bit) - 1)) ^ x);
  }
  sort(b, b + n);
  long long res = 0;
  for (int i = 0, l = 0, r = 0; i < n; i++) {
    long long cur = (a[i] & ~((1ll << bit) - 1));
    while (l < n && b[l] < cur) {
      l++;
    }
    while (r < n && b[r] <= cur) {
      r++;
    }
    res += r - l;
  }
  return res;
}

void solve() {
  sort(a, a + n);
  long long res = 0;
  for (int bit = maxb - 1; bit >= 0; bit--) {
    long long cnt = get(bit, res);
    if (k >= cnt) {
      k -= cnt;
      res ^= (1ll << bit);
    }
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