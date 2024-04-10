using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;

template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

using mint = ModInt< 1000000007 >;


mint fct[1000005];
mint ifct[1000005];


mint choose(int a, int b){
    if(a < 0 || b < 0 || a < b) return 0;
    return fct[a] * ifct[b] * ifct[a-b];
}

mint power(mint a, int b){
  if(b == 0) return 1;
  mint y = power(a, b/2);
  if(b%2 == 0) return y*y;
  return y*y*a;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int tests;
    cin >> tests;
    fct[0] = 1;
        for (int i = 1; i < 1000005; i++) {
            fct[i] = fct[i - 1] * i;
        }
        ifct[1000005 - 1] = (mint)1 / fct[1000005 - 1];
        for (int i = 1000005 - 2; i >= 0; i--) {
            ifct[i] = ifct[i + 1] * (i + 1);
        }
    for(int casenum = 1; casenum <= tests; casenum++){
        int n, m, k;
        cin >> n >> m >> k;

        
        if(m == 0 || k == 0){
            cout << 0 << endl;
            continue;
        }
        if(n == m){
            cout << (((mint) k)*n) << endl;
            continue;
        }
        mint tot = 0;
        mint p = m-n;
        mint z = 0;
        mint j = 1;
        for(int i=0; i<=m; i++){
            z = j * i;
            j *= 2;
            
            mint paths = choose(n-1-i, m-i);

            tot += paths * z;
        }
        mint ans = (tot / power(2, n));
        ans *= k;
        cout << ans << endl;
    }
    
}