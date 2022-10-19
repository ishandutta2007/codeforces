
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


    int tests;
    cin >> tests;
    for (int casenum = 1; casenum <= tests; casenum++) {
        ll n, k;
        cin >> n >> k;
        vector<vector<ll> > v;
        for (int i = 0; i < n; i++) {
            ll x, y;
            cin >> x >> y;
            v.push_back({ x, y });
        }
        bool found = false;
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (abs(v[i][0] - v[j][0]) + abs(v[i][1] - v[j][1]) > k) ok = false;
            }
            if (ok) found = true;
        }
        if (found) cout << 1 << endl;
        else cout << -1 << endl;
    }

}