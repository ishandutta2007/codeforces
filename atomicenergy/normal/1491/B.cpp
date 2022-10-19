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
        int n, u, v;
        cin >> n >> u >> v;
        int ans = 6*v;
        vector<int> g;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            g.push_back(x);
        }
        int start = g[0];
        bool allsame = true;
        for(int i=1; i<n; i++){
            if(g[i] != g[i-1]) allsame = false;
            if(g[i] < start -1 || g[i] > start + 1) start = -2;
            else start = g[i];
        }
        if(start == -2) cout << 0 << endl;
        else if(!allsame) cout << min(u, v) << endl;
        else cout << min(2*v, u+v) << endl;
        
    }
    
}