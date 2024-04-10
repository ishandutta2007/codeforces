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
    for(int casenum = 1; casenum <= tests; casenum++){
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> v;
        for(int i=0; i<m; i++){
            v.push_back({1000000001, i});
        }
        for(int i=0; i<n; i++){
            vector<int> u;
            for(int j=0; j<m; j++){
                int x;
                cin >> x;
                u.push_back(x);
            }
            sort(u.begin(), u.end());
            sort(v.begin(), v.end());
            reverse(u.begin(), u.end());
            vector<int> ans(m);
            for(int j=0; j<m; j++){
                ans[v[j].second] = u[j];
                v[j].first = min(v[j].first, u[j]);
            }
            for(int j=0; j<m; j++){
                cout << ans[j] << " ";
            }
            cout << endl;
        }
    }
    
}