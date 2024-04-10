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

const int maxn = (int) 2e5 + 5;
int n;
int a[maxn];
char tmp[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", tmp);
  for (int i = 0; i < n; i++) {
    a[i] = tmp[i] - '0';
  }
  return true;
}

int fst[10];
int lst[10];
int b[maxn];
char ans[maxn];

void solve() {
  for (int i = 0; i < 10; i++) {
    lst[i] = -1;
    fst[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    lst[a[i]] = i;
  }
  for (int i = n - 1; i >= 0; i--) {
    fst[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    ans[i] = '2';
  }
  int pd = -1;
  for (int d = 0; d < 10; d++) {
    if (fst[d] == -1) {
      continue;
    }
    if (pd != -1 && fst[d] < lst[pd]) {
      for (int i = lst[pd] + 1; i < n; i++) {
        if (a[i] == d) {
          ans[i] = '1';
        }
      }
      break;
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == d) {
        ans[i] = '1';
      }
    }
    pd = d;
  }
  int pos = 0;
  for (int i = 0; i < n; i++) {
    if (ans[i] == '1') {
      b[pos++] = a[i];
    }
  }
  for (int i = 0; i < n; i++) {
    if (ans[i] == '2') {
      b[pos++] = a[i];
    }
  }
  for (int i = 0; i + 1 < n; i++) {
    if (b[i + 1] < b[i]) {
      printf("-\n");
      return;
    }
  }
  ans[n] = 0;
  printf("%s\n", ans);
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