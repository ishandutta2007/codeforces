
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

    ll n;
    cin >> n;

    vector<ll> v;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v.push_back(x);
    }
    vector < pair<ll, vector<ll> > > a;
    a.push_back({ 0, v });
    for (ll i = 30; i >= 0; i--) {
        vector < pair<ll, vector<ll> > > b;
        for (auto p : a) {
            vector<ll> zeroes;
            vector<ll> ones;
            for (auto j : p.second) {
                if (j & (1 << i)) ones.push_back(j);
                else zeroes.push_back(j);
            }
            if (!ones.size() || !zeroes.size()) b.push_back(p);
            else {
                b.push_back({ p.first + zeroes.size() - 1, ones });
                b.push_back({ p.first + ones.size() - 1, zeroes });
            }
        }
        a = b;
    }
    ll mn = 100000000;
    for (auto p : a) if (p.first < mn) mn = p.first;
    cout << mn << endl;


}