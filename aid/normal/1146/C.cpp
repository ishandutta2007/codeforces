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

const int maxb = 8;
vector<int> a[2];

int ask() {
  if (a[0].empty() || a[1].empty()) {
    return 0;
  }
  printf("%d %d ", sz(a[0]), sz(a[1]));
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < sz(a[t]); i++) {
      printf("%d ", a[t][i] + 1);
    }
  }
  printf("\n");
  fflush(stdout);
  int res;
  scanf("%d", &res);
  if (res == -1) {
    exit(0);
  }
  return res;
}

void solve() {
  int res = 0;
  for (int b = 0; b < maxb; b++) {
    a[0].clear();
    a[1].clear();
    for (int v = 0; v < n; v++) {
      a[(v >> b) & 1].push_back(v);
    }
    res = max(res, ask());
  }
  printf("%d %d\n", -1, res);
  fflush(stdout);
}

int main() {
  precalc();
  int t;
  scanf("%d", &t);
  for (int tt = 0; tt < t; tt++) {
    read();
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}