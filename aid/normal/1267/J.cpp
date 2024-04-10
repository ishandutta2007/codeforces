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

const int maxn = (int) 2e6 + 5;
int n;
int cnt[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    x--;
    cnt[x]++;
  }
  return true;
}

void solve() {
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (cnt[i]) {
      cnt[k++] = cnt[i];
    }
  }
  int ms = inf;
  for (int i = 0; i < k; i++) {
    ms = min(ms, cnt[i] + 2);
  }
  int res = n;
  for (int s = 1; s < ms; s++) {
    int cur = 0;
    for (int i = 0; i < k; i++) {
      int x = (cnt[i] + s - 1) / s;
      if (x * (s - 1) > cnt[i]) {
        cur = inf;
        break;
      }
      cur += x;
    }
    res = min(res, cur);
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