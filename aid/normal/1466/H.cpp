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

const int maxn = 45;
int f[maxn], invs[maxn], finv[maxn];

void precalc() {
  f[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    f[i] = mul(f[i - 1], i);
  }
  invs[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    invs[i] = (mod - (long long) (mod / i) * invs[mod % i] % mod) % mod;
  }
  finv[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    finv[i] = mul(finv[i - 1], invs[i]);
  }
}

int c(int n, int k) {
  return mul(f[n], mul(finv[n - k], finv[k]));
}

int n;
int p[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
  }
  return true;
}

map<pair<vector<pair<int, int>>, int>, int> dp;

int getN(const vector<pair<int, int>> &a) {
  int n = 0;
  for (int i = 0; i < sz(a); ++i) {
    n += a[i].first * a[i].second;
  }
  return n;
}

int rec(const vector<pair<int, int>> &a, int l);

int rec1(int i, const vector<pair<int, int>> &a, vector<pair<int, int>> &b, int l, int n) {
  if (i >= sz(a)) {
    int m = getN(b);
    if (m >= n) {
      return 0;
    }
    int res = rec(b, n - m);
    for (int i = 0; i < n - m; ++i) {
      res = mul(res, f[n - 1]);
    }
    for (int i = 0; i < m; ++i) {
      res = mul(res, mul(f[n + l], finv[n]));
    }
    return res;
  }
  int c = a[i].first;
  int val;
  if (l) {
    int all = 1, bad = 1;
    for (int k = 0; k < c; ++k) {
      all = mul(all, mul(f[n + l], finv[n]));
      bad = mul(bad, mul(f[n + l - 1], finv[n - 1]));
    }
    val = all;
    add(val, mod - bad);
  } else {
    val = 1;
  }
  int cur = 1;
  b.push_back(make_pair(c, 0));
  int res = 0;
  for (int x = 0; x < a[i].second; ++x) {
    b.back().second = a[i].second - x;
    add(res, mul(mul(::c(a[i].second, x), cur), rec1(i + 1, a, b, l, n)));
    cur = mul(cur, val);
  }
  b.pop_back();
  add(res, mul(cur, rec1(i + 1, a, b, l, n)));
  return res;
}

int rec(const vector<pair<int, int>> &a, int l) {
  if (dp.count(make_pair(a, l))) {
    return dp[make_pair(a, l)];
  }
  if (a.empty()) {
    return dp[make_pair(a, l)] = 1;
  }
  vector<pair<int, int>> b;
  int res = rec1(0, a, b, l, getN(a));
  return dp[make_pair(a, l)] = res;
}

int used[maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    used[i] = false;
  }
  vector<pair<int, int>> a;
  for (int s = 0; s < n; ++s) {
    if (used[s]) {
      continue;
    }
    int len = 0;
    for (int v = s; !used[v]; v = p[v]) {
      ++len;
      used[v] = true;
    }
    a.push_back(make_pair(len, 1));
  }
  sort(a.begin(), a.end());
  {
    int k = 1;
    for (int i = 1; i < sz(a); ++i) {
      if (a[i].first == a[k - 1].first) {
        a[k - 1].second += a[i].second;
      } else {
        a[k++] = a[i];
      }
    }
    a.resize(k);
  }
  dp.clear();
  printf("%d\n", rec(a, 0));
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