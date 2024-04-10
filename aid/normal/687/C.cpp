#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 505;
int n, k;
int c[maxn];
bitset<maxn> dp[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
  }
  return true;
}

void solve() {
  for (int i = 0; i <= k; i++) {
    dp[0][i].reset();
  }
  dp[0][0][0] = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i + 1][j] = (dp[i][j] | (dp[i][j] << c[i]));
      if (j >= c[i]) {
        dp[i + 1][j] |= dp[i][j - c[i]];
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i <= k; i++) {
    if (dp[n][i][k - i]) {
      ans.push_back(i);
    }
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}