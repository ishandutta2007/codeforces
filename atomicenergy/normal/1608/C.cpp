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
        int n;
        cin >> n;
        vector<vector<int> > v;
        vector<int> maxbefore;
        vector<int> minafter;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            v.push_back({x, i});
        }
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            v[i].push_back(x);
        }
        sort(v.begin(), v.end());
        int mx = v[0][2];
        for(int i=0; i<n; i++){
            mx = max(v[i][2], mx);
            maxbefore.push_back(mx);
        }
        int mn = v[n-1][2];
        for(int i=n-1; i>=0; i--){
            mn = min(v[i][2], mn);
            minafter.push_back(mn);
        }
        reverse(minafter.begin(), minafter.end());
        int cutoff = 0;
        for(int i=0; i<n-1; i++){
            if(maxbefore[i] < minafter[i+1]) cutoff = i+1;
        }
        vector<int> answer(n, 0);
        for(int i=cutoff; i<n; i++){
            answer[v[i][1]] = 1;
        }
        for(auto c : answer){
            cout << c;
        }
        cout << endl;

    }
    
}