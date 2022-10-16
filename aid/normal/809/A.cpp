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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

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

const int maxn = (int) 3e5 + 5;
int n;
int x[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  return true;
}

int s[maxn];

void solve() {
  sort(x, x + n);
  s[0] = 0;
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i];
    add(s[i + 1], x[i]);
  }
  int res = 0;
  for (int k = 1, tomul = 1; k < n; k++, tomul = mul(tomul, 2)) {
    int cur = 0;
    add(cur, mod - s[n - k]);
    add(cur, s[n]);
    add(cur, mod - s[k]);
    add(res, mul(cur, tomul));
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