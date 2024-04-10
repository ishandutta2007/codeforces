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

long long n;

bool read() {
  if (scanf("%lld", &n) < 1) {
    return false;
  }
  return true;
}

bool isPrime(long long n) {
  for (long long d = 2; d * d <= n; d++) {
    if (!(n % d)) {
      return false;
    }
  }
  return true;
}

void solve() {
  if (isPrime(n)) {
    printf("1\n");
    return;
  }
  if (!(n & 1)) {
    printf("2\n");
    return;
  }
  if (isPrime(n - 2)) {
    printf("2\n");
    return;
  }
  printf("3\n");
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