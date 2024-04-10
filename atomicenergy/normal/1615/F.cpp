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

mint ans[2002][2005];
mint num[2002][2005];

bool z(char c){return (c == '0' || c == '?');}
bool o(char c){return (c == '1' || c == '?');}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tests;
    cin >> tests;
    for(int casenum = 1; casenum <= tests; casenum++){
        int n;
        cin >> n;
        string s;
        string t;
        cin >> s >> t;
        for(int i=0; i<n+1; i++){
            for(int j=-1002; j<1002; j++){
                num[i][j+1002] = 0;
                ans[i][j + 1002] = 0;
            }
        }
                num[0][1002] = 1;

        for(int i=0; i<n; i++){
         
        

            for(int j=-1002; j<1002; j++){
                
       
                if(z(s[i]) && z(t[i])){
                    num[i+1][j+1002] += num[i][-j+1002];

                    ans[i+1][j+1002] += ans[i][-j+1002] + num[i][-j+1002]*abs(j);
                    
                }
              
                if(z(s[i]) && o(t[i])){
              
                    num[i+1][j+1002] += num[i][1-j+1002];
               

                    ans[i+1][j+1002] += ans[i][1-j+1002] + num[i][1-j+1002]*abs(j);
                }
                if(o(s[i]) && z(t[i])){
                    num[i+1][j+1002] += num[i][-1-j+1002];

                    ans[i+1][j+1002] += ans[i][-1-j+1002] + num[i][-1-j+1002] * abs(j);
                }
                if(o(s[i]) && o(t[i])){
                    num[i+1][j+1002] += num[i][-j+1002];

                    ans[i+1][j+1002] += ans[i][-j+1002] + num[i][-j+1002]*abs(j);
                }
            }

        }
        cout << ans[n][0+1002] << endl;

    }
    
    
}