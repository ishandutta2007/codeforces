using namespace std;



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
    
    int tests;
    cin >> tests;
    for(int casenum = 1; casenum <= tests; casenum++){
        ll n, k;
        cin >> n >> k;
        vector<ll> v;
        for(int i=0; i<n; i++){
            ll x;
            cin >> x;
            v.push_back(x);
        }
        ll gcd = 0;
        for(int i=1; i<v.size(); i++){
            gcd = __gcd(gcd, v[i] - v[0]);
        }
        if((k-v[0])%gcd != 0) cout << "NO" << endl;
        else cout << "YES" << endl;
        
    }
    
}