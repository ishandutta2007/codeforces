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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

int n;

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

char tmp[100];

int ask(int x, int y) {
  assert(0 <= x && x <= (int) 1e9);
  assert(0 <= y && y <= (int) 1e9);
  printf("%d %d\n", x, y);
  fflush(stdout);
  scanf("%s", tmp);
  return tmp[0] == 'w';
}

void solve() {
  int col = ask(0, 1);
  int x = 0;
  int len = (1 << (n - 2));
  for (int i = 1; i < n; i++) {
    int cur = ask(x + len, 1);
    if (cur == col) {
      x += len;
    }
    len >>= 1;
  }
  printf("%d %d %d %d\n", x, 0, x + 1, 2);
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