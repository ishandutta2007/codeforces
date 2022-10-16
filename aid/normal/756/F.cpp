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

void add(int &a, int b, int mod = ::mod) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int sum(int a, int b, int mod = ::mod) {
  add(a, b, mod);
  return a;
}

int mul(int a, int b, int mod = ::mod) {
  return (long long) a * b % mod;
}

int power(int x, int p, int mod = ::mod) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mul(res, x, mod);
    }
    p >>= 1;
    x = mul(x, x, mod);
  }
  return res;
}

pair<int, int> gcd(int a, int b) {
  if (!b) {
    return make_pair(1, 0);
  }
  pair<int, int> p = gcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x) {
  int res = gcd(x, mod).first;
  if (res < 0) {
    res += mod;
  }
  return res;
}

string sub(const string &a, const string &b) {
  assert(sz(a) == sz(b));
  int n = sz(a);
  string res(n, 0);
  int carry = 0;
  for (int i = n - 1; i >= 0; i--) {
    int cur = (a[i] - '0') - (b[i] - '0') + carry;
    carry = 0;
    if (cur < 0) {
      cur += 10;
      carry = -1;
    }
    res[i] = cur + '0';
  }
  int l = 0;
  while (l < n && res[l] == '0') {
    l++;
  }
  res.erase(res.begin(), res.begin() + l);
  return res;
}

string inc(string s) {
  for (int i = sz(s) - 1; i >= 0; i--) {
    if (s[i] != '9') {
      s[i]++;
      return s;
    }
    s[i] = '0';
  }
  s.insert(s.begin(), '1');
  return s;
}

int strMod(const string &s, int mod = ::mod) {
  int len = sz(s);
  int x = 0;
  for (int i = 0; i < len; i++) {
    x = mul(x, 10, mod);
    add(x, s[i] - '0', mod);
  }
  return x;
}

struct T {
  int x, len;

  T(): x(0), len(0) {}

  T(int _x, int _len): x(_x), len(_len) {}

  T(const string &s) {
    x = strMod(s, mod);
    len = sz(s);
  }

  T operator + (const T &t) const {
    return T(sum(mul(x, power(10, t.len)), t.x), sum(len, t.len, mod - 1));
  }

  T operator * (const string &s) const {
    T res;
    T x = *this;
    for (int i = sz(s) - 1; i >= 0; i--) {
      T y;
      for (int d = 0; d < 10; d++) {
        if (d == s[i] - '0') {
          res = res + y;
        }
        y = y + x;
      }
      x = y;
    }
    return res;
  }

  T(const string &ls, const string &rs) {
    if (sz(ls) == sz(rs)) {
      int l = sz(ls);
      string k = sub(rs, ls);
      *this = T(ls) * inc(k);
      int pl = power(10, l);
      int q = inv(sum(1, mod - pl));
      int km = strMod(k);
      int km1 = strMod(k, mod - 1);
      int toadd = mul(q, sum(km, mod - mul(pl, mul(sum(1, mod - power(pl, km1)), q))));
      add(x, toadd);
      return;
    }
    assert(sz(ls) < sz(rs));
    *this = T(ls, string(sz(ls), '9'));
    for (int l = sz(ls) + 1; l < sz(rs); l++) {
      int ppl = power(10, l - 1);
      int pl = mul(ppl, 10);
      int q = inv(sum(1, mod - pl));
      int ppl1 = power(10, l - 1, mod - 1);
      int km = sum(mul(ppl, 9), mod - 1);
      int km1 = sum(mul(ppl1, 9, mod - 1), mod - 2, mod - 1);
      int km11 = sum(km1, 1, mod - 1);
      T cur(mul(ppl, mul(sum(1, mod - power(pl, km11)), q)), mul(km11, l, mod - 1));
      int toadd = mul(q, sum(km, mod - mul(pl, mul(sum(1, mod - power(pl, km1)), q))));
      add(cur.x, toadd);
      *this = *this + cur;
    }
    *this = *this + T("1" + string(sz(rs) - 1, '0'), rs);
  }
};

string s;

int read() {
  if (!getline(cin, s)) {
    return false;
  }
  return true;
}

T getExp(int &pos) {
  T res;
  while (true) {
    string x;
    assert(isdigit(s[pos]));
    while (pos < sz(s) && isdigit(s[pos])) {
      x += s[pos];
      pos++;
    }
    if (s[pos] == '-') {
      string y;
      pos++;
      assert(isdigit(s[pos]));
      while (pos < sz(s) && isdigit(s[pos])) {
        y += s[pos];
        pos++;
      }
      res = res + T(x, y);
    } else if (s[pos] == '(') {
      pos++;
      res = res + getExp(pos) * x;
      assert(s[pos] == ')');
      pos++;
    } else {
      res = res + T(x);
    }
    if (pos >= sz(s) || s[pos] != '+') {
      break;
    }
    pos++;
  }
  return res;
}

void solve() {
  int pos = 0;
  T res = getExp(pos);
  assert(pos == sz(s));
  printf("%d\n", res.x);
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