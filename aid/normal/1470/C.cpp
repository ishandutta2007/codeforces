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

int n, k;

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  return true;
}

int cnt;

int ask(int i) {
  ++cnt;
  assert(cnt <= 1000);
  printf("? %d\n", i + 1);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  return res;
}

void printAns(int i) {
  printf("! %d\n", i + 1);
  fflush(stdout);
}

void solve() {
  cnt = 0;
  ask(0);
  int i = 0;
  int d = 1;
  while (true) {
    int x = ask(i);
    if (x < k) {
      break;
    }
    d = min(d + 1, n / 2 - 1);
    i = (i + d) % n;
  }
  i = (i + 1) % n;
  if (ask(i) == k) {
    printAns(i);
    return;
  }
  int l = 0, r = d + 1;
  while (l < r - 1) {
    int m = (l + r) / 2;
    int j = (i + m) % n;
    int x = ask(j);
    if (x == k) {
      printAns(j);
      return;
    }
    if (x < k) {
      l = m;
    } else {
      r = m;
    }
  }
  assert(false);
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