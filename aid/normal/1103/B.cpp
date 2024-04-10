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

char tmp[100];

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  string s = tmp;
  if (s != "start") {
    return false;
  }
  return true;
}

char ask(int x, int y) {
  printf("? %d %d\n", x, y);
  fflush(stdout);
  scanf("%s", tmp);
  char res = tmp[0];
  if (res == 'e') {
    exit(0);
  }
  return res;
}

void printAns(int x) {
  printf("! %d\n", x);
  fflush(stdout);
}

void solve() {
  if (ask(0, 1) == 'x') {
    printAns(1);
    return;
  }
  int l = 1;
  while (true) {
    int r = 2 * l;
    if (ask(l, r) == 'x') {
      break;
    } else {
      l = r;
    }
  }
  int a = l;
  int r = 2 * l;
  while (l < r - 1) {
    int m = (l + r) / 2;
    if (ask(a, m) == 'x') {
      r = m;
    } else {
      l = m;
    }
  }
  printAns(r);
}

int main() {
  precalc();
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}