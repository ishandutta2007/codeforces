#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1.01e9;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

const int mod = (int) 1e9 + 7;

void add(int & x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int sum(int x, int y) {
  add(x, y);
  return x;
}

int mult(int x, int y) {
  return (ll) x * y % mod;
}

int power(int x, ll p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
    p >>= 1;
  }
  return res;
}

int inv(int x) {
  return power(x, mod - 2);
}

void precalc() {
}

int gcd(int a, int b) {
  if (!b) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

const int maxn = 2e5 + 100;

int n, m;
int bad[maxn];
int g[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  memset(bad, 0, sizeof(bad));
  for (int i = 0; i < n; i++) {
    int cur = 0;
    scanf("%d", &cur);
    bad[cur] = 1;
  }
  return true;
}

int cnt[maxn];
int dp[maxn], pr[maxn];

void gcdext(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
  } else {
    int k = a / b;
    gcdext(b, a % b, y, x);
    y -= k * x;
  }
}

void solve() {
  memset(cnt, 0, sizeof(cnt));
  vector<vector<int> > v(m + 1);
  for (int i = 0; i < m; i++) {
    if (!bad[i]) {
      cnt[gcd(i, m)]++;
      v[gcd(i, m)].pb(i);
    }
  }
  vector<int> divs;
  for (int i = 1; i <= m; i++) {
    if (m % i == 0) {
      divs.pb(i);
    }
  }
  for (auto i : divs) {
    dp[i] = cnt[i];
    pr[i] = -1;
    for (auto j : divs) {
      if (j >= i) {
        break;
      }
      if (i % j == 0) {
        if (dp[i] < dp[j] + cnt[i]) {
          dp[i] = dp[j] + cnt[i];
          pr[i] = j;
        }
      }
    }
    //eprintf("%d %d %d\n", i, dp[i], pr[i]);
  }
  vector<int> r;
  for (int cur = m; cur != -1; cur = pr[cur]) {
    r.pb(cur);
  }
  reverse(r.begin(), r.end());
  vector<int> ans;
  int cur = 1;
  for (auto i : r) {
    for (auto j : v[i]) {
      int tomult = i / gcd(cur, m);
      cur = ((ll) cur * tomult) % m;
      int a = cur / i;
      int x, y;
      gcdext(a, m / i, x, y);
      if (x < 0) {
        x += m / i;
      }
      int val = ((ll) x * (j / i)) % m * (ll) tomult % m;
      ans.pb(val);
      cur = j;
    }
  }
  assert(sz(ans) == dp[m]);
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d%c", ans[i], " \n"[i == sz(ans) - 1]);
  }
  cur = 1;
  for (int i = 0; i < sz(ans); i++) {
    cur = ((ll) cur * ans[i]) % m;
    assert(!bad[cur]);
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}