#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

template <int MOD>
struct Mint {
  int n;
  constexpr Mint(int n = 0): n(n) {}
  constexpr Mint operator -() const {
    return n ? MOD - n: 0;
  }
  constexpr Mint operator ++() {
    n++;
    if(n == MOD) n = 0;
    return *this;
  }
  constexpr Mint operator --() {
    n--;
    if(n < 0) n = MOD - 1;
    return *this;
  }
  constexpr Mint &operator -= (const Mint &rhs){
    if(n >= rhs.n) n -= rhs.n;
    else n = MOD - (rhs.n - n);
    return *this;
  }
  constexpr Mint &operator += (const Mint &rhs){
    n += rhs.n;
    if(n >= MOD) n -= MOD;
    return *this;
  }
  constexpr Mint &operator *= (const Mint &rhs){
    n = (long long) n * rhs.n % MOD;
    return *this;
  }
  constexpr Mint &operator /= (const Mint &rhs){
    n = (long long) n * rhs.inv().n % MOD;
    return *this;
  }
  constexpr bool operator == (const Mint &rhs) const {
    return n == rhs.n;
  }
  constexpr bool operator != (const Mint &rhs) const {
    return n != rhs.n;
  }
  friend constexpr Mint operator - (const Mint &lhs, const Mint &rhs){
    Mint r = lhs;
    r -= rhs;
    return r;
  }
  friend constexpr Mint operator + (const Mint &lhs, const Mint &rhs){
    Mint r = lhs;
    r += rhs;
    return r;
  }
  friend constexpr Mint operator * (const Mint &lhs, const Mint &rhs){
    Mint r = lhs;
    r *= rhs;
    return r;
  }
  friend constexpr Mint operator / (const Mint &lhs, const Mint &rhs){
    Mint r = lhs;
    r /= rhs;
    return r;
  }
  constexpr Mint pow(int n) const {
    Mint r = 1;
    Mint x = *this;
    for(; n; n >>= 1){
      if(n & 1) r *= x;
      x *= x;
    }
    return r;
  }
  constexpr Mint inv() const {
    return pow(MOD - 2);
  }
};

template <int MOD, int N>
struct Minv {
  Mint<MOD> inv[N+1];
  constexpr Minv(): inv() {
    inv[1] = 1;
    for(int i = 2; i <= N; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i];
  }
  constexpr Mint<MOD> operator[](int i) const {
    return inv[i];
  }
};

template <int MOD, int K>
struct FFT {
  Mint<MOD> w[1<<(K-1)];
  Mint<MOD> y[1<<(K-1)];
//  Mint<MOD> v[(1<<(K-2))+1];
  Mint<MOD> v[1<<(K-1)];

  static constexpr Mint<MOD> root = []() constexpr {
    bool sieve[1<<16] = {};
    int factors[1<<16] = {};
    int fs = 0;
    int t = MOD - 1;
    int i = 0;
    for(; t % 2 == 0; t /= 2) i++;
    factors[fs++] = (MOD - 1) / 2;
    if(i < K) return Mint<MOD>(0);
    for(int i = 3; (long long) i * i < t; i += 2){
      if(!sieve[i]){
        for(int j = 3 * i; (long long) j * j < t; j += 2 * i) sieve[j] = true;
        if(t % i == 0){
          factors[fs++] = (MOD - 1) / i;
          do { t /= i; } while(t % i == 0);
        }
      }
    }
    if(t != 1) factors[fs++] = (MOD - 1) / t;
    for(int i = 2; i < MOD; i++){
      int j = 0;
      for(j = 0; j < fs; j++){
        if(Mint<MOD>(i).pow(factors[j]) == 1) break;
      }
      if(j == fs) return Mint<MOD>(i).pow(MOD >> K);
    }
    return Mint<MOD>(0);
  }();


  FFT(): w(), y(), v() {
    constexpr int m = 1 << K;
    static_assert(root != 0);
    w[m / 4] = root;
    y[m / 4] = root.inv();
    for(int j = m / 4; j > 1; j >>= 1){
      w[j / 2] = w[j] * w[j];
      y[j / 2] = y[j] * y[j];
    }
    w[0] = y[0] = 1;
    for(int j = 2; j < m / 2; j <<= 1){
      for(int i = 1; i < j; i++){
        w[j + i] = w[j] * w[i];
        y[j + i] = y[j] * y[i];
      }
    }
    v[0] = 1;
    for(long unsigned int i = 1; i < sizeof(v)/sizeof(v[0]); i++) v[i] = root * v[i - 1];
  }

