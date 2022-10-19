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
        vector<vector<ll> > g;
        g = vector<vector<ll> >(n);
        map<ll, ll> m;
        for(ll i=0; i<n-1; i++){
            ll x, y;
          cin >> x >> y;
          x--, y--;
          g[x].push_back(y);
          g[y].push_back(x);
          m[v[x]]++;
          m[v[y]]++;
        }
        ll cur = 0;
        for(auto x : v) {
            m[x]--;
            if(m[x] == 0) m.erase(x);
            cur+=x;
        }
        for(ll i=0; i<n-2; i++){
            cout << cur << " ";
            auto p = *m.rbegin();
            cur += p.first;
            m[p.first]--;
            if(m[p.first] == 0) m.erase(p.first);
        }
        
        cout << cur << endl;
        
        
    }
    
}