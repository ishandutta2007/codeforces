#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

template <uint MD> struct ModInt {
  using M = ModInt;
  const static M G;
  uint v;
  ModInt(ll _v = 0) { set_v(_v % MD + MD); }
  M& set_v(uint _v) {
    v = (_v < MD) ? _v : _v - MD;
    return *this;
  }
  explicit operator bool() const { return v != 0; }
  M operator-() const { return M() - *this; }
  M operator+(const M& r) const { return M().set_v(v + r.v); }
  M operator-(const M& r) const { return M().set_v(v + MD - r.v); }
  M operator*(const M& r) const { return M().set_v(ull(v) * r.v % MD); }
  M operator/(const M& r) const { return *this * r.inv(); }
  M& operator+=(const M& r) { return *this = *this + r; }
  M& operator-=(const M& r) { return *this = *this - r; }
  M& operator*=(const M& r) { return *this = *this * r; }
  M& operator/=(const M& r) { return *this = *this / r; }
  bool operator==(const M& r) const { return v == r.v; }
  M pow(ll n) const {
    M x = *this, r = 1;
    while (n) {
      if (n & 1) r *= x;
      x *= x;
      n >>= 1;
    }
    return r;
  }
  M inv() const { return pow(MD - 2); }
  friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }
};
using Mint = ModInt<998244353>;
template<> const Mint Mint::G = Mint(3);

template <class Mint> void nft(bool type, V<Mint>& a) {
  int n = int(a.size()), s = 0;
  while ((1 << s) < n) s++;
  assert(1 << s == n);

  static V<Mint> ep, iep;
  while (int(ep.size()) <= s) {
    ep.push_back(Mint::G.pow(Mint(-1).v / (1 << ep.size())));
    iep.push_back(ep.back().inv());
  }
  V<Mint> b(n);
  for (int i = 1; i <= s; i++) {
    int w = 1 << (s - i);
    Mint base = type ? iep[i] : ep[i], now = 1;
    for (int y = 0; y < n / 2; y += w) {
      for (int x = 0; x < w; x++) {
        auto l = a[y << 1 | x];
        auto r = now * a[y << 1 | x | w];
        b[y | x] = l + r;
        b[y | x | n >> 1] = l - r;
      }
      now *= base;
    }
    swap(a, b);
  }
}

template <class Mint> V<Mint> multiply(const V<Mint>& a, const V<Mint>& b) {
  int n = int(a.size()), m = int(b.size());
  if (!n || !m) return {};
  int lg = 0;
  while ((1 << lg) < n + m - 1) lg++;
  int z = 1 << lg;
  auto a2 = a, b2 = b;
  a2.resize(z);
  b2.resize(z);
  nft(false, a2);
  nft(false, b2);
  for (int i = 0; i < z; i++) a2[i] *= b2[i];
  nft(true, a2);
  a2.resize(n + m - 1);
  Mint iz = Mint(z).inv();
  for (int i = 0; i < n + m - 1; i++) a2[i] *= iz;
  return a2;
}

#define int long long

const int MOD = 998244353;

int expo(int x, int p) {
  int ret = 1;
  while(p > 0) {
    if(p&1)
      ret = (ret*x)%MOD;
    p >>= 1;
    x = (x*x)%MOD;
  }
  return ret;
}

int inv(int x) {
  return expo(x, MOD-2);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int fact[n];
  fact[0] = 1;
  for(int i = 1; i < n; i++)
    fact[i] = (fact[i-1]*i)%MOD;

  int dp[n], dp2[n];
  dp[0] = dp2[0] = 1;
  
  int k = (n-1)/2;

  // dp[n]: n nodes except root
  // one guy can have at max k
  // for i goes from 0 to k-1: (n-1)!*dp[n-1-i]/(n-i-1)!;

  for(int i = 1; i < n; i++) {
    int cval = (dp2[i-1] - (i-k-1 >= 0 ? dp2[i-k-1] : 0) + MOD)%MOD;
    dp[i] = (cval*fact[i-1])%MOD;
    dp2[i] = (cval*inv(i))%MOD;
    dp2[i] = (dp2[i] + dp2[i-1])%MOD;
  }

  V<Mint> a, b;
  for(int i = 0; n-2-i >= 0; i++) {
    int cur = dp[i]*fact[n-2-i];
    cur %= MOD;
    cur *= inv(fact[i]);
    cur %= MOD;
    a.push_back(cur);
    b.push_back(inv(fact[i]));
  }

  for(int i = 0; i < k; i++)
    a[i] = a[i+n-1-k];
  a = multiply(a, b);

  std::cout << dp[n-1] << " ";
  for(int i = 1; i < n; i++) {
    int ct = k-i+1;
    //k-i = dp[n-1-i]
    if(ct <= 0) {
      std::cout << 0 << " ";
    }
    else {
      // cval = sum j goes from 0 to ct-1, (n-1-i choose j) (i+j-1)! / (i-1)!
      // dp[n-1-i-j];
      int orig = fact[n-1-i]*i;
      orig %= MOD;
      /*
      int cval = 0;
      for(int j = 0; j < ct; j++) {
        int cur = inv(fact[j]);
        cur %= MOD;
        cur *= inv(fact[n-1-j-i]);
        cur %= MOD;
        cur *= (fact[i+j-1])%MOD;
        cur %= MOD;
        cur *= dp[n-1-i-j];
        cur %= MOD;
        cval = (cval + cur)%MOD;
      }
      */
      // dp[n-1+(ct-n)]/0! + dp[n-2]/1! + ... + 
      // dp[n-2]/0! + dp[n-3]/1!
      Mint cval = a[ct-1];

      /*
      cval *= fact[n-1-i];
      cval *= inv(fact[i-1]);
      */
      cval *= orig;
      //cval %= MOD;
      std::cout << cval << " ";
    }
  }

  std::cout << std::endl;

  return 0;
}