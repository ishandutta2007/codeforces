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

using mint = ModInt< 998244353 >;
mint fct[5005];
mint ifct[5005];
mint choose(int a, int b){
    return fct[a] * ifct[b] * ifct[a-b];
}

mint walks(int l, int r){
    return choose(l+r, l);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    fct[0] = 1;
    for (int i = 1; i < 5005; i++) {
        fct[i] = fct[i - 1] * i;
    }
    ifct[5005 - 1] = (mint)1 / fct[5005 - 1];
    for (int i = 5005 - 2; i >= 0; i--) {
        ifct[i] = ifct[i + 1] * (i + 1);
    }
    int n, m;
    cin >> n >> m;
    mint tot = 0;
    for(int i=1; i<=n-1; i++){
        for(int j=1; j<=m-1; j++){
            tot += walks(i-1, j) * walks(m-j-1, i)* walks(j-1, n-i) * walks(n-i-1, m-j) ;
            tot += walks(i, j-1) * walks(m-j, i-1)* walks(j, n-i-1) * walks(n-i, m-j-1) ;
        }
    }
    
    for(int i=1; i<=n-1; i++){
        mint s1 = 0;
        mint s2 = 0;
        for(int j=1; j<=m-1; j++){
            tot += walks(i-1, j) * walks(m-j-1, i)* s1 ;
            tot += walks(n-i-1, j) * walks(m-j-1, n-i)* s2;
            s1 += walks(j-1, n-i) * walks(n-i-1, m-j);
            s2 +=  walks(j-1, i) * walks(i-1, m-j);
        }
    }
    swap(n, m);
    for(int i=1; i<=n-1; i++){
        mint s1 = 0;
        mint s2 = 0;
        for(int j=1; j<=m-1; j++){
            tot += walks(i-1, j) * walks(m-j-1, i)* s1 ;
            tot += walks(n-i-1, j) * walks(m-j-1, n-i)* s2;
            s1 += walks(j-1, n-i) * walks(n-i-1, m-j);
            s2 +=  walks(j-1, i) * walks(i-1, m-j);
        }
    }
    //tot += walks(i, j-1) * walks(j, n-i-1) * walks(n-i, m-j-1) * walks(m-j, n-i-1);


    cout << tot << endl;
    
}