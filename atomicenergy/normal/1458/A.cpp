
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

ll gcd(ll a, ll b) {
    if (a == 0 || b == 0) return a+b;
    if (a > b) return gcd(b, a);
    return gcd(b % a, a);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    ll start;
    vector<ll> a;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    if (n == 1) {
        for (int i = 0; i < m; i++) {
            ll x;
            cin >> x;
            cout << a[0] + x << " ";
        }
        return 0;
    }
    start = abs(a[1]-a[0]);
    for (int i = 1; i < n; i++) {
        start = gcd(start, abs(a[i] - a[0]));
    }
    vector<ll> b;
  
    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        b.push_back(x);
        cout << gcd(start, a[0] + b[i]) << " ";
    }




}