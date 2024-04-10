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

ll ons[60];
ll  ons2[60][60];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll tests;
    cin >> tests;
    vector<mint> pows(120, 0);
    pows[0] = 1;
    for(ll i=1; i<120; i++){
        pows[i] = pows[i-1]*2;
    }
    for(ll casenum = 1; casenum <= tests; casenum++){
        ll n;
        cin >> n;
        vector<ll> v;
        for(ll i=0; i<n; i++){
            ll x;
            cin >> x;
            v.push_back(x);
        }
        
        for(int i=0; i<60; i++){
            ons[i] = 0;
        }

        for(auto x : v){
            for(ll i=0, ii=1; i<60; i++, ii<<=1ll){
                if(!(x & ii)) continue;
                ons[i]++;

            }
        }
        mint tot = 0;
        for(auto x : v){
                   mint cur = 0;
                mint cur2 = 0;
            for(ll i=0; i<60; i++){
         
                if(x & (1ll << i)) {
                    cur += (pows[i] * ons[i]);
                    cur2 += (pows[i] * n);
                }else{
                    cur2 += pows[i]* ons[i];
                }
               
            }
             tot += cur * cur2;
        }

        cout << tot << endl;
    }
    
}