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

const int maxm = (int) 1e5 + 5;
long long n, k;
int m;
long long p[maxm];

bool read() {
  if (scanf("%lld%d%lld", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%lld", &p[i]);
    p[i]--;
  }
  return true;
}

void solve() {
  int del = 0;
  int res = 0;
  for (int j = 0; j < m;) {
    int i = j;
    long long page = (p[i] - del) / k;
    while (j < m && (p[j] - del) / k == page) {
      j++;
    }
    res++;
    del += j - i;
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