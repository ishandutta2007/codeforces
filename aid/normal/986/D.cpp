#ifdef DEBUG
//#define _GLIBCXX_DEBUG
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

namespace FFT {
  struct com {
    ld x, y;

    com(ld _x = 0, ld _y = 0) : x(_x), y(_y) {}

    inline com operator + (const com &c) const {
      return com(x + c.x, y + c.y);
    }
    inline com operator - (const com &c) const {
      return com(x - c.x, y - c.y);
    }
    inline com operator * (const com &c) const {
      return com(x * c.x - y * c.y, x * c.y + y * c.x);
    }
    inline com conj() const {
      return com(x, -y);
    }
  };

  const static int maxk = 21, maxn = (1 << maxk) + 1;
  com ws[maxn];
  int dp[maxn];
  com rs[maxn];
  int n, k;
  int lastk = -1;

  void fft(com *a, bool torev = 0) {
    if (lastk != k) {
      lastk = k;
      dp[0] = 0;

      for (int i = 1, g = -1; i < n; ++i) {
        if (!(i & (i - 1))) {
          ++g;
        }
        dp[i] = dp[i ^ (1 << g)] ^ (1 << (k - 1 - g));
      }

      ws[1] = com(1, 0);
      for (int two = 0; two < k - 1; ++two) {
        ld alf = pi / n * (1 << (k - 1 - two));
        com cur = com(cos(alf), sin(alf));

        int p2 = (1 << two), p3 = p2 * 2;
        for (int j = p2; j < p3; ++j) {
          ws[j * 2 + 1] = (ws[j * 2] = ws[j]) * cur;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      if (i < dp[i]) {
        swap(a[i], a[dp[i]]);
      }
    }
    if (torev) {
      for (int i = 0; i < n; ++i) {
        a[i].y = -a[i].y;
      }
    }
    for (int len = 1; len < n; len <<= 1) {
      for (int i = 0; i < n; i += len) {
        int wit = len;
        for (int it = 0, j = i + len; it < len; ++it, ++i, ++j) {
          com tmp = a[j] * ws[wit++];
          a[j] = a[i] - tmp;
          a[i] = a[i] + tmp;
        }
      }
    }
  }

  com a[maxn];
  void mul(const vector<int> &_a, const vector<int> &_b, vector<long long> &ans) {
    int na = sz(_a), nb = sz(_b);
    ans.clear();
    if (!na || !nb) {
      return;
    }
    for (k = 0, n = 1; n < na + nb - 1; n <<= 1, ++k) ;
    assert(n < maxn);
    for (int i = 0; i < n; ++i) {
      a[i] = com(i < na ? _a[i] : 0, i < nb ? _b[i] : 0);
    }
    fft(a);
    a[n] = a[0];
    for (int i = 0; i <= n - i; ++i) {
      a[i] = (a[i] * a[i] - (a[n - i] * a[n - i]).conj()) * com(0, (ld) -1 / n / 4);
      a[n - i] = a[i].conj();
    }
    fft(a, 1);
    for (int i = 0; i < n; ++i) {
      long long val = (long long) round(a[i].x);
      assert(abs(val - a[i].x) < 1e-1);
      if (val) {
        assert(i < na + nb - 1);
        ans.resize(i + 1);
        ans[i] = val;
      }
    }
  }
};

const int len = 5, p = (int) 1e5;

struct Num {
  vector<int> a;

  Num(int x) {
    while (x) {
      a.push_back(x % p);
      x /= p;
    }
  }

  Num(const vector<int> &_a): a(_a) {}

  Num(const string &s) {
    for (int i = 0; i < sz(s); i += len) {
      int cur = 0;
      for (int j = len - 1; j >= 0; j--) {
        cur = cur * 10 + (i + j < sz(s) ? s[i + j] - '0' : 0);
      }
      a.push_back(cur);
    }
  }

  Num() {}

  Num operator * (const Num &num) const {
    vector<long long> ans;
    FFT::mul(a, num.a, ans);
    long long cur = 0;
    for (int i = 0; i < sz(ans) || cur; i++) {
      if (i >= sz(ans)) {
        ans.resize(i + 1);
      }
      cur += ans[i];
      ans[i] = cur % p;
      cur /= p;
    }
    vector<int> ans1;
    for (int i = 0; i < sz(ans); i++) {
      ans1.push_back(ans[i]);
    }
    return Num(ans1);
  }

  Num operator * (int k) const {
    vector<int> ans(sz(a));
    int cur = 0;
    for (int i = 0; i < sz(a) || cur; i++) {
      if (i >= sz(ans)) {
        ans.resize(i + 1);
      }
      cur += (i < sz(a) ? a[i] : 0) * 3;
      ans[i] = cur % p;
      cur /= p;
    }
    return Num(ans);
  }

  Num operator / (int k) const {
    vector<int> ans(sz(a));
    int cur = 0;
    for (int i = sz(a) - 1; i >= 0; i--) {
      cur = cur * p + a[i];
      ans[i] = cur / k;
      cur %= k;
    }
    if (cur) {
      int pos = 0;
      while (pos < sz(ans) && ans[pos] + 1 >= p) {
        ans[pos] = 0;
        pos++;
      }
      if (pos >= sz(ans)) {
        ans.resize(pos + 1);
      }
      ans[pos]++;
    }
    while (!ans.empty() && !ans.back()) {
      ans.pop_back();
    }
    return Num(ans);
  }

  bool operator < (const Num &n) const {
    if (sz(a) != sz(n.a)) {
      return sz(a) < sz(n.a);
    }
    for (int i = sz(a) - 1; i >= 0; i--) {
      if (a[i] != n.a[i]) {
        return a[i] < n.a[i];
      }
    }
    return false;
  }
};

const int maxlen = (int) 2e6 + 5;
string s;
char tmp[maxlen];
Num n;

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  reverse(s.begin(), s.end());
  n = Num(s);
  return true;
}

Num myPow(Num x, int p) {
  Num res(1);
  while (p) {
    if (p & 1) {
      res = res * x;
    }
    x = x * x;
    p >>= 1;
  }
  return res;
}

Num ns[3];
int p3;
Num cur;

int solve1(const Num &n) {
  if (!sz(n.a) || (sz(n.a) == 1 && n.a[0] == 1)) {
    return 0;
  }
  while (cur < n) {
    cur = cur * 3;
    p3++;
  }
  return p3 * 3;
}

void solve() {
  for (int p2 = 0; p2 < 3; p2++) {
    ns[p2] = n;
    n = n / 2;
  }
  p3 = (log10(ns[2].a.back()) + len * (sz(ns[2].a) - 1)) / log10(3) - 1;
  p3 = max(p3, 0);
  cur = myPow(Num(3), p3);
  int res = inf;
  for (int p2 = 2; p2 >= 0; p2--) {
    res = min(res, p2 * 2 + solve1(ns[p2]));
  }
  res = max(res, 1);
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