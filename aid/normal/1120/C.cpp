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

const int maxn = 5005;
int n, a, b;
string s;
char tmp[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &a, &b) < 3) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

int z[maxn];

void getZ(const string &s) {
  int n = sz(s);
  for (int i = 0; i < n; i++) {
    z[i] = 0;
  }
  for (int i = 1, l = 0, r = -1; i < n; i++) {
    if (i + z[i - l] < r) {
      z[i] = z[i - l];
    } else {
      l = i;
      r = max(r, i);
      while (r < n && s[r] == s[r - l]) {
        r++;
      }
      z[i] = r - l;
    }
  }
}

int dp[maxn];

void solve() {
  for (int i = 0; i <= n; i++) {
    dp[i] = inf;
  }
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    auto cur = dp[i];
    dp[i + 1] = min(dp[i + 1], cur + a);
    string t = s.substr(i) + '#' + s.substr(0, i);
    getZ(t);
    int len = 0;
    for (int j = n - i + 1; j < n + 1; j++) {
      len = max(len, z[j]);
    }
    for (int j = 1; j <= len; j++) {
      dp[i + j] = min(dp[i + j], cur + b);
    }
  }
  printf("%d\n", dp[n]);
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