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

const int maxn = 105;
int n, m;
int h[maxn];
int who[maxn];
int a[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    who[i] = -1;
  }
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d%d", &x, &h[i]);
    x--;
    who[x] = i;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int dp[maxn];
int used[maxn];

bool solve1(bool rev) {
  int l = 0, r = n - 1;
  while (who[l] == -1) {
    l++;
  }
  while (who[r] == -1) {
    r--;
  }
  for (int t = 0; t < n; t++) {
    memset(dp, -1, sizeof(dp));
    dp[t] = t;
    for (int i = t; i < n; i++) {
      if (dp[i] == -1) {
        continue;
      }
      for (int j = i + 1; j < n; j++) {
        if (who[j] == -1 || dp[j] != -1) {
          continue;
        }
        int curh = h[who[j]];
        bool ok = true;
        for (int k = j; k >= i; k--) {
          curh += a[k];
          if (curh < 0) {
            ok = false;
            break;
          }
        }
        if (ok) {
          dp[j] = i;
        }
      }
    }
    for (int i = t; i >= 0; i--) {
      if (dp[i] == -1) {
        continue;
      }
      for (int j = i - 1; j >= 0; j--) {
        if (who[j] == -1 || dp[j] != -1) {
          continue;
        }
        int curh = h[who[j]];
        bool ok = true;
        for (int k = j; k < i; k++) {
          curh += a[k];
          if (curh < 0) {
            ok = false;
            break;
          }
        }
        if (ok) {
          dp[j] = i;
        }
      }
    }
    if (t < r && dp[r] == -1) {
      continue;
    }
    if (l < t && dp[l] == -1) {
      continue;
    }
    printf("%d\n", (rev ? n - t - 1 : t) + 1);
    for (int i = 0; i < m; i++) {
      used[i] = false;
    }
    vector<int> ans;
    if (l < t) {
      for (int i = l; i < t; i = dp[i]) {
        ans.push_back(who[i]);
        used[who[i]] = true;
      }
    }
    if (t < r) {
      for (int i = r; i > t; i = dp[i]) {
        ans.push_back(who[i]);
        used[who[i]] = true;
      }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < m; i++) {
      if (!used[i]) {
        ans.push_back(i);
      }
    }
    for (int i = 0; i < m; i++) {
      printf("%d ", ans[i] + 1);
    }
    printf("\n");
    return true;
  }
  return false;
}

void solve() {
  if (solve1(false)) {
    return;
  }
  reverse(who, who + n);
  reverse(a, a + n);
  if (solve1(true)) {
    return;
  }
  printf("-1\n");
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