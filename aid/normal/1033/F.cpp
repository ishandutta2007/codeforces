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

const int maxw = 12, poww = (1 << maxw), poww3 = (int) 6e5 + 5;
int w, n, m;
int a[poww];

int read() {
  if (scanf("%d%d%d", &w, &n, &m) < 3) {
    return false;
  }
  for (int i = 0; i < (1 << w); i++) {
    a[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[x]++;
  }
  return true;
}

int cnt[poww3];

int to3(int x, int diff) {
  int res = 0;
  for (int bit = w - 1; bit >= 0; bit--) {
    if (diff & (1 << bit)) {
      res = res * 3 + 2;
    } else {
      res = res * 3 + ((x >> bit) & 1);
    }
  }
  return res;
}

int gen(const string &s, int pos, int x) {
  if (pos >= sz(s)) {
    return cnt[x];
  }
  int res = 0;
  if (s[pos] == 'A' || s[pos] == 'O' || s[pos] == 'X') {
    res += gen(s, pos + 1, x * 3);
  }
  if (s[pos] == 'X' || s[pos] == 'a' || s[pos] == 'o') {
    res += gen(s, pos + 1, x * 3 + 1);
  }
  if (s[pos] == 'A' || s[pos] == 'o' || s[pos] == 'x') {
    res += gen(s, pos + 1, x * 3 + 2);
  }
  return res;
}

char tmp[100];

void solve() {
  memset(cnt, 0, sizeof(cnt));
  for (int x = 0; x < (1 << w); x++) {
    for (int diff = 0; diff < (1 << w); diff++) {
      int y = (x ^ diff);
      cnt[to3(x, diff)] += a[x] * a[y];
    }
  }
  for (int i = 0; i < m; i++) {
    scanf("%s", tmp);
    string s = tmp;
    printf("%d\n", gen(s, 0, 0));
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}