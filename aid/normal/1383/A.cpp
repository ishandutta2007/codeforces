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

const int maxn = (int) 1e5 + 5;
char tmp[maxn];
int n;
string s, t;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  scanf("%s", tmp);
  t = tmp;
  return true;
}

const int sigma = 20;
int a[sigma][sigma];

void solve() {
  for (int i = 0; i < sigma; ++i) {
    for (int j = 0; j < sigma; ++j) {
      a[i][j] = false;
    }
  }
  for (int i = 0; i < n; ++i) {
    a[s[i] - 'a'][t[i] - 'a'] = true;
  }
  int res = 0;
  for (int i = 0; i < sigma; ++i) {
    int to = sigma;
    for (int j = 0; j < sigma; ++j) {
      if (i == j) {
        continue;
      }
      if (a[i][j]) {
        to = j;
        break;
      }
    }
    if (to < i) {
      printf("-1\n");
      return;
    }
    if (to < sigma) {
      ++res;
      for (int j = to; j < sigma; ++j) {
        a[to][j] |= a[i][j];
      }
    }
  }
  printf("%d\n", res);
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