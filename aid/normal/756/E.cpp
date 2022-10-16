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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

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

struct BigInt {
  static const int p = (int) 1e9;
  static const int len = 9;
  vector<int> a;

  void read() {
    a.clear();
    static char tmp[(int) 1e4 + 5];
    assert(scanf("%s", tmp) == 1);
    string s = tmp;
    reverse(s.begin(), s.end());
    for (int i = 0; i < sz(s); i += len) {
      int cur = 0;
      for (int j = i, p = 1; j < i + len && j < sz(s); j++, p *= 10) {
        cur += (s[j] - '0') * p;
      }
      a.push_back(cur);
    }
  }

  int div(int k) {
    long long carry = 0;
    for (int i = sz(a) - 1; i >= 0; i--) {
      carry *= p;
      long long na = a[i] + carry;
      carry = na % k;
      a[i] = na / k;
    }
    while (!a.empty() && !a.back()) {
      a.pop_back();
    }
    return carry;
  }
};

const int maxn = (int) 3e5 + 5;
int n;
int a[maxn];
int b[maxn];
BigInt x;

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  x.read();
  return true;
}

int need[maxn];
int sb[maxn];
vector<int> dp[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    if (i + 1 < n && a[i] == 1) {
      need[i] = 0;
      continue;
    }
    if (i + 1 < n) {
      need[i] = x.div(a[i]);
    } else {
      if (sz(x.a) > 1) {
        printf("0\n");
        return;
      }
      need[i] = (x.a.empty() ? 0 : x.a[0]);
    }
  }
  for (int i = 0; i < n; i++) {
    sb[i] = b[i];
    if (i) {
      sb[i] += sb[i - 1] / a[i - 1];
    }
  }
  for (int i = 0; i < n; i++) {
    dp[i].clear();
    dp[i].resize(sb[i] + 1);
  }
  if (need[n - 1] > sb[n - 1]) {
    printf("0\n");
    return;
  }
  dp[n - 1][need[n - 1]] = 1;
  for (int i = n - 1; i > 0; i--) {
    vector<int> s(sz(dp[i]));
    for (int j = 0; j < sz(dp[i]); j++) {
      add(s[max(j - b[i], 0)], dp[i][j]);
      if (j + 1 < sz(dp[i])) {
        add(s[j + 1], mod - dp[i][j]);
      }
    }
    for (int j = 0; j + 1 < sz(dp[i]); j++) {
      add(s[j + 1], s[j]);
    }
    for (int j = 0; j < sz(dp[i]); j++) {
      long long nj = (long long) j * a[i - 1] + need[i - 1];
      if (nj <= sb[i - 1]) {
        add(dp[i - 1][nj], s[j]);
      }
    }
  }
  int res = 0;
  for (int i = 0; i <= b[0]; i++) {
    add(res, dp[0][i]);
  }
  printf("%d\n", res);
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