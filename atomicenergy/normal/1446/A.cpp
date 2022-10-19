
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
    for (ll casenum = 1; casenum <= tests; casenum++) {
        ll n, w;
        cin >> n >> w;

        vector<ll> v;
        ll s = 0;
        bool going = true;
        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            if (x > w) continue;
            if (going && s + x <= w) {
                v.push_back(i+1);
                s += x;
            }
            else if (going && s*2 < w) {
                v.clear();
                v.push_back(i+1);
                going = false;
                s = x;
            }
        }
        if (2*s < w || s > w) {
            cout << -1 << endl;
        }
        else {
            cout << v.size() << endl;
            for (ll i = 0; i < v.size(); i++) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
        




    }

}