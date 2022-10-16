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

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

void go(int &x, int &y) {
  ++y;
  if (y >= n) {
    ++x;
    y = 0;
  }
}

void solve() {
  int x0 = 0, y0 = 0, x1 = 0, y1 = 1;
  while (x0 < n && x1 < n) {
    int a;
    scanf("%d", &a);
    if (a != 1) {
      printf("1 %d %d\n", x0 + 1, y0 + 1);
      fflush(stdout);
      go(x0, y0);
      while ((x0 + y0) & 1) {
        go(x0, y0);
      }
    } else {
      printf("2 %d %d\n", x1 + 1, y1 + 1);
      fflush(stdout);
      go(x1, y1);
      while (!((x1 + y1) & 1)) {
        go(x1, y1);
      }
    }
  }
  while (x0 < n || x1 < n) {
    int a;
    scanf("%d", &a);
    if (x0 < n) {
      int b = (a == 1 ? 3 : 1);
      printf("%d %d %d\n", b, x0 + 1, y0 + 1);
      fflush(stdout);
      go(x0, y0);
      while ((x0 + y0) & 1) {
        go(x0, y0);
      }
    } else {
      int b = (a == 2 ? 3 : 2);
      printf("%d %d %d\n", b, x1 + 1, y1 + 1);
      fflush(stdout);
      go(x1, y1);
      while (!((x1 + y1) & 1)) {
        go(x1, y1);
      }
    }
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