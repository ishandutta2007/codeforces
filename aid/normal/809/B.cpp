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

int n, k;

int read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  return true;
}

int getMid(int l, int r) {
  return (l + r) / 2;
}

char tmp[10];

int ask(int x, int y) {
  printf("1 %d %d\n", x + 1, y + 1);
  fflush(stdout);
  scanf("%s", tmp);
  return tmp[0] == 'T';
}

int get(int l, int r) {
  if (l >= r) {
    return -1;
  }
  if (r - l <= 4) {
    int res = l;
    for (int i = l + 1; i < r; i++) {
      if (!ask(res, i)) {
        res = i;
      }
    }
    return res;
  }
  int len = (r - l + 1) / 2;
  int lmid = getMid(l, l + len);
  int rmid = getMid(r - len, r) - ((len & 1) ^ 1);
  if (ask(lmid, rmid)) {
    return get(l, l + len);
  } else {
    return get(r - len, r);
  }
}

void solve() {
  int x = get(0, n);
  //eprintf("x = %d\n", x);
  int y0 = get(0, x);
  //eprintf("y0 = %d\n", y0);
  int y1 = get(x + 1, n);
  //eprintf("y1 = %d\n", y1);
  int y;
  if (y0 == -1) {
    y = y1;
  } else if (y1 == -1) {
    y = y0;
  } else {
    if (ask(y0, y1)) {
      y = y0;
    } else {
      y = y1;
    }
  }
  printf("2 %d %d\n", x + 1, y + 1);
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