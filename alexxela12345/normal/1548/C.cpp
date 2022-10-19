#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

using namespace std;

#define sz(v) ((int)(v).size())
#define endl '\n'

typedef long long ll;
typedef long double ldb;

namespace FFT {
template <int MOD> inline constexpr int mul(int a, int b) {
  return 1LL * a * b % MOD;
}

template <int MOD> inline constexpr int add(int a, int b) {
  a += b;
  if (a >= MOD)
    a -= MOD;
  return a;
}

template <int MOD> inline constexpr int sub(int a, int b) {
  a -= b;
  if (a < 0)
    a += MOD;
  return a;
}

template <int MOD> inline constexpr int powmod(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) {
      ans = mul<MOD>(ans, a);
    }
    a = mul<MOD>(a, a);
    b >>= 1;
  }
  return ans;
}

template <int MOD> inline constexpr int rev(int a) {
  return powmod<MOD>(a, MOD - 2);
}

template <int MOD> inline constexpr int getGenerator() {
  if (MOD == 998244353) {
    return 3;
  }
  int divs[20] = {};
  int n = MOD - 1;
  int cur = 2;
  int pos = 0;
  while (cur * cur <= n) {
    if (n % cur == 0) {
      divs[pos++] = cur;
      while (n % cur == 0)
        n /= cur;
    }
    cur++;
  }
  for (int g = 2;; g++) {
    bool bad = 0;
    for (int i = 0; i < pos; i++) {
      if (powmod<MOD>(g, (MOD - 1) / divs[i]) == 1) {
        bad = 1;
        break;
      }
    }
    if (!bad)
      return g;
  }
}
template <int MOD> constexpr int generator = getGenerator<MOD>();

template <int MOD> vector<int> roots = {-1};

template <int MOD> void initRoots(int n) {
  roots<MOD>.resize(2 * n, -1);
  for (int k = 1; k < n; k *= 2) {
    if (roots<MOD>[k] != -1) {
      continue;
    }
    int w = powmod<MOD>(generator<MOD>, (MOD - 1) / (2 * k));
    int cur = 1;
    for (int i = 0; i < k; i++) {
      roots<MOD>[k + i] = cur;
      cur = mul<MOD>(cur, w);
    }
  }
}

inline constexpr unsigned int reverse_bits(unsigned int n) {
  n = ((n & 0xFFFF0000) >> 16) | ((n & 0x0000FFFF) << 16);
  n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
  n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
  n = ((n & 0b11001100110011001100110011001100) >> 2) | ((n & 0b00110011001100110011001100110011) << 2);
  n = ((n & 0b10101010101010101010101010101010) >> 1) | ((n & 0b01010101010101010101010101010101) << 1);
  return n;
}

template <int MOD> void ntt(vector<int> &a, unsigned int n) {
  assert((MOD - 1) % n == 0);
  int bitlen = 0;
  while ((1U << bitlen) != n)
    bitlen++;
  for (unsigned i = 0; i < n; i++) {
    // unsigned int ri = 0;
    // for (int j = 0; j < bitlen; j++) {
    //   if (i & (1 << j)) {
    //     ri ^= (1 << (bitlen - j - 1));
    //   }
    // }

     unsigned int ri = reverse_bits(i) >> (32 - bitlen);
    if (i < ri) {
      a[i] ^= a[ri];
      a[ri] ^= a[i];
      a[i] ^= a[ri];
      // swap(a[i], a[ri]);
    }
  }
  initRoots<MOD>(n);
  for (unsigned int k = 1; k < n; k *= 2) {
    for (unsigned int i = 0; i < n; i += 2 * k) {
      for (unsigned int j = 0; j < k; j++) {
        int x = a[i + j];
        int y = mul<MOD>(roots<MOD>[k + j], a[i + j + k]);
        a[i + j] = add<MOD>(x, y);
        a[i + j + k] = sub<MOD>(x, y);
      }
    }
  }
}

template <int MOD>
vector<int> conv(const vector<int> &a, const vector<int> &b) {
  int sz = max(sz(a), sz(b)) << 1;
  // round sz to nearest power of 2
  while (sz & (sz - 1)) {
    sz = (sz | (sz - 1)) + 1;
  }
  assert(__builtin_popcount(sz) == 1);
  vector<int> c = a;
  vector<int> d = b;
  c.resize(sz);
  d.resize(sz);
  ntt<MOD>(c, sz);
  ntt<MOD>(d, sz);
  int rsz = rev<MOD>(sz);
  for (int i = 0; i < sz; i++) {
    c[i] = mul<MOD>(c[i], d[i]);
    c[i] = mul<MOD>(c[i], rsz);
  }
  reverse(c.begin() + 1, c.end());
  ntt<MOD>(c, sz);
  return c;
}
}; // namespace FFT

const int MOD = 1e9 + 7;

#define add(a, b) FFT::add<MOD>(a, b)
#define sub(a, b) FFT::sub<MOD>(a, b)
#define mul(a, b) FFT::mul<MOD>(a, b)
#define powmod(a, b) FFT::powmod<MOD>(a, b)
#define rev(a) FFT::rev<MOD>(a)

struct Poly {
  vector<int> arr;

  Poly() {}
  Poly(vector<int> arr_) : arr(arr_) {
    while (sz(arr) > 1 && arr.back() == 0)
      arr.pop_back();
  }

  int operator()(int);
};

Poly operator+(const Poly &a, const Poly &b) {
  vector<int> ans;
  ans.resize(max(sz(a.arr), sz(b.arr)));
  for (int i = 0; i < sz(a.arr); i++) {
    ans[i] = add(ans[i], a.arr[i]);
  }
  for (int i = 0; i < sz(b.arr); i++) {
    ans[i] = add(ans[i], b.arr[i]);
  }
  return Poly(move(ans));
}

