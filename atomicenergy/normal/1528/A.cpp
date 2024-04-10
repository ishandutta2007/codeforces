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
vector<long long> l, r;
vector<vector<long long> > g;

pair<long long, long long> dfs(long long v, long long p){
    pair<long long, long long> ans = {0, 0};
    for(auto u : g[v]){
        if(u == p) continue;
        auto a = dfs(u, v);
        ans.first += max(a.first + abs(l[v] - l[u]), a.second + abs(l[v] - r[u]));
        ans.second += max(a.first + abs(r[v] - l[u]), a.second + abs(r[v] - r[u]));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    long long tests;
    cin >> tests;
    for(long long casenum = 1; casenum <= tests; casenum++){
        long long n;
        cin >> n;
        l = vector<long long> (n);
        r = vector<long long> (n);
        for(long long i=0; i<n; i++){
            long long x, y;
            cin >> x >> y;
            
            l[i] = x;
            r[i] = y;
        }
        
        
        
        g = vector<vector<long long> >(n);
        for(long long i=0; i<n-1; i++){
            long long x, y;
          cin >> x >> y;
          x--, y--;
          g[x].push_back(y);
          g[y].push_back(x);
        }
        auto ans = dfs(0, -1);
        cout << max(ans.first, ans.second) << endl;
        
    }
    
}