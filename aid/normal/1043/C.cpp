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

const int maxn = 1005;
int n;
char tmp[maxn];
string s;

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

int ans[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    ans[i] = false;
  }
  int pos = 0;
  while (pos < n && s[pos] == s[0]) {
    pos++;
  }
  if (pos >= n) {
    for (int i = 0; i < n; i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
    return;
  }
  char cur = s[pos];
  while (pos < n) {
    while (pos < n && s[pos] == cur) {
      pos++;
    }
    if (pos >= n) {
      break;
    }
    ans[pos - 1] = true;
    cur = s[pos];
  }
  if (cur == 'a') {
    ans[n - 1] = true;
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
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