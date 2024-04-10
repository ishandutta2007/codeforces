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

long long n, k;

bool read() {
  if (scanf("%lld%lld", &n, &k) < 2) {
    return false;
  }
  return true;
}

long long m;

long long get(long long i) {
  if (!i) {
    return k * (k + 1) / 2;
  }
  long long j = i / k;
  long long x = get(j);
  long long l = j * m;
  i %= k;
  if (l + (i + 1) * k < x) {
    return ((l + i * k + 1) + (l + (i + 1) * k)) * k / 2;
  }
  if (l + i * k + 1 < x) {
    return ((l + i * k + 1) + (l + i * k + k + 1)) * (k + 1) / 2 - x;
  }
  return ((l + i * k + 2) + (l + i * k + k + 1)) * k / 2;
}

void solve() {
  m = k * k + 1;
  long long i = (n - 1) / m;
  long long x = get(i);
  if (n == x) {
    printf("%lld\n", (i + 1) * (k + 1));
  } else {
    long long p = n;
    if (x < p) {
      p--;
    }
    p = (p - 1) % m;
    printf("%lld\n", i * k * (k + 1) + (p / k) * (k + 1) + (p % k) + 1);
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}