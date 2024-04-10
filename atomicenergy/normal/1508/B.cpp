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
        ll n, k;
        cin >> n >> k;
        ll l = 1;
        ll r = 1;
        if(n < 62 && k > (1ll << (n-1))){
            cout << -1 << endl;
            continue;
        }
        k--;
        vector<ll> bin;
        for(ll i=(n-2); i>=0; i--){
            bool b;
            if(i < 62)
                b = (1ll << i) & (k);
            else
                b = false;
            if(b){
                r++;
            }else{
                for(ll j=r; j>=l; j--){
                    cout << j << " ";
                }
                r = r+1;
                l = r;
            }
        }
        for(ll j=r; j>=l; j--){
            cout << j << " ";
        }
        cout << endl;
    }
    
}