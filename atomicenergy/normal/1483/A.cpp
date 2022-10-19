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
        vector<vector<int>> vv;
        vector<int> cnts(n+1);
        for(int i=0; i<m; i++){
            vector<int> v;
            int x;
            cin >> x;
            for(int i=0; i<x; i++){
                int z;
                cin >> z;
                v.push_back(z);
            }
            vv.push_back(v);
            if(x == 1) cnts[v[0]]++;
        }
        int ok = false;
        for(int i=0; i<=n; i++){
            if(cnts[i] > (m+1)/2){
                cout << "NO" << endl;
                ok = true;
            }
        }
        if(ok) continue;
        vector<int> ans(m);
        for(int i=0; i<m; i++){
            ans[i] = vv[i][0];
            if(vv[i].size()==1) continue;
            for(int j=1; j<vv[i].size(); j++){
                if(cnts[vv[i][j]] < cnts[ans[i]]){
                    ans[i] = vv[i][j];
                }
            }
            cnts[ans[i]]++;
        }
        cout << "YES" << endl;
        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";      
        }
        cout << endl;
        

        
        
    }
    
}