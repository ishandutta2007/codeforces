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

vector<int> ans;

void solve() {
  int x = -1;
  for (int i = 1; i < n; ++i) {
    printf("? %d 1\n", i);
    for (int j = 0; j < i; ++j) {
      printf("%d ", j + 1);
    }
    printf("\n");
    printf("%d\n", i + 1);
    fflush(stdout);
    int f;
    scanf("%d", &f);
    if (f) {
      x = i;
      break;
    }
  }
  assert(x >= 0);
  int l = 0, r = x;
  while (l < r - 1) {
    int m = (l + r) / 2;
    printf("? %d 1\n", m);
    for (int i = 0; i < m; ++i) {
      printf("%d ", i + 1);
    }
    printf("\n");
    printf("%d\n", x + 1);
    fflush(stdout);
    int f;
    scanf("%d", &f);
    if (f) {
      r = m;
    } else {
      l = m;
    }
  }
  int y = l;
  ans.clear();
  for (int i = 0; i < x; ++i) {
    if (i != y) {
      ans.push_back(i);
    }
  }
  for (int i = x + 1; i < n; ++i) {
    printf("? 1 1\n");
    printf("%d\n", x + 1);
    printf("%d\n", i + 1);
    fflush(stdout);
    int f;
    scanf("%d", &f);
    if (!f) {
      ans.push_back(i);
    }
  }
  printf("! %d ", sz(ans));
  for (int i = 0; i < sz(ans); ++i) {
    printf("%d ", ans[i] + 1);
  }
  printf("\n");
  fflush(stdout);
}

int main() {
  precalc();
  int t;
  scanf("%d", &t);
  for (int tt = 0; tt < t; ++tt) {
    read();
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}