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

const vector<string> nums = {"1110111",
                             "0010010",
                             "1011101",
                             "1011011",
                             "0111010",
                             "1101011",
                             "1101111",
                             "1010010",
                             "1111111",
                             "1111011"};
vector<int> msks;

int getMsk(const string &s) {
  assert(sz(s) == 7);
  int msk = 0;
  for (int i = 0; i < sz(s); i++) {
    if (s[i] == '1') {
      msk |= (1 << i);
    }
  }
  return msk;
}

void precalc() {
  for (int i = 0; i < sz(nums); i++) {
    msks.push_back(getMsk(nums[i]));
  }
}

const int maxn = 2005;
char tmp[maxn];
int n, k;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    string s = tmp;
    a[i] = getMsk(s);
  }
  return true;
}

int dp[maxn][maxn];
string ans;

int light(int x, int y) {
  if ((x & y) != x) {
    return -1;
  }
  return __builtin_popcount(y ^ x);
}

void solve() {
  memset(dp, 0, sizeof(dp));
  dp[n][0] = true;
  for (int i = n; i > 0; i--) {
    for (int j = 0; j <= k; j++) {
      auto cur = dp[i][j];
      if (!cur) {
        continue;
      }
      for (int d = 0; d < 10; d++) {
        int x = light(a[i - 1], msks[d]);
        if (x == -1) {
          continue;
        }
        if (j + x <= k) {
          dp[i - 1][j + x] = true;
        }
      }
    }
  }
  if (!dp[0][k]) {
    printf("-1\n");
    return;
  }
  ans = "";
  for (int i = 0, j = k; i < n; i++) {
    for (int d = 9; d >= 0; d--) {
      int x = light(a[i], msks[d]);
      if (x == -1 || x > j || !dp[i + 1][j - x]) {
        continue;
      }
      ans += (char) ('0' + d);
      j -= x;
      break;
    }
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