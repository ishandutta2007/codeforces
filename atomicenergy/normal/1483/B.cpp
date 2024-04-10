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

int gcd(int x, int y){
    if(x==0 || y==0) return x+y;
    if(x < y) return gcd(y, x);
    return gcd(x%y, y);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int tests;
    cin >> tests;
    for(int casenum = 1; casenum <= tests; casenum++){
        int n;
        cin >> n;
        vector<int> v;
        vector<pair<int, int>> vs;
        vector<int> after(n);
        for(int i=0; i<n; i++){
            vs.push_back({i, (i+1)%n});
            after[i] = (i+1)%n;
        }
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        int i=0;
        vector<bool> skip(n, false);
        vector<int> ans;
        int tot = 0;
        while(vs.size()>i){
            auto cur = vs[i];
            
            i++;
            if(cur.first == cur.second) {
                if(gcd(v[cur.first], v[cur.second]) > 1){
                    continue;

                }
                tot++;
                ans.push_back(cur.second);
                break;
            }
            if(gcd(v[cur.first], v[cur.second]) > 1){
                continue;

            }
            if(vs.size() > i){
                if(vs[i].first == cur.second){
                    i++;
                }
            }
            tot++;
            ans.push_back(cur.second);
            after[cur.first] = after[cur.second];
            vs.push_back({cur.first, after[cur.first]});
        }
        cout << tot << " ";
        for(int i=0; i<ans.size(); i++){
            cout << ans[i]+1 << " ";      
        }
        cout << endl;
        
        
    }
    
}