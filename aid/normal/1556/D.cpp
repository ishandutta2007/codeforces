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

const int maxn = (int) 1e4 + 5;
int n, k;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  --k;
  return true;
}

void ask(int i, int j, int x[2]) {
  printf("or %d %d\n", i + 1, j + 1);
  fflush(stdout);
  scanf("%d", &x[0]);
  printf("and %d %d\n", i + 1, j + 1);
  fflush(stdout);
  scanf("%d", &x[1]);
}

const int maxb = 30;

void get(int &b, int a, int x[2]) {
  b = 0;
  for (int bit = 0; bit < maxb; ++bit) {
    b ^= (x[(a >> bit) & 1] & (1 << bit));
  }
}

int x[2], y[2], z[2];

void solve() {
  ask(0, 1, x);
  ask(0, 2, y);
  ask(1, 2, z);
  a[0] = 0;
  for (int bit = 0; bit < maxb; ++bit) {
    if (((x[0] >> bit) & 1) == ((x[1] >> bit) & 1)) {
      a[0] ^= (x[0] & (1 << bit));
      continue;
    }
    if (((y[0] >> bit) & 1) == ((y[1] >> bit) & 1)) {
      a[0] ^= (y[0] & (1 << bit));
      continue;
    }
    a[0] ^= (~z[0] & (1 << bit));
  }
  get(a[1], a[0], x);
  get(a[2], a[0], y);
  for (int i = 3; i < n; ++i) {
    ask(0, i, x);
    get(a[i], a[0], x);
  }
  nth_element(a, a + k, a + n);
  printf("finish %d\n", a[k]);
  fflush(stdout);
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