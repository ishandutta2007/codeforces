
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
        int n;
        cin >> n;
        vector<int> v;
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
            m[x]++;
        }
        bool ok = true;
        for (auto p : m) { //6 if 4 lose, 7 if 5 lose
            if (p.second > ((n + 1) / 2)) ok = false;
        }
        if (!ok) {
            cout << -1 << endl;
            continue;
        }
        map<int, int> f;
        int tot = 2;
        f[v[0]]++;
        f[v[n - 1]]++;
        for (int i = 1; i < n; i++) {
            if (v[i] == v[i - 1]) {
                f[v[i]]+=2;

                tot += 2;
            }
        }
        int ans = 0;
        for (auto p : f) {
            if (p.second > tot - p.second + 2) {
                ans = (p.second - (tot - p.second + 2)) / 2;
            }
        }

        cout << (tot - 2) / 2 + ans << endl;


    }

}