  template <typename C>
  void fft(C A, int k = K) const {
    int u = 1;
    int v = 1 << (k-1);
    for(int i=k;i>0;i--){
      for(int jh=0;jh<u;jh++){
        Mint<MOD> wj = w[jh];
        for(int j = jh << i, je = j+v;j<je; j++){
          Mint<MOD> Ajv = wj * A[j+v];
          A[j+v]  = A[j] - Ajv;
          A[j]    = A[j] + Ajv;
        }
      }
      u <<= 1;
      v >>= 1;
    }
  }

  template <typename C>
  void ifft(C A, int k = K) const {
    int u = 1 << (k-1);
    int v = 1;
    for(int i=1;i<=k;i++){
      for(int jh=0;jh<u;jh++){
        Mint<MOD> wj = y[jh];
        for(int j = jh << i, je = j+v;j<je; j++){
          Mint<MOD> Ajv = A[j] - A[j+v];
          A[j] = A[j] + A[j+v];
          A[j+v] = wj * Ajv;
        }
      }
      u >>= 1;
      v <<= 1;
    }
  }
};



template <int MOD, int K = __builtin_ctz(MOD - 1)>
class Poly {
  public:
  using vec = std::valarray<Mint<MOD> >;
  vec c;
  inline static FFT<MOD, K + 1> fft;
  inline static Minv<MOD, (1 << K) - 1> minv;
//  static constexpr auto minv = Minv<MOD, (1 << K) - 1>();
//  static constexpr auto fft = FFT<MOD, K + 1>();

  Poly(int n = -1): c(n + 1) {
  }

  inline int deg() const {
    return c.size() - 1;
  }

  inline const Mint<MOD> &at(std::size_t n) const {
    static Mint<MOD> zero = Mint<MOD>();
    if(n < c.size()) return c[n];
    else return zero;
  }

  void operator +=(const Poly &rhs){
    if(rhs.deg() > deg()){
      vec d(rhs.c);
      for(int i = 0; i <= deg(); i++) d[i] += c[i];
      c.swap(d);
    }
    else if(rhs.deg() < deg()) {
      for(int i = 0; i <= rhs.deg(); i++) c[i] += rhs.c[i];
    }
    else c += rhs.c;
  }
  void operator -=(const Poly &rhs){
    if(rhs.deg() > deg()){
      vec d(-rhs.c);
      for(int i = 0; i <= deg(); i++) d[i] += c[i];
      c.swap(d);
    }
    else if(rhs.deg() < deg()) {
      for(int i = 0; i <= rhs.deg(); i++) c[i] -= rhs.c[i];
    }
    else c -= rhs.c;
  }

  void operator *=(const Poly &rhs){
    if(deg() < 0 || rhs.deg() < 0){
      c.resize(0);
      return;
    }
    const int rdeg = deg() + rhs.deg();
    const int k = 32-__builtin_clz(rdeg);
    assert(k <= K + 1);
    vec d(1 << k);
    vec e(1 << k);
    for(int i = 0; i <= deg(); i++) d[i] = c[i];
    for(int i = 0; i <= rhs.deg(); i++) e[i] = rhs.c[i];
    fft.fft(std::begin(d), k);
    fft.fft(std::begin(e), k);
    d *= e;
    fft.ifft(std::begin(d), k);
    c.resize(rdeg + 1);
    const Mint<MOD> im = Mint<MOD>((MOD+1)/2).pow(k);
    for(int i = 0; i <= rdeg; i++) c[i] = d[i] * im;
  }

  Poly operator +(const Poly &rhs) const {
    Poly r = *this;
    r += rhs;
    return r;
  }

  Poly operator -(const Poly &rhs) const {
    Poly r = *this;
    r -= rhs;
    return r;
  }

  Poly operator *(const Poly &rhs) const {
    Poly r = *this;
    r *= rhs;
    return r;
  }

