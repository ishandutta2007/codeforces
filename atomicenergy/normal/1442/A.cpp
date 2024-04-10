
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
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        int first = v[0];
        int second = 0;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (second > v[i]) {
                ok = false;
            }
            if (first > v[i]-second) {
                first = v[i] - second;
            }
            if (second + first < v[i]) {
                second = v[i] - first;
            }
            

        }
        cout << (ok ? "YES" : "NO") << endl;

    }


}