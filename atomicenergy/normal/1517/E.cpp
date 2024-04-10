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





int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll tests;
    cin >> tests;
    for(ll casenum = 1; casenum <= tests; casenum++){
        ll n;
        cin >> n;
        vector<ll> v;
        for(ll i=0; i<n; i++){
            ll x;
            cin >> x;
            v.push_back(x);
        }
        //want positive P-C
        //case1 CCCCCPCPCPCPPPPPPPPP
        vector<ll> ev;
        vector<ll> od;
        ll sum = 0;
        for(ll i=0; i<n; i+=2){
            sum += v[i];
        }
        ev.push_back(sum);
        for(ll i=0; i<n; i+=2){
            sum -= 2*v[i];
            ev.push_back(sum);
        }
        sum = 0;
        for(ll i=1; i<n; i+=2){
            sum += v[i];
        }
        od.push_back(sum);
        for(ll i=1; i<n; i+=2){
            sum -= 2*v[i];
            od.push_back(sum);
        }
        //want to know how many of ev + od > 0
        reverse(ev.begin(), ev.end());
        //ev is increasing, od is decreasing;
        ll ei = 0;
        ll oi = 0;
        mint ans = 0;
        while(ei < ev.size()){
            if(oi == od.size() || ev[ei] + od[oi] <= 0){
                ei++;
                ans += oi;
                continue;
            }
            else{
                oi++;
                
                continue;
            }
        }
        
        //case1 PCC [CCCPCPCPCPPPPPPPPP]
        if(v.size() > 2){
            ll cur = v[0] - v[1] - v[2];
            vector<ll> ev;
            vector<ll> od;
            ll sum = 0;
            for(ll i=3; i<n; i+=2){
                sum += v[i];
            }
            ev.push_back(sum);
            for(ll i=3; i<n; i+=2){
                sum -= 2*v[i];
                ev.push_back(sum);
            }
            sum = 0;
            for(ll i=4; i<n; i+=2){
                sum += v[i];
            }
            od.push_back(sum);
            for(ll i=4; i<n; i+=2){
                sum -= 2*v[i];
                od.push_back(sum);
            }
    
            //want to know how many of ev + od > 0
            reverse(ev.begin(), ev.end());
            //ev is increasing, od is decreasing;
            ll ei = 0;
            ll oi = 0;
            while(ei < ev.size()){
                if(oi == od.size() || ev[ei] + od[oi] + cur <= 0){
                    ei++;
                    ans += oi;
                    continue;
                }
                else{
                    oi++;
                    
                    continue;
                }
            }

        }

        //case [CCCPCPCPCPPPPPPPPP] PPC
        if(v.size() > 2){
            ll cur = v[n-3] + v[n-2] - v[n-1];
            vector<ll> ev;
            vector<ll> od;
            ll sum = 0;
            for(ll i=0; i<n-3; i+=2){
                sum += v[i];
            }
            ev.push_back(sum);
            for(ll i=0; i<n-3; i+=2){
                sum -= 2*v[i];
                ev.push_back(sum);
            }
            sum = 0;
            for(ll i=1; i<n-3; i+=2){
                sum += v[i];
            }
            od.push_back(sum);
            for(ll i=1; i<n-3; i+=2){
                sum -= 2*v[i];
                od.push_back(sum);
            }
    
            //want to know how many of ev + od > 0
            reverse(ev.begin(), ev.end());
            //ev is increasing, od is decreasing;
            ll ei = 0;
            ll oi = 0;
            while(ei < ev.size()){
                if(oi == od.size() || ev[ei] + od[oi] + cur <= 0){
                    ei++;
                    ans += oi;
                    continue;
                }
                else{
                    oi++;
                    
                    continue;
                }
            }

        }
   
        //case PCC [CCCPCPCPCPPPPPPPPP] PPC
        if(v.size() > 5){
            ll cur = v[0] - v[1] - v[2] + v[n-3] + v[n-2] - v[n-1];
            vector<ll> ev;
            vector<ll> od;
            ll sum = 0;
            for(ll i=3; i<n-3; i+=2){
                sum += v[i];
            }
            ev.push_back(sum);
            for(ll i=3; i<n-3; i+=2){
                sum -= 2*v[i];
                ev.push_back(sum);
            }
            sum = 0;
            for(ll i=4; i<n-3; i+=2){
                sum += v[i];
            }
            od.push_back(sum);
            for(ll i=4; i<n-3; i+=2){
                sum -= 2*v[i];
                od.push_back(sum);
            }
    
            //want to know how many of ev + od > 0
            reverse(ev.begin(), ev.end());
            //ev is increasing, od is decreasing;
            ll ei = 0;
            ll oi = 0;
            while(ei < ev.size()){
                if(oi == od.size() || ev[ei] + od[oi] + cur <= 0){
                    ei++;
                    ans += oi;
                    continue;
                }
                else{
                    oi++;
                    
                    continue;
                }
            }

        }

        //caselast PPCCCCCC
        if(v.size() > 3){
            sum = 0;
            for(ll i=0; i<n-1; i++){
                
                sum += v[i];
            }
            sum -= v[n-1];
            for(ll i=n-2; i>1; i--){
                sum -= 2*v[i];
                if(sum > 0 ) ans=ans+1;
            }
        }
        

        cout << ans << endl;

        
    }
    
}