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
    
    ll n, m, k;
    cin >> n >> m >> k;
    if(k %2 == 1){
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                cout << -1 << " ";
            }
            cout << endl;
        }
        return 0;
    }
    vector<ll > v(n*m);
    vector<vector<pair<ll, ll>> > g(n*m);
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m-1; j++){
            ll x;
            cin >> x;
            g[i*m + j].push_back({i*m + j + 1, x});
            g[i*m + j + 1].push_back({i*m + j, x});
        }
    }
    for(ll i=0; i<n - 1; i++){
        for(ll j=0; j<m; j++){
            ll x;
            cin >> x;
            g[i*m + j].push_back({i*m + j + m, x});
            g[i*m + j + m].push_back({i*m + j, x});
        }
    }
    for(ll i=0; i<(k/2); i++){
        vector<ll > u(n*m, 1000000000);
        for(ll j=0; j<n*m; j++){
            for(auto l : g[j]){
                u[j] = min(u[j], l.second + l.second + v[l.first]);
            }
        }
        swap(u, v);

    }
     for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                cout << v[i*m+j] << " ";
            }
            cout << endl;
        }
    
    
}