  Poly operator %(const Poly &rhs) const {
    Poly r = *this;
    r %= rhs;
    return r;
  }


// Newton (1 + 2/3) M(n) = 5/3 M(n)
  Poly inv(int n = -1) const {
    assert(c[0] != 0);
    if(n == -1) n = deg();
    if(n == -1) return *this;
    const int k = 32 - __builtin_clz(n);
    assert(k <= K);
    vec d(1 << k);
    vec ee(1 << k);
    Poly r(n);
    r.c[0] = c[0].inv();
    int y = (MOD+1)/2;
    if(y&1) y += MOD;
    y /= 2;
    Mint<MOD> im = MOD - y;
    for(int i = 0; i < k; i++){
      for(int j = 0; j < (1 << (i + 1)); j++) d[j] = at(j);
      fft.fft(std::begin(d), i + 1);
      for(int j = 0; j < (1 << i); j++) ee[j] = r.c[j];
      fft.fft(std::begin(ee), i + 1);
      for(int j = 0; j < (1 << (i + 1)); j++) d[j] *= ee[j];
      fft.ifft(std::begin(d), i + 1);
      for(int j = 0; j < (1 << i); j++) d[j] = d[j + (1 << i)], d[j + (1 << i)] = 0;
      fft.fft(std::begin(d), i + 1);
      for(int j = 0; j < (1 << (i + 1)); j++) d[j] *= ee[j];
      fft.ifft(std::begin(d), i + 1);
      for(int j = 0; (1 << i) + j < std::min(1 << (i + 1), n + 1); j++) r.c[j + (1 << i)] = d[j] * im;

      if(im.n&1) im.n += MOD;
      im.n /= 2;
      if(im.n&1) im.n += MOD;
      im.n /= 2;
    }
    return r;
  }


// Newton: 2 M(n)
  Poly isqrt(int n = -1) const {
    assert(c[0] == 1);
    if(n == -1) n = deg();
    if(n == -1) return *this;
    const int k = 32 - __builtin_clz(n);
    assert(k <= K);
    vec d(1 << (k + 1));
    vec ee(1 << (k + 1));
    Poly r(n);
    r.c[0] = 1;
    int y = (MOD+1)/2;
    if(y&1) y += MOD;
    y /= 2;
    if(y&1) y += MOD;
    y /= 2;
    Mint<MOD> im = MOD - y;
    for(int i = 0; i < k; i++){
      for(int j = 0; j < (1 << (i + 1)); j++) d[j] = at(j);
      fft.fft(std::begin(d), i + 2);
      for(int j = 0; j < (1 << i); j++) ee[j] = r.c[j];
      for(int j = (1 << i); j < (1 << (i + 1)); j++) ee[j] = 0;
      fft.fft(std::begin(ee), i + 2);
      for(int j = 0; j < (1 << (i + 2)); j++) d[j] *= ee[j] * ee[j] * ee[j];
      fft.ifft(std::begin(d), i + 2);
      for(int j = 1 << i; j < std::min(1 << (i + 1), n + 1); j++) r.c[j] = d[j] * im;
      if(im.n&1) im.n += MOD;
      im.n /= 2;
    }
    return r;
  }


// Newton: (1 + 1/2 + (1/4)*(2/3) + (1/2)*(2/3)) M(n) = 2 M(n)
  Poly sqrt(int n = -1) const {
    if(n == -1) n = deg();
    if(n == -1) return *this;
    assert(c[0] == 1);
    if(n == 0){
      Poly r(0);
      r.c[0] = 1;
      return r;
    }
    const int k = 32 - __builtin_clz(n);
    assert(k <= K);
    Poly g((1 << (k - 1)) - 1);
    vec d(1 << k);
    vec e(1 << (k-1));
    vec f(1 << k);
    vec gg(1 << k);
    for(int i = 0; i < std::min(1 << (k - 1), deg() + 1); i++) g.c[i] = d[i] = c[i];
    g = g.isqrt();
    for(int i = 0; i < (1 << (k - 1)); i++) gg[i] = g.c[i];
    fft.fft(std::begin(d), k);
    fft.fft(std::begin(gg), k);
    for(int i = 0; i < (1 << k); i++) f[i] = gg[i];
    Mint<MOD> im0 = Mint<MOD>((1+MOD)/2).pow(k + 1);
    Mint<MOD> im1 = im0 + im0;
    Mint<MOD> im2 = im1 + im1;
    for(int i = 0; i < (1 << k); i++) gg[i] *= d[i] * im1;
    fft.ifft(std::begin(gg), k);
    for(int i = 0; i < (1 << (k - 1)); i++) e[i] = gg[i];
    fft.fft(std::begin(e), k - 1);
    for(int i = 0; i < (1 << (k - 1)); i++) e[i] *= e[i] * im2;
    fft.ifft(std::begin(e), k - 1);
    for(int i = 0; i < (1 << (k - 1)); i++) d[i] = at(i + (1 << (k - 1))) + at(i) - e[i];
    for(int i = (1 << (k - 1)); i < (1 << k); i++) d[i] = 0;
    fft.fft(std::begin(d), k);
    for(int i = 0; i < (1 << k); i++) d[i] *= f[i] * im0;
    fft.ifft(std::begin(d), k);
    for(int i = 0; i < (1 << (k - 1)); i++) gg[i + (1 << (k - 1))] = d[i];
    Poly r(n);
    for(int i = 0; i <= n; i++) r.c[i] = gg[i];
    return r;
  }


// Newton (5/6 + (1/2)*(2/3) + 1 + 2/3) M(n) = 17/6 M(n)
  Poly exp(int n = -1) const {
    if(n == -1) n = deg();
    if(n == -1) return *this;
    assert(c[0] == 0);
    if(n == 0){
      Poly r(0);
      r.c[0] = 1;
      return r;
    }
    const int k = 32 - __builtin_clz(n);
    assert(k <= K);
    vec f(1 << k);
    vec g(1 << (k-1));
    vec ff(1 << k);
    vec gg(1 << k);
    vec G(1 << k);
    f[0] = 1;
    f[1] = c[1];
    g[0] = 1;
    G[0] = G[1] = 1;
    int y = (MOD+1)/2;
    if(y&1) y += MOD;
    y /= 2;
    Mint<MOD> im = y;
    for(int i = 1; i < k; i++){
      for(int j = 0; j < (1 << i); j++) ff[j] = f[j] * im;
      fft.fft(std::begin(ff), i + 1);

/*
      for(int j = 0; j < (1 << (i - 1)); j++) gg[j] = g[j];
      for(int j = (1 << (i - 1)); j < (1 << i); j++) gg[j] = 0;
      fft.fft(gg, i + 1);
*/

      for(int j = 0; j < (1 << i); j++) gg[j] = G[j];
      for(int j = 0; j < (1 << (i - 1)); j++) gg[j + (1 << i)] = fft.v[j << (K - i)] * g[j];
      fft.fft(std::begin(gg) + (1 << i), i);

/*
      for(int j = 0; j < (1 << (i - 1)); j++) gg[j] = fft.v[j << (K - i)] * g[j], gg[j + (1 << (i - 1))] = 0;
      fft.fft(gg, i);
      for(int j = 0; j < (1 << i); j++) gg[j + (1 << i)] = gg[j], gg[j] = G[j];
*/


      for(int j = 0; j < (1 << (i + 1)); j++) gg[j] *= gg[j] * ff[j];
      fft.ifft(std::begin(gg), i + 1);
      for(int j = 1 << (i - 1); j < (1 << i); j++) g[j] = -gg[j];
      for(int j = 0; j < (1 << i) - 1; j++) gg[j] = at(j + 1) * (2 * j + 2);
      gg[(1 << i) - 1] = 0;
      fft.fft(std::begin(gg), i);
      for(int j = 0; j < (1 << i); j++) gg[j] *= ff[j];
      fft.ifft(std::begin(gg), i);

      Mint<MOD> tmp = -gg[(1 << i) - 1];
      for(int j = (1 << i) - 1; j; j--) gg[j] = f[j] * j - gg[j - 1];
      gg[0] = tmp;
      for(int j = (1 << i); j < (1 << (i + 1)); j++) gg[j] = 0;
      fft.fft(std::begin(gg), i + 1);
      for(int j = 0; j < (1 << i); j++) G[j] = g[j];
      fft.fft(std::begin(G), i + 1);
      for(int j = 0; j < (1 << (i + 1)); j++) gg[j] *= G[j];
      fft.ifft(std::begin(gg), i + 1);

      for(int j = 0; j < (1 << i); j++) gg[j] = at(j + (1 << i)) - gg[j] * minv[(1 << i) + j] * im;
      for(int j = (1 << i); j < (1 << (i + 1)); j++) gg[j] = 0;
      fft.fft(std::begin(gg), i + 1);
      for(int j = 0; j < (1 << (i + 1)); j++) ff[j] *= gg[j];
      fft.ifft(std::begin(ff), i + 1);
      for(int j = 0; j < (1 << i); j++) f[j + (1 << i)] = ff[j];
      if(im.n&1) im.n += MOD;
      im.n /= 2;
    }
    Poly r(n);
    for(int i = 0; i <= n; i++) r.c[i] = f[i];
    return r;
  }


// 8/3 M(n)
  Poly log(int n = -1) const {
    if(n == -1) n = deg();
    if(n == -1) return *this;
    assert(c[0] == 1);
    const int k = 32 - __builtin_clz(n);
    assert(k <= K);
    Poly g((1 << k) - 1);
    vec d(1 << (k + 1));
    for(int i = 0; i < std::min(1 << k, deg() + 1); i++) g.c[i] = c[i];
    for(int i = 0; i < std::min(1 << k, deg()); i++) d[i] = (i + 1) * c[i + 1];
    g = g.inv();
    vec gg(1 << (k + 1));
    for(int i = 0; i < (1 << k); i++) gg[i] = g.c[i];
    fft.fft(std::begin(gg), k + 1);
    fft.fft(std::begin(d), k + 1);
    Mint<MOD> im = Mint<MOD>((1+MOD)/2).pow(k + 1);
//    for(int i = 0; i < (1 << (k + 1)); i++) gg[i] *= d[i];
    gg *= d;
    fft.ifft(std::begin(gg), k + 1);
    for(int i = (1 << k) - 1; i; i--) gg[i] = gg[i-1] * minv[i] * im;
    gg[0] = 0;
    Poly r(n);
    for(int i = 0; i <= n; i++) r.c[i] = gg[i];
    return r;
  }


// 8/3 M(n)
// regarded as a polynomial rather than a formal power series
  Poly quotient(const Poly &Q) const {
    assert(Q.deg() >= 0);
    if(deg() < 0) return *this;

    int dP;
    for(dP = deg(); dP && c[dP] == 0; dP--) ;
    if(c[dP] == 0) return Poly();

    int dQ;
    for(dQ = Q.deg(); dQ && Q.c[dQ] == 0; dQ--) ;
    assert(Q.c[dQ] != 0);
    if(dQ > dP) return Poly();
    Poly RQ(std::min(dQ, dP - dQ));
    for(int j = 0; j <= std::min(dQ, dP - dQ); j++) RQ.c[j] = Q.c[dQ - j];

    const int k = 32 - __builtin_clz(2*(dP - dQ));
    assert(k <= K + 1);
    vec rp(1 << k);
    for(int j = 0; j <= dP - dQ; j++) rp[j] = c[dP - j];


    RQ = RQ.inv(dP - dQ);
//    RQ = RQ.inv();
    vec rq(1 << k);
    for(int i = 0; i <= dP - dQ; i++) rq[i] = RQ.c[i];
    fft.fft(std::begin(rp), k);
    fft.fft(std::begin(rq), k);
//    for(int j = 0; j < (1 << k); j++) rq[j] *= rp[j];
    rq *= rp;
    fft.ifft(std::begin(rq), k);
    Mint<MOD> im = Mint<MOD>((1+MOD)/2).pow(k);
    Poly r(dP - dQ);
    for(int j = 0; j <= dP - dQ; j++) r.c[j] = rq[dP - dQ - j] * im;
    return r;
  }


// (8/3 + 1/2) M(n) = 19/6 M(n)
// regarded as a polynomial rather than a formal power series
  Poly &operator %= (const Poly &Q) {
    if(Q.deg() > deg()) return *this;
    if(Q.deg() < 32){
      int dQ = Q.deg();
      while(dQ && Q.c[dQ] == 0) dQ--;
      assert(Q.c[dQ] != 0);
      for(int i = deg(); i >= dQ; i--){
        if(c[i] == 0) continue;
        Mint<MOD> x = c[i] / Q.c[dQ];
        c[i] = 0;
        for(int j = 1; j <= dQ; j++){
          c[i - j] -= x * Q.c[dQ - j];
        }
      }
      int dP;
      for(dP = dQ - 1; dP >= 0 && c[dP] == 0; dP--) ;
      vec r(dP + 1);
      for(int i = 0; i <= dP; i++) r[i] = c[i];
      c.swap(r);
      return *this;
    }
    Poly P = quotient(Q);
    const int k = 32 - __builtin_clz(deg());
    vec v(1 << k);
    vec w(1 << k);
    for(int i = 0; i <= P.deg(); i++) w[i] = P.c[i];
    fft.fft(std::begin(w), k);
    for(int i = 0; i <= Q.deg(); i++) v[i] = Q.c[i];
    fft.fft(std::begin(v), k);
//    for(int i = 0; i < (1 << k); i++) v[i] *= w[i];
    v *= w;
    fft.ifft(std::begin(v), k);
    Mint<MOD> im = Mint<MOD>((1+MOD)/2).pow(k);
    int dR = -1;
    for(int i = 0; i < Q.deg(); i++){
      v[i] = c[i] - v[i] * im;
      if(v[i] != 0) dR = i;
    }
    c.resize(dR + 1);
    for(int i = 0; i <= dR; i++) c[i] = v[i];
    return *this;
  }

