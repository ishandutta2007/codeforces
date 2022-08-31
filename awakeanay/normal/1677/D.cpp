// First 96 lines have been copied from https://github.com/yosupo06/library-checker-problems/blob/master/math/convolution_mod/sol/correct.cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <set>
 
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
const int MAXN = 1000006;

int fact[MAXN];
int ifact[MAXN];

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

int choose(int n, int k) {
  if(n < k || n < 0 || k < 0)
    return 0;
  int ans = fact[n]*ifact[k];
  ans %= MOD;
  ans *= ifact[n-k];
  ans %= MOD;
  return ans;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  fact[0] = 1;
  for(int i = 1; i < MAXN; i++)
    fact[i] = (i*fact[i-1])%MOD;

  ifact[MAXN-1] = inv(fact[MAXN-1]);
  for(int i = MAXN-2; i >= 0; i--)
    ifact[i] = (ifact[i+1]*(i+1))%MOD;

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    int v[n];
    for(int i = 0; i < n; i++) {
      std::cin >> v[i];
    }

    bool poss = true;
    for(int i = 0; i < k; i++)
      poss &= v[n-1-i] == 0 || v[n-1-i] == -1;

    if(!poss) {
      std::cout << 0 << std::endl;
      continue;
    }

    int m = n-k;
    V<Mint> vec[m+1];
    vec[0].push_back(1);
    std::set<std::pair<int, int> > fast;
    fast.insert({vec[0].size(), 0});

    Mint one = 1;
    Mint zero = 0;

    for(int i = 0; i < m; i++) {
      if(v[i] == 0) {
        vec[i+1].push_back(0);
        vec[i+1].push_back(1);
      }
      else if(v[i] == -1) {
        vec[i+1].push_back(i);
        vec[i+1].push_back(1);
      }
      else {
        vec[i+1].push_back(1);
      }
      fast.insert({vec[i+1].size(), i+1});
    }

    while(fast.size() > 1) {
      int u = (*fast.begin()).second;
      fast.erase(fast.begin());
      int v = (*fast.begin()).second;
      fast.erase(fast.begin());
      vec[v] = multiply(vec[v], vec[u]);
      fast.insert({vec[v].size(), v});
    }

    int x = (*fast.begin()).second;

    int ch = n-k;
    Mint ans = 0;
    for(int i = 0; i <= ch; i++) {
      Mint cur = (i < vec[x].size() ? vec[x][i] : 0);
      cur *= expo(k+1, i);
      ans += cur;
    }

    ans *= fact[k];
    std::cout << ans << std::endl;
  }

  return 0;
}