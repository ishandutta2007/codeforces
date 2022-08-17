// First 96 lines have been copied from https://github.com/yosupo06/library-checker-problems/blob/master/math/convolution_mod/sol/correct.cpp
#include <map>
#include <iostream>
#include <cstdio>
#include <set>
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

const int MAXN = 1000006;

Mint fact[MAXN];
Mint ifact[MAXN];

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  fact[0] = 1;
  for(int i = 1; i < MAXN; i++)
    fact[i] = ((Mint) i)*fact[i-1];

  ifact[MAXN-1] = fact[MAXN-1].inv();
  for(int i = MAXN-2; i >= 0; i--)
    ifact[i] = ifact[i+1]*((Mint) (i+1));

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::map<int, int> mp;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      mp[x]++;
    }

    int m = mp.size();

    if(m == 1) {
      std::cout << 1 << std::endl;
      continue;
    }

    Mint res = ((Mint) n)*((Mint) n);
    int k = 0;
    V<int> list;
    for(auto j : mp) {
      k = gcd(k, j.second);
      res -= ((Mint) j.second)*((Mint) j.second);
      list.push_back(j.second);
    }
    
    Mint ans = 0;
    Mint tot = 0;

    std::vector<int> count(n+1, 0);
    for(int i = 1; i <= n; i++)
      count[gcd(i, n)] += 1;

    //std::cout << vec[x][2] << std::endl;

    Mint div = ((Mint) n).inv();
    for(int i = 1; i <= n; i++) {
      if(!count[i])
        continue;

      if(k%(n/i))
        continue;

      int kt = n/i;
      Mint ctot = fact[i]*div*((Mint) count[i]);
      for(int j : list)
        ctot *= ifact[j/kt];

      Mint cans = ctot;
      cans *= ifact[i-1]*fact[i-2];
      cans *= ifact[kt]*fact[kt-1];
      cans *= res;

      tot += ctot;
      ans += cans;
    }

    ans *= tot.inv();

    std::cout << ans << std::endl;
  }

  return 0;
}