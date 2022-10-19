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
        ll n, m;
        cin >> n >> m;
        vector<ll> v;
        for(ll i=0; i<n; i++){
            ll x;
            cin >> x;
            v.push_back(x);
        }
        vector<ll> u;
        for(ll i=0; i<m; i++){
            ll x;
            cin >> x;
            u.push_back(x);
        }
        sort(v.begin(), v.end());
        ll present = 0;
        ll total = 0;
        for(ll i=v.size()-1; i>=0; i--){
            if(present <= v[i]-1){
                total += u[present];
                present++;
            }else{
                total += u[v[i]-1];
            }
        }
        cout << total << endl;
        
        
    }
    
}