  Mint<MOD> eval(Mint<MOD> x) const {
    Mint<MOD> r = 0;
    for(int i = deg(); i >= 0; i--){
      r *= x;
      r += c[i];
    }
    return r;
  }

/*
  vec eval(const vec &P) const {
    const int m = P.size();
    if(m <= (1 << _ls)){
      vec v(m);
      for(int i = 0; i < m; i++){
        v[i] = eval(P[i]);
      }
      return v;
    }
    const int k = 32 - __builtin_clz(m - 1);

    std::vector<Poly> M = gen_tree(P);
    M[1] = *this % M[1];

    for(int i = 2; i < (1 << (k - _ls + 1)); i++) M[i] = M[i / 2] % M[i];

    vec r(m);
    for(int i = 0; i < (1 << (k - _ls)); i++){
      for(int j = i << _ls; j < std::min((i + 1) << _ls, m); j++) r[j] = M[(1 << (k - _ls)) + i].eval(P[j]);
    }

    return r;
  }
*/

  vec eval2(const vec &P) const {
    const int m = P.size();
    if(m <= (1 << _ls)){
      vec v(m);
      for(int i = 0; i < m; i++){
        v[i] = eval(P[i]);
      }
      return v;
    }
    const int k = 32 - __builtin_clz(m - 1);
    const std::vector<Poly> T = gen_tree(P);
//    const std::vector<vec> FT = gen_tree(P);
    Poly A(1 << k);
//    for(int i = 0; i <= (1 << k); i++) A.c[i] = FT[1].c[(1 << k) - i];
    for(int i = 0; i <= (1 << k); i++) A.c[i] = T[1].c[(1 << k) - i];
//    Poly B = A.inv((1 << k) - 1);
    Poly B = A.inv(deg());
    const int v = (1 << k) - 1;
    A = middle_product(v, B, *this);
    B.c.resize(v + 1);
    for(int i = 0; i <= v; i++) B.c[i] = A.c[v - i];
//    return tuptree(B, FT);
    return tuptree(B, T);
  }