Poly operator-(const Poly &a) {
  vector<int> ans;
  ans.resize(sz(a.arr));
  for (int i = 0; i < sz(ans); i++)
    ans[i] = sub(0, a.arr[i]);
  return Poly(move(ans));
}

Poly operator-(const Poly &a, const Poly &b) { return a + (-b); }

Poly operator-(const int &a, const Poly &b) { return Poly({a}) - b; }

Poly operator*(const Poly &a, const Poly &b) {
  return Poly(FFT::conv<MOD>(a.arr, b.arr));
}

int Poly::operator()(int x) {
  int ans = 0;
  for (int i = sz(arr) - 1; i >= 0; i--) {
    ans = mul(ans, x);
    ans = add(ans, arr[i]);
  }
  return ans;
}

int deg(const Poly &a) { return sz(a.arr) - 1; }

Poly reverse(const Poly &A, int need) {
  Poly B({rev(A.arr[0])});
  while (sz(B.arr) < need) {
    Poly A1;
    A1.arr.resize(2 * sz(B.arr));
    copy(A.arr.begin(), A.arr.begin() + min(sz(A1.arr), sz(A.arr)),
         A1.arr.begin());
    Poly B1 = B * (2 - A1 * B);
    B1.arr.resize(2 * sz(B.arr));
    B = B1;
  }
  B.arr.resize(need);
  return B;
}

Poly div(const Poly &a, const Poly &b) {
  int n = deg(a);
  int m = deg(b);
  if (n < m)
    return Poly({0});
  Poly ra = a;
  Poly rb = b;
  reverse(ra.arr.begin(), ra.arr.end());
  reverse(rb.arr.begin(), rb.arr.end());
  ra.arr.resize(n - m + 1);
  rb.arr.resize(n - m + 1);
  Poly irb = reverse(rb, sz(rb.arr));
  Poly q = ra * irb;
  q.arr.resize(n - m + 1);
  reverse(q.arr.begin(), q.arr.end());
  return q;
}

Poly mod(const Poly &a, const Poly &b) { return a - b * div(a, b); }

vector<Poly> multipointEvaluationTree;
vector<int> multipointEvaluationAns;

void multipointEvaluationPrecalc(int v, int l, int r, const vector<int> &xs) {
  if (l + 1 == r) {
    multipointEvaluationTree[v] = Poly({sub(0, xs[l]), 1});
  } else {
    int m = (l + r) / 2;
    multipointEvaluationPrecalc(2 * v + 1, l, m, xs);
    multipointEvaluationPrecalc(2 * v + 2, m, r, xs);
    multipointEvaluationTree[v] = multipointEvaluationTree[2 * v + 1] *
                                  multipointEvaluationTree[2 * v + 2];
  }
}

void multipointEvaluationGetAns(int v, int l, int r, const Poly &p,
                                const vector<int> &xs) {
  Poly p1 = mod(p, multipointEvaluationTree[v]);
  if (r - l <= 500) {
    for (int i = l; i < r; i++) {
      multipointEvaluationAns[i] = p1(xs[i]);
    }
  } else {
    int m = (l + r) / 2;
    multipointEvaluationGetAns(2 * v + 1, l, m, p1, xs);
    multipointEvaluationGetAns(2 * v + 2, m, r, p1, xs);
  }
}

vector<int> multipointEvaluation(const Poly &p, const vector<int> &xs) {
  multipointEvaluationTree.clear();
  multipointEvaluationTree.resize(4 * sz(xs));
  multipointEvaluationPrecalc(0, 0, sz(xs), xs);
  multipointEvaluationAns.resize(sz(xs));
  multipointEvaluationGetAns(0, 0, sz(xs), p, xs);
  return multipointEvaluationAns;
}

Poly derivative(const Poly &p) {
  Poly ans;
  ans.arr.resize(sz(p.arr) - 1);
  for (int i = 0; i < sz(ans.arr); i++) {
    ans.arr[i] = mul(p.arr[i + 1], i + 1);
  }
  return ans;
}

Poly integral(const Poly &p) {
  Poly ans;
  ans.arr.resize(sz(p.arr) + 1);
  for (int i = 1; i < sz(ans.arr); i++) {
    ans.arr[i] = mul(p.arr[i - 1], rev(i));
  }
  return ans;
}

const int MAXN = 3e6 + 228;

int fact[MAXN];
int rfact[MAXN];

int C(int n, int k) { return mul(fact[n], mul(rfact[k], rfact[n - k])); }

int num[MAXN];
int den[4];
int ans[MAXN];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fact[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  rfact[MAXN - 1] = rev(fact[MAXN - 1]);
  for (int i = MAXN - 2; i >= 0; i--) {
    rfact[i] = mul(rfact[i + 1], i + 1);
  }
  int n;
  cin >> n;
  for (int i = 0; i < 3 * n + 4; i++) {
    num[i] = C(3 * n + 3, i);
  }
  num[0] = sub(num[0], C(3, 0));
  num[1] = sub(num[1], C(3, 1));
  num[2] = sub(num[2], C(3, 2));
  num[3] = sub(num[3], C(3, 3));
  for (int i = 1; i <= 3; i++) {
    den[i] = C(3, i);
  }
  int rv = rev(den[3]);
  for (int i = 3 * n + 3; i >= 0; i--) {
    if (num[i] != 0) {
      int cnt = mul(num[i], rv);
      ans[i - 3] = cnt;
      for (int j = 0; j <= 3; j++) {
	num[i - j] = sub(num[i - j], mul(den[3 - j], cnt));
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << ans[x] << endl;
  }
}