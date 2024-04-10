
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


ll number(ll n, ll k) {
    if (k > n) return n;
    //we will have n%k pieces of size n/k+1 and the rest of size n/k
    return (n % k) * (n / k + 1) * (n / k + 1) + (k - (n % k)) * (n / k) * (n / k);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;


    vector<ll> v;
    vector<ll> pieces;
    //s has {negative improvement, index}
    ll total = 0;
    set<pair<ll, ll> > s;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v.push_back(x);
        total += x * x;
        pieces.push_back(1);
        s.insert({ number(x, 2) - number(x, 1),i });
        //cout << number(x, 2) << "!" << number(x, 1) << endl;
    }
    //cout << number(100000, 2) - number(100000, 1) << endl;
    for (int i = 0; i < k-n; i++) {
        auto p = *(s.begin());
        //cout << p.first << " " << p.second << endl;
        s.erase(p);
        //cout << p.first << endl;
        total += p.first;
        pieces[p.second]++;
        s.insert({ number(v[p.second], pieces[p.second] + 1) - number(v[p.second], pieces[p.second]), p.second });
    }
    cout << total << endl;



}