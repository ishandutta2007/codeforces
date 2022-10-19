
using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
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
        int n, m, k;
        cin >> n >> m >> k;

        if (k >= 460) {
            cout << -1 << endl;
            continue;
        }
        vector<unordered_set<int> > g;
        g = vector<unordered_set<int> >(n);
        vector<int> removable;
        vector<int> exactly;
        vector<bool> all(n, true);
        for (int i = 0; i < m; i++) {
            int x, y;
           cin >> x >> y;

            if (x == y) continue;
            x--, y--;
            g[x].insert(y);
            g[y].insert(x);
        }
        int tot = n;
        k--;
        for (int i = 0; i < n; i++) {
            if (g[i].size() < k) {
                removable.push_back(i);
                all[i] = false;
            }
            if (g[i].size() == k) exactly.push_back(i);
        }
        int ind = 0;
        int ind2 = 0;
        bool cliqued = false;
        while (removable.size() > ind || exactly.size() > ind2) {
            if (removable.size() > ind) {
                int x = removable[ind];
                ind++;
                for (auto y : g[x]) {
                    g[y].erase(x);
                    if (g[y].size() == k) exactly.push_back(y);
                    if (g[y].size() < k && all[y]) {
                        removable.push_back(y);
                        all[y] = false;
                    }
                }
                continue;
            }
            if (exactly.size() > ind2) {
                int x = exactly[ind2];
                ind2++;
                if (!all[x]) continue;
                if (g[x].size() != k) {
                    ind2++;
                    continue;
                }
                int ok = true;
                for (auto y : g[x]) {
                    for (auto z : g[x]) {
                        if (y == z) continue;
                        if (!g[y].count(z)) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) break;
                }
                if (ok) {
                    cout << 2 << endl;
                    
                    for (auto y : g[x]) {
                        cout << y+1 << " ";
                    }
                    cout << x+1 << endl;
                    cliqued = true;
                    break;
                }
                all[x] = false;
                for (auto y : g[x]) {

                    g[y].erase(x);
                    if (g[y].size() == k) exactly.push_back(y);
                    if (g[y].size() < k && all[y]) {
                        removable.push_back(y);
                        all[y] = false;
                    }
                }
                continue;
            }
        }
        if (cliqued) continue;
        
        tot = 0;
        for (int i = 0; i < n; i++) {
            if (all[i]) tot++;
        }
        if (tot == 0) {
            cout << -1 << endl;
            continue;
        }
        cout << 1 << " " << tot << endl;
        for (int i = 0; i < n; i++) {
            if (all[i]) cout << i + 1 << " ";
        }
        cout << endl;
    }
    



}