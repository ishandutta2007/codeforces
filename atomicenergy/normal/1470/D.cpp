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
        vector<vector<int> > g;
        g = vector<vector<int> >(n);
        for(int i=0; i<m; i++){
            int x, y;
          cin >> x >> y;
          x--, y--;
          g[x].push_back(y);
          g[y].push_back(x);
        }
        vector<int> ans;
        vector<bool> okay(n, false);
        set<int> canbe;
        canbe.insert(0);
        int ok = 0;
        while(ok < n){
            if(canbe.empty()) break;
            int x = *(canbe.begin());
            canbe.erase(x);
            if(okay[x]) continue;
            ans.push_back(x);
            okay[x] = true;
            ok++;
            for(auto y : g[x]){
                if(okay[y]) continue;
                ok++;
                okay[y] = true;
                
                    for(auto z : g[y]){
                        if(!okay[z]) canbe.insert(z);
                    }
                
            }
        }
        if(ok != n){cout << "NO" << endl; continue;}
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for(int i=0; i<ans.size(); i++){
            cout << ans[i]+1 << " ";      
        }
        cout << endl;
        
        

    }
    
}