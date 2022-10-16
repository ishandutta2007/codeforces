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

const int maxn = 205;
int n, k;
int ls[maxn], rs[maxn];
int used[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < 2 * n; ++i) {
    used[i] = false;
  }
  for (int i = 0; i < k; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x;
    --y;
    used[x] = true;
    used[y] = true;
    if (x > y) {
      swap(x, y);
    }
    ls[i] = x;
    rs[i] = y;
  }
  return true;
}

void solve() {
  int res = 0;
  for (int i = 0; i < k; ++i) {
    for (int j = i + 1; j < k; ++j) {
      if ((ls[i] < ls[j] && ls[j] < rs[i]) != (ls[i] < rs[j] && rs[j] < rs[i])) {
        ++res;
      }
    }
    int cnt = 0;
    for (int x = ls[i] + 1; x < rs[i]; ++x) {
      if (!used[x]) {
        ++cnt;
      }
    }
    cnt = min(cnt, 2 * (n - k) - cnt);
    res += cnt;
  }
  res += (n - k) * (n - k - 1) / 2;
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