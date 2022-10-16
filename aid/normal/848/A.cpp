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
int k;

int read() {
  if (scanf("%d", &k) < 1) {
    return false;
  }
  return true;
}

int f[maxn];
int dp[maxn];
int p[maxn];

void solve() {
  if (!k) {
    printf("a\n");
    return;
  }
  f[0] = 0;
  f[1] = 0;
  int n;
  for (n = 2;; n++) {
    f[n] = inf;
    for (int i = 1; i < n; i++) {
      f[n] = min(f[n], f[i] + f[n - i] + i * (n - i));
    }
    if (f[n] > k) {
      break;
    }
  }
  eprintf("%d\n", n);
  for (int i = 0; i <= k; i++) {
    dp[i] = inf;
    p[i] = -1;
  }
  dp[0] = 0;
  for (int i = 0; i < k; i++) {
    auto cur = dp[i];
    if (cur >= inf) {
      continue;
    }
    for (int j = 1; i + f[j] <= k; j++) {
      auto &nxt = dp[i + f[j]];
      if (nxt > cur + 1) {
        nxt = cur + 1;
        p[i + f[j]] = j;
      }
    }
  }
  assert(dp[k] <= 26);
  char c = 'a';
  int cur = k;
  string ans;
  while (cur) {
    int cnt = p[cur];
    assert(cnt != -1);
    cur -= f[cnt];
    ans += string(cnt, c);
    c++;
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