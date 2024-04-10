
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
        string s;
        cin >> n;
        cin >> s;
        bool noleft = true, noright = true;
        for (int i = 0; i < n; i++) {
            if (s[i] == '<') noleft = false;
            if (s[i] == '>') noright = false;
        }
        if (noleft || noright) {
            cout << n << endl;
            continue;
        }
        int tot = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '-' || s[(i + 1) % n] == '-') tot++;
        }
        cout << tot << endl;
    }

}