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
int q;
int qs[maxn][3];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &qs[i][0]);
    if (qs[i][0] == 1) {
      scanf("%d%d", &qs[i][1], &qs[i][2]);
      qs[i][1]--;
    } else {
      scanf("%d", &qs[i][1]);
    }
  }
  return true;
}

int mx[maxn];
int lst[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    lst[i] = -1;
  }
  for (int i = 0; i < q; i++) {
    if (qs[i][0] == 1) {
      int id = qs[i][1];
      lst[id] = i;
    }
  }
  mx[q] = 0;
  for (int i = q - 1; i >= 0; i--) {
    mx[i] = mx[i + 1];
    if (qs[i][0] == 1) {
      continue;
    }
    mx[i] = max(mx[i], qs[i][1]);
  }
  for (int i = 0; i < n; i++) {
    int x = (lst[i] == -1 ? a[i] : qs[lst[i]][2]);
    x = max(x, mx[lst[i] + 1]);
    printf("%d ", x);
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