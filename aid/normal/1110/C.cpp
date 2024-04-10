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

int gcd(int a, int b) {
  return (b ? gcd(b, a % b) : a);
}

const int maxk = 26;
int ans[maxk] = {0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};

void precalc() {
  /*eprintf("int ans[maxk] = {0,");
  for (int k = 1; k < maxk; k++) {
    int a = (1 << k) - 1;
    auto &cur = ans[k];
    cur = 0;
    for (int x = 1; x < a; x++) {
      int y = (a ^ x), z = (a & x);
      cur = max(cur, gcd(y, z));
    }
    eprintf("%d,", cur);
  }
  eprintf("};\n");*/
}

int a;

bool read() {
  if (scanf("%d", &a) < 1) {
    return false;
  }
  return true;
}

void solve() {
  int k = 32 - __builtin_clz(a);
  int x = (1 << k) - 1;
  if (a == x) {
    printf("%d\n", ans[k]);
    return;
  }
  printf("%d\n", x);
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