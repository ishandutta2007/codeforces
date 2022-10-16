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

const int maxx = (int) 1e8;

vector<int> a;

int ask(int x, int y) {
  printf("0 %d %d\n", x, y);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  return res;
}

void rec(int l, int r) {
  if (l == r - 1) {
    return;
  }
  int m = l + (r - l) / 2;
  int d = ask(m, m);
  if (d == (r - l) / 2) {
    if (!((r - l) & 1)) {
      return;
    }
    if (!ask(r - 1, r - 1)) {
      a.push_back(r - 1);
    }
    return;
  }
  if (!ask(m - d, m - d)) {
    a.push_back(m - d);
    rec(l, m - d);
    rec(m - d, r);
  } else {
    a.push_back(m + d);
    rec(l, m + d);
    rec(m + d, r);
  }
}

void solve() {
  a.clear();
  int l = -maxx + ask(-maxx, -maxx);
  int r = maxx - ask(maxx, maxx);
  a.push_back(l);
  if (l < r) {
    a.push_back(r);
    rec(l, r);
  }
  sort(a.begin(), a.end());
  int x = -maxx;
  {
    int pos = 0;
    while (pos < sz(a) && a[pos] == x) {
      x++;
      pos++;
    }
  }
  vector<int> xs, ys;
  for (int i = 0; i < sz(a); i++) {
    if (!ask(x, a[i])) {
      ys.push_back(a[i]);
    }
    if (!ask(a[i], x)) {
      xs.push_back(a[i]);
    }
  }
  printf("1 %d %d\n", sz(xs), sz(ys));
  for (int i = 0; i < sz(xs); i++) {
    printf("%d ", xs[i]);
  }
  printf("\n");
  for (int i = 0; i < sz(ys); i++) {
    printf("%d ", ys[i]);
  }
  printf("\n");
  fflush(stdout);
}

int main() {
  precalc();
  solve();
  return 0;
}