  Poly interpolation(const vec &a, const vec &b) const {
    int m = a.size();
    assert(b.size() == m);

    return Poly();
  }

  private:
  static constexpr int _ls = 0;
//  static std::pair<std::vector<Poly>, std::vector<vec> > gen_tree(const vec &P){
  static std::vector<Poly> gen_tree(const vec &P){
//  static std::vector<vec> gen_tree(const vec &P){
    const int m = P.size();
    assert(m > (1 << _ls));

    const int k = 32 - __builtin_clz(m - 1);
    std::vector<Poly> T(1 << (k + 1));
    std::vector<vec> FT(1 << (k + 1));
    vec w(1 << _ls);
    w[1] = 1;
    fft.fft(std::begin(w), _ls);
    if(_ls == 0) w[0] = 1;

    for(int i = 0; i < (1 << (k - _ls)); i++){
      const int t = (1 << (k - _ls)) + i;
      T[t].c.resize((1 << _ls) + 1);
      T[t].c[1 << _ls] = 1;
      for(int j = 0; j < (1 << _ls); j++){
        T[t].c[j] = 1;
        for(int l = 0; l < (1 << _ls); l++){
          T[t].c[j] *= w[j] - (((i << _ls) + l < m) ? P[(i << _ls) + l] : 0);
        }
        T[t].c[j] -= 1;
      }
    }

/*
for(int i = 0; i < (1 << k); i++){
   T[(1 << k) + i].c.resize(2);
   T[(1 << k) + i].c[1] = 1;
   T[(1 << k) + i].c[0] = i < m ? -P[i] : 0;
}
*/


    Mint<MOD> im = Mint<MOD>((1+MOD)/2).pow(_ls);
    for(int i = _ls + 1; i <= k; i++){
//      Poly tmp((1 << i)-1);
      for(int j = 0; j < (1 << (k - i)); j++){
        const int t = (1 << (k - i)) + j;
        T[t].c.resize((1 << i) + 1);
        T[t].c[1 << i] = 1;
/*
        for(int l = 0; l < (1 << (i - 1)); l++) T[t].c[l] = T[2 * t].c[l];
        fft.ifft(std::begin(T[2 * t].c), i - 1);
        for(int l = 0; l < (1 << (i - 1)); l++) T[2 * t].c[l] *= im;
*/
        FT[2 * t].resize(1 << i);
        for(int l = 0; l < (1 << (i - 1)); l++) FT[2 * t][l] = T[2 * t].c[l] + 1;
        fft.ifft(std::begin(T[2 * t].c), i - 1);
        for(int l = 0; l < (1 << (i - 1)); l++) T[2 * t].c[l] *= im;

/*
for(int l=0; l<i; l++) io.put_char(' ');
io.put_int(2*t, ' ');
T[2 * t].print();
*/

/*
        for(int l = 0; l < (1 << (i - 1)); l++) T[t].c[(1 << (i - 1)) + l] = T[2 * t].c[l] * fft.v[l << (K - i + 1)];
        fft.fft(std::begin(T[t].c) + (1 << (i - 1)), i - 1);
*/
        for(int l = 0; l < (1 << (i - 1)); l++) FT[2 * t][(1 << (i - 1)) + l] = T[2 * t].c[l] * fft.v[l << (K - i + 1)];
        --FT[2 * t][1 << (i - 1)];
        fft.fft(std::begin(FT[2 * t]) + (1 << (i - 1)), i - 1);
//        for(int l = 0; l < (1 << (i - 1)); l++) --FT[2 * t][(1 << (i - 1)) + l];

/*
        for(int l = 0; l < (1 << (i - 1)); l++) tmp.c[l] = T[2 * t + 1].c[l];
        fft.ifft(std::begin(T[2 * t + 1].c), i - 1);
        for(int l = 0; l < (1 << (i - 1)); l++) T[2 * t + 1].c[l] *= im;
*/
        FT[2 * t + 1].resize(1 << i);
        for(int l = 0; l < (1 << (i - 1)); l++) FT[2 * t + 1][l] = T[2 * t + 1].c[l] + 1;
        fft.ifft(std::begin(T[2 * t + 1].c), i - 1);
        for(int l = 0; l < (1 << (i - 1)); l++) T[2 * t + 1].c[l] *= im;

/*
for(int l=0; l<i; l++) io.put_char(' ');
io.put_int(2*t+1, ' ');
T[2 * t + 1].print();
*/

/*
        for(int l = 0; l < (1 << (i - 1)); l++) tmp.c[(1 << (i - 1)) + l] = T[2 * t + 1].c[l] * fft.v[l << (K - i + 1)];
        fft.fft(std::begin(tmp.c) + (1 << (i - 1)), i - 1);
*/
        for(int l = 0; l < (1 << (i - 1)); l++) FT[2 * t + 1][(1 << (i - 1)) + l] = T[2 * t + 1].c[l] * fft.v[l << (K - i + 1)];
        --FT[2 * t + 1][1 << (i - 1)];
        fft.fft(std::begin(FT[2 * t + 1]) + (1 << (i - 1)), i - 1);
//        for(int l = 0; l < (1 << (i - 1)); l++) --FT[2 * t + 1][(1 << (i - 1)) + l];

        for(int l = 0; l < (1 << i); l++){
/*
          T[t].c[l] = T[t].c[l] * tmp.c[l] + T[t].c[l] + tmp.c[l];
          T[t].c[(1 << (i - 1)) + l] = T[t].c[(1 << (i - 1)) + l] * tmp.c[(1 << (i - 1)) + l] - T[t].c[(1 << (i - 1)) + l] - tmp.c[(1 << (i - 1)) + l];
*/
/*
          T[t].c[l] = FT[2 * t][l] * FT[2 * t + 1][l] + FT[2 * t][l] + FT[2 * t + 1][l];
          T[t].c[(1 << (i - 1)) + l] = FT[2 * t][(1 << (i - 1)) + l] * FT[2 * t + 1][(1 << (i - 1)) + l] - FT[2 * t][(1 << (i - 1)) + l] - FT[2 * t + 1][(1 << (i - 1)) + l];
*/
          T[t].c[l] = FT[2 * t][l] * FT[2 * t + 1][l] - 1;
        }
      }
      if(im.n&1) im.n += MOD;
      im.n /= 2;
    }

    fft.ifft(std::begin(T[1].c), k);
    FT[1].resize(1 << k);
    for(int l = 0; l < (1 << k); l++) FT[1][l] = T[1].c[l] *= im;
//    T[1].c[1 << k] = 1 << k;

//    return FT;
    return T;
//    return std::pair(T, FT);
  }


