
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
        vector<string> v;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            v.push_back(s);
        }
        vector<string> t = {"OX.", "XO.", "X.O", "O.X", ".OX", ".XO"};
        int mintot = n * n + 1;
        int mini = 7;
        for (int i = 0; i < 6; i++) {
            int tot = 0;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (t[i][(j + k) % 3] != '.' && t[i][(j + k) % 3] != v[j][k] && v[j][k] != '.') tot++;
                }
            }
            if (tot < mintot) {
                mintot = tot;
                mini = i;
            }
        }
        int i = mini;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (t[i][(j + k) % 3] != '.' && t[i][(j + k) % 3] != v[j][k] && v[j][k] != '.') {
                    v[j][k] ^= ('X' ^ 'O');
                }
            }
        }
        for (auto s : v) {
            cout << s << endl;
        }
    }

}