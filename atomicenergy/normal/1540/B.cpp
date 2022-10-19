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

vector<vector<int> > g;
vector<int> place;

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

vector<vector<mint> > numbers (201, vector<mint>(201));


bool dfs1(int v, int p, int t, int d){
    if(v == t){
        place[v] = d;
        return true;
    }
  for(int i=0; i<g[v].size(); i++){
    int u = g[v][i];
    if(u == p) continue;
    if(dfs1(u, v, t, d+1)){
        place[v] = d;
        return true;
    }
  }
  return false;
}
int total = 1;
mint dfs2(int v, int p, int cur){
    if(place[v]) cur = place[v];
    mint tot = 0;
    tot += numbers[cur - 1][total];
    for(int i=0; i<g[v].size(); i++){
        int u = g[v][i];
        if(u == p) continue;
        tot += dfs2(u, v, cur);
    }
    return tot;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for(int i=0; i<=200; i++){
        for(int j=0; j<=200; j++){
            //i is "numerator"
            //j is "denominator"
            if(i == 0) {
                numbers[i][j] = 0;
                continue;
            }
            if(i == j){
                numbers[i][j] = 1;
                continue;
            }
            if(j == 0) continue;
            numbers[i][j] = (numbers[i-1][j-1] + numbers[i][j-1]) / 2;
        }
    }
    g = vector<vector<int> >(n);
    for(int i=0; i<n-1; i++){
        int x, y;
      cin >> x >> y;
      x--, y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    mint ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            place = vector<int>(n);
            dfs1(i, -1, j, 1);
            total = place[j] - 1;
            ans += dfs2(i, -1, 1);
          //  cout << i << " " << j << " " << dfs2(i, -1, 1) << endl;
        }
    }
    ans/=n;
    cout << ans << endl;
    
    
}