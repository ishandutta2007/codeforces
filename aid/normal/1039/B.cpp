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

mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

long long n;
int k;

int read() {
  if (scanf("%lld%d", &n, &k) < 2) {
    return false;
  }
  return true;
}

int K = 60;
char tmp[100];

bool ask(long long l, long long r) {
  printf("%lld %lld\n", l + 1, r);
  fflush(stdout);
  scanf("%s", tmp);
  return tmp[0] == 'Y';
}

void solve() {
  long long l = 0, r = n;
  while (true) {
    while (r - l > K) {
      long long m = (l + r) / 2;
      if (ask(l, m)) {
        r = m;
      } else {
        l = m;
      }
      l = max(0ll, l - k);
      r = min(n, r + k);
    }
    long long x = l + rnd((int) (r - l));
    if (ask(x, x + 1)) {
      return;
    }
    l = max(0ll, l - k);
    r = min(n, r + k);
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