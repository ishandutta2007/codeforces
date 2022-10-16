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

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = (int) 5e5 + 5;
int n;
long long x[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &x[i]);
  }
  return true;
}

const int maxb = 61;
int cnt[maxb];

void solve() {
  for (int i = 0; i < maxb; ++i) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    for (int b = 0; b < maxb; ++b) {
      if (x[i] & (1ll << b)) {
        ++cnt[b];
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int andSum = 0;
    for (int b = 0; b < maxb; ++b) {
      if (x[i] & (1ll << b)) {
        add(andSum, mul(cnt[b], (1ll << b) % mod));
      }
    }
    int orSum = 0;
    for (int b = 0; b < maxb; ++b) {
      int k;
      if (x[i] & (1ll << b)) {
        k = n;
      } else {
        k = cnt[b];
      }
      add(orSum, mul(k, (1ll << b) % mod));
    }
    add(res, mul(andSum, orSum));
  }
  printf("%d\n", res);
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