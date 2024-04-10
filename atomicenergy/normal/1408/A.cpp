
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

        vector<int> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }

        vector<int> b;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            b.push_back(x);
        }


        vector<int> c;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            c.push_back(x);
        }

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            if (a[i] != ans[(i + 1) % n] && a[i] != ans[(i - 1 + n) % n]) ans[i] = a[i];
            if (b[i] != ans[(i + 1) % n] && b[i] != ans[(i - 1 + n) % n]) ans[i] = b[i];
            if (c[i] != ans[(i + 1) % n] && c[i] != ans[(i - 1 + n) % n]) ans[i] = c[i];
        }


        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;





    }

}