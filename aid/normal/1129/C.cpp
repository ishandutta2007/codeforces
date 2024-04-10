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

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = 3005;
int n;
string s;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  s = "";
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    s += (char) ('0' + x);
  }
  return true;
}

int z[maxn];

int getZ(const string &s) {
  for (int i = 0; i < sz(s); i++) {
    z[i] = 0;
  }
  int res = 0;
  for (int i = 1, l = 0, r = -1; i < sz(s); i++) {
    if (i + z[i - l] < r) {
      z[i] = z[i - l];
    } else {
      l = i;
      r = max(r, i);
      while (r < sz(s) && s[r] == s[r - l]) {
        r++;
      }
      z[i] = r - l;
    }
    res = max(res, z[i]);
  }
  return res;
}

int bad[maxn];
int dp[maxn][maxn];

void solve() {
  for (int i = 0; i <= n; i++) {
    bad[i] = false;
  }
  for (int i = 0; i + 4 <= n; i++) {
    string t = s.substr(i, 4);
    if (t == "0011" || t == "0101" || t == "1110" || t == "1111") {
      bad[i + 4] = true;
    }
  }
  for (int i = 0; i <= n; i++) {
    dp[i][i] = 1;
  }
  for (int len = 1; len <= n; len++) {
    for (int i = 0; i + len <= n; i++) {
      int j = i + len;
      auto &cur = dp[i][j];
      cur = 0;
      for (int k = 1; k <= 4 && k <= len; k++) {
        if (k == 4 && bad[j]) {
          continue;
        }
        add(cur, dp[i][j - k]);
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    string t = s.substr(0, i + 1);
    reverse(t.begin(), t.end());
    int k = getZ(t);
    for (int len = k + 1; len <= i + 1; len++) {
      add(res, dp[i + 1 - len][i + 1]);
    }
    printf("%d\n", res);
  }
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