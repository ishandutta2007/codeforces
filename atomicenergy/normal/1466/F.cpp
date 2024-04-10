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

mint power(mint a, int b){
  if(b == 0) return 1;
  mint y = power(a, b/2);
  if(b%2 == 0) return y*y;
  return y*y*a;
}

struct uf {
    vector<int> rt, sz, ac;
    uf(int n) {
        rt.resize(n);
        sz.resize(n);
                ac.resize(n);

        for (int i = 0; i < n; i++) {
            rt[i] = i;
            sz[i] = 1;
            ac[i] = 0;
        }
    }

    int id(int x) {
        if (rt[x] == x) return x;
        return rt[x] = id(rt[x]);
    }

    bool join(int x, int y) {
        x = id(x);
        y = id(y);
        if (x == y) return false;
        rt[x] = rt[y];
        sz[y] += sz[x];
        ac[y] = ac[x] | ac[y];
        sz[x] = 0;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> m >> n;
    
    

    uf u1 = uf(n);
    uf u2 = uf(n);
    vector<vector<int> > all;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x;
        if(x == 1){
            cin >> x;
            x--;
            all.push_back({x});
        }else{
            cin >> x >> y;
            x--, y--;
            u1.join(x, y);
            all.push_back({x, y});
        }
    }
    vector<int> sol;
    for(int i=0; i<all.size(); i++){
        auto v = all[i];
        if(v.size() == 1){
            int x = v[0];
            if(!u2.ac[u2.id(x)]){
                u2.ac[u2.id(x)] = true;
                sol.push_back(i);
            }
        }else{
            int x = v[0];
            int y = v[1];
            if(u2.ac[u2.id(x)] && u2.ac[u2.id(y)]) continue;
            if(u2.join(x, y)){
                sol.push_back(i);
            }
        }
    }
    cout << power(2, sol.size()) << " " << sol.size() << endl;
    for(int i=0; i<sol.size(); i++){
        cout << sol[i]+1 << " ";      
    }
    cout << endl;
    
    
}