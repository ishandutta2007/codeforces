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

const int maxn = (int) 1e6 + 5;
int k;
int used[maxn];
int lst;

int read() {
  if (scanf("%d", &k) < 1) {
    return false;
  }
  memset(used, 0, sizeof(used));
  lst = -1;
  for (int i = 0; i < k; i++) {
    int r;
    scanf("%d", &r);
    r--;
    used[r] = true;
    lst = max(lst, r);
  }
  return true;
}

void solve() {
  for (int i = 0; i < maxn && k < 25; i++) {
    if (!used[i]) {
      used[i] = true;
      lst = max(lst, i);
      k++;
    }
  }
  int res = lst + 1 - 25;
  printf("%d\n", res);
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