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
        int n, m, x;
        cin >> n >> m >> x;
        vector<int> v;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        set<pair<int, int> > s;
        for(int i=0; i<m; i++){
            s.insert({0, i+1});
        }
        cout << "YES" << endl;
        for(int i=0; i<v.size(); i++){
            auto j = *(s.begin());
            cout << j.second << " ";
            s.erase(j);
            s.insert({j.first + v[i], j.second});
        }
        cout << endl;
        
    }
    
}