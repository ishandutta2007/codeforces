#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e4 + 5;
int n;
int dp[maxn][2];
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

void solve() {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      dp[i][j] = false;
    }
  }
  dp[n][0] = true;
  dp[n][1] = true;
  for (int i = n; i >= 0; i--) {
    for (int j = 0; j < 2; j++) {
      if (!dp[i][j]) {
        continue;
      }
      int len0 = 2 + j;
      for (int k = 0; k < 2; k++) {
        int len1 = 2 + k;
        if (i - len1 < 0) {
          continue;
        }
        if (len0 != len1 || i == n ||
            s.substr(i - len1, len1) != s.substr(i, len0)) {
          dp[i - len1][k] = true;
        }
      }
    }
  }
  vector<string> ans;
  for (int i = 5; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      if (dp[i][j]) {
        int len = 2 + j;
        ans.push_back(s.substr(i, len));
      }
    }
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%s\n", ans[i].c_str());
  }
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}