  static Poly middle_product(int n, const Poly &lhs, const Poly &rhs){
    int dl = lhs.deg();
    while(lhs.c[dl] == 0) dl--;
    assert(rhs.deg() <= n + dl);
    int k = 32 - __builtin_clz(dl + n);
    Poly P((1 << k) - 1);
    Poly Q((1 << k) - 1);
    for(int i = 0; i <= dl; i++) P.c[i] = lhs.c[dl - i];
    for(int i = 0; i <= rhs.deg(); i++) Q.c[i] = rhs.c[i];
    fft.fft(std::begin(P.c), k);
    fft.fft(std::begin(Q.c), k);
//
    P.c *= Q.c;
    fft.ifft(std::begin(P.c), k);
    Mint<MOD> im = Mint<MOD>((1+MOD)/2).pow(k);
    Q.c.resize(n + 1);
    for(int i = 0; i <= n; i++) Q.c[i] = P.c[i + dl] * im;
    return Q;
  }

  static Poly uptree(const vec &C, const std::vector<Poly> &T){
    int m = C.size();
    int k = 32 - __builtin_clz(m - 1);
    Poly B[1 << k];
    for(int i = 0; i < m; i++){
      B.c.resize(1);
      B[i].c[0] = C[i];
    }
    for(int i = 1; i <= k; i++){
      for(int j = 0; j < (1 << (k - i)); j++){
        B[j] = T[(1 << (k - i + 1)) + 2 * j + 1] * B[2 * j] + T[(1 << (k - i + 1)) + 2 * j] * B[2 * j + 1];
      }
    }
    return B[0];
  }

  static vec tuptree(const Poly &B, const std::vector<Poly> &T){
//  static vec tuptree(const Poly &B, const std::vector<vec> &FT){
    int m = B.deg() + 1;
    int k = 32 - __builtin_clz(m - 1);
    Poly C[1 << k];
    C[0] = B;
    for(int i = k; i > 0; i--){
      for(int j = (1 << (k - i)) - 1; j >= 0; j--){
        int n = (1 << (i - 1)) - 1;
        C[2 * j + 1] = middle_product(n, T[(1 << (k - i + 1)) + 2 * j], C[j]);
        C[2 * j] = middle_product(n, T[(1 << (k - i + 1)) + 2 * j + 1], C[j]);
      }
    }
    vec r(m);
    for(int i = 0; i < m; i++) r[i] = C[i].c[0];
    return r;
  }

};

/*
template <int MOD, int K>
FFT<MOD, K + 1> Poly<MOD, K>::fft;

template <int MOD, int K>
Minv<MOD, (1 << K) - 1> Poly<MOD, K>::minv;
*/

constexpr int mod = 998244353;
constexpr int K = 18;

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  int n,k;
  cin>>n>>k;
  vector<int> hs(n);
  for(int i=0;i<n;i++) cin>>hs[i];

  int cnt=0;
  for(int i=0;i<n;i++)
    if(hs[i]==hs[(i+1)%n]) cnt++;

  if(cnt==n){
    cout<<0<<endl;
    return 0;
  }

  Poly<mod, K> A(2e5+1000);
  A.c[0]=1;
  A.c[1]=(k-2)%mod;
  A.c[2]=1;

  auto B=A.log();
  for(int i=0;i<(int)B.c.size();i++)
    B.c[i]*=Mint<mod>(n-cnt);

  auto C=B.exp();

  Mint<mod> ans=Mint<mod>(k%mod).pow(n-cnt);
  for(int i=0;i<=n-cnt;i++) ans-=C.c[i];

  ans*=Mint<mod>(k%mod).pow(cnt);
  cout<<ans.n<<endl;
  return 0;
}