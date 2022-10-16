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

const int maxn = (int) 4e5 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

void solve() {
  int g = 0;
  while (g < n && a[g] == a[0]) {
    g++;
  }
  int s = 0;
  while (s <= g) {
    if (g + s >= n) {
      printf("0 0 0\n");
      return;
    }
    int cur = a[g + s];
    while (g + s < n && a[g + s] == cur) {
      s++;
    }
  }
  int b = 0;
  while (b <= g) {
    if (g + s + b >= n) {
      printf("0 0 0\n");
      return;
    }
    int cur = a[g + s + b];
    while (g + s + b < n && a[g + s + b] == cur) {
      b++;
    }
  }
  if (2 * (g + s + b) > n) {
    printf("0 0 0\n");
    return;
  }
  while (true) {
    int l = g + s + b;
    int r = l;
    while (r < n && a[r] == a[l]) {
      r++;
    }
    if (2 * (g + s + b + (r - l)) <= n) {
      b += r - l;
    } else {
      break;
    }
  }
  printf("%d %d %d\n", g, s, b);
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