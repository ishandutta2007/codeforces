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

const int maxn = (int) 1e5 + 5;
int n;
int a[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int pos[maxn];
int dp[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    pos[a[i]] = i;
  }
  for (int x = n; x >= 1; x--) {
    int i = pos[x];
    auto &cur = dp[i];
    cur = false;
    for (int j = i - x; j >= 0 && !cur; j -= x) {
      if (a[j] > x && !dp[j]) {
        cur = true;
      }
    }
    for (int j = i + x; j < n && !cur; j += x) {
      if (a[j] > x && !dp[j]) {
        cur = true;
      }
    }
  }
  string ans;
  for (int i = 0; i < n; i++) {
    ans += (char) ('A' + !dp[i]);
  }
  printf("%s\n", ans.c_str());
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