
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
        map<int, int> f;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            f[x]++;
            v.push_back(x);
        }
        int s = 0;
        int e = n - 1;
        bool perm = true;
        int onesatend = 0;
        for (int i = 1; i <= n; i++) if (f[i] != 1) perm = false;
        for (int i = 1; i < n; i++) {
            if (f[i] > 0) onesatend++;
            if (f[i] > 1) break;
            if (v[s] != i && v[e] != i) break;
            if (v[s] == i) s++;
            if (v[e] == i) e--;

        }
        if (perm) cout << 1;
        else cout << 0;
        for (int i = 0; i < n - 1 - onesatend; i++) cout << 0;
        for (int i = 0; i < onesatend; i++) cout << 1;
        cout << endl;
    }

}