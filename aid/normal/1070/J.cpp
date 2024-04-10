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

const int maxn = (int) 2e5 + 5;
int n, m, k;
string s;
char tmp[maxn];

int read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

const int sigma = 26;
int cnt[sigma];
int dp[maxn];

void solve() {
  for (int i = 0; i < sigma; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < k; i++) {
    cnt[s[i] - 'A']++;
  }
  {
    for (int i = 0; i <= k; i++) {
      dp[i] = false;
    }
    dp[0] = true;
    for (int i = 0; i < sigma; i++) {
      for (int x = k; x >= 0; x--) {
        if (dp[x]) {
          dp[x + cnt[i]] = true;
        }
      }
    }
    for (int x = n; x <= k - m; x++) {
      if (dp[x]) {
        printf("0\n");
        return;
      }
    }
  }
  int res = inf;
  for (int i = 0; i < sigma; i++) {
    for (int i = 0; i <= k; i++) {
      dp[i] = false;
    }
    dp[0] = true;
    for (int j = 0; j < sigma; j++) {
      if (j == i) {
        continue;
      }
      for (int x = k; x >= 0; x--) {
        if (dp[x]) {
          dp[x + cnt[j]] = true;
        }
      }
    }
    for (int x = 0; x <= n; x++) {
      if (dp[x] && k - cnt[i] - x <= m) {
        res = min(res, (n - x) * (m - (k - cnt[i] - x)));
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