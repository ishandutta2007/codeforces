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


    int n;
    int m;

vector<int> dist;
    vector<int> choices;
    vector<int> choice;
    vector<vector<int>> todo;

mint solve(int i){
     dist = vector<int>(n, -1);
     choice = vector<int>(n, -1);
     choices = vector<int>(n, 1);
    todo = vector<vector<int> > (1, {i, 0, -1});

    int ind = -1;
    while(ind+1 < todo.size()){
        ind++;
        auto ti = todo[ind]; 
        if(dist[ti[0]] == ti[1]) choices[ti[0]]+=1;
        if(dist[ti[0]] != -1) continue;
        dist[ti[0]] = ti[1];
        choice[ti[0]] = ti[2];
        for(auto u : g[ti[0]]){
            if(dist[u] != -1) continue;
            todo.push_back({u, ti[1] + 1, ti[0]});
        }

    }

    mint ans = 1;
    for(auto c : choices) ans *= c;
    return ans;
}

mint choices2[1000];
int dist2a[1000];
int dist2b[1000];
int  todo2[3000][4];

mint solve2(int i, int j){
    

    for(int i=0; i<n; i++){
        dist2a[i] = -1;
        dist2b[i] = -1;
        choices2[i] = 1;
    }

    vector<int> revchoice2(n, -1);
    int cur = j;
    int d = 0;
    while(cur != -1){
        d++;
        if(choices[cur] > 1) return 0;
        if(choice[cur] != -1) revchoice2[choice[cur]] = cur;
        cur = choice[cur];
    }
    d--;
    
    todo2[0][0] = i;
    todo2[0][1] = 0;
    todo2[0][2] = -1;
    todo2[0][3] =  d;
    
    int ind2 = -1;
    int sz = 1;
    while(ind2+1 < sz){
        ind2++;
        auto ti = todo2[ind2];
        if(dist2b[ti[0]] > ti[3]){
            return 0;
        }
        if(dist2a[ti[0]] == ti[1]){
            if(dist2b[ti[0]] == ti[3]){
                choices2[ti[0]]+=1;
            }          
        }
        if(dist2a[ti[0]] != -1) continue;
        dist2a[ti[0]] =ti[1];
        dist2b[ti[0]] = ti[3];
        if(revchoice2[ti[0]] != -1){
            todo2[sz][0] = revchoice2[ti[0]];
            todo2[sz][1] =  ti[1] + 1;
            todo2[sz][2] = ti[0];
            todo2[sz][3] = ti[3] - 1;
            sz++;
        }
        for(auto u : g[ti[0]]){
            if(u == revchoice2[ti[0]]) continue;
            todo2[sz][0] = u;
            todo2[sz][1] = ti[1] + 1;
            todo2[sz][2] = ti[0];
            todo2[sz][3] = ti[3] + 1;
            sz++;
        }

    }
    mint ans = 1;
    for(int i=0; i<n; i++) ans *= choices2[i];
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    

    cin >> n >> m;
    g = vector<vector<int> >(n);
    for(int i=0; i<m; i++){
        int x, y;
      cin >> x >> y;
      x--, y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vector<vector<mint> > ans(n, vector<mint>(n, 0));
    for(int i=0; i<n; i++){
        ans[i][i] = solve(i);
        for(int j=0; j<n; j++){
            if (i < j){
                ans[i][j] = solve2(i, j);
                ans[j][i] = ans[i][j];
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}