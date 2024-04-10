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

const int maxn = 105;
int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

int p[maxn];

void ask(int x) {
  int a = x, b = 0;
  int toadd = max(1 - a, 1 - b);
  a += toadd;
  b += toadd;
  printf("?");
  for (int i = 0; i < n - 1; ++i) {
    printf(" %d", a);
  }
  printf(" %d\n", b);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  --res;
  if (res >= 0) {
    p[res] = -x;
  }
}

void solve() {
  p[n - 1] = 0;
  for (int x = -n + 1; x <= n - 1; ++x) {
    if (x == 0) {
      continue;
    }
    ask(x);
  }
  int mn = 0;
  for (int i = 0; i < n; ++i) {
    mn = min(mn, p[i]);
  }
  for (int i = 0; i < n; ++i) {
    p[i] += 1 - mn;
  }
  printf("!");
  for (int i = 0; i < n; ++i) {
    printf(" %d", p[i]);
  }
  printf("\n");
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