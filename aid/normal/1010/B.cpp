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

const int maxn = 35;
int m, n;

int read() {
  if (scanf("%d%d", &m, &n) < 2) {
    return false;
  }
  return true;
}

int ask(int y) {
  printf("%d\n", y + 1);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  if (res == 0 || res == -2) {
    exit(0);
  }
  return res;
}

int a[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    a[i] = (ask(0) == 1);
  }
  int l = 0, r = m;
  int it = 0;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    int res = ask(mid);
    if (!a[it % n]) {
      res *= -1;
    }
    if (res == 1) {
      l = mid;
    } else {
      r = mid;
    }
    it++;
  }
  ask(l);
  assert(false);
}

int main() {
  precalc();
  read();
  solve();
  return 0;
}