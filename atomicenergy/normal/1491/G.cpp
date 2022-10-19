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
    
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        x--;
        v.push_back(x);
    }
    vector<vector<int> > cyc;
    vector<bool> seen(n, false);
    for(int i=0; i<n; i++){
        if(i == v[i]) continue;
        if(!seen[i]){
            vector<int> nw(1, i);
            seen[i] = true;
            int j = v[i];
            while(j != i){
                seen[j] = true;
                nw.push_back(j);
                j = v[j];
            }
             cyc.push_back(nw);
        }
       
    }
    vector<pair<int, int> > ans;
    while(cyc.size() >= 2){
        vector<int> a = cyc.back();
        cyc.pop_back();
        vector<int> b = cyc.back();
        cyc.pop_back();
        ans.push_back({a[0], b[0]});
        for(int i=1; i<a.size(); i++){
            ans.push_back({b[0], a[i]});
        }
        for(int i=1; i<b.size(); i++){
            ans.push_back({a[0], b[i]});
        }
        ans.push_back({a[0], b[0]});
    }
    if(cyc.size() == 1){
        vector<int> a = cyc[0];
        if(a.size() == 2){
            int z = 0;
            while(a[0] == z || a[1] == z) z++;
            ans.push_back({z, a[0]});
            ans.push_back({z, a[1]});
            ans.push_back({z, a[0]});
        }
        else{
            ans.push_back({a[0], a.back()});
            for(int i=1; i<a.size()-2; i++){
                ans.push_back({a[i], a.back()});
            }
            ans.push_back({a[0], a[a.size()-2]});
            ans.push_back({a[a.size()-2], a.back()});
            ans.push_back({a[0], a.back()});
        }

    }
    
    cout << ans.size() << endl;
    for(auto p : ans) cout << p.first+1 << " " << p.second+1 << endl;
}