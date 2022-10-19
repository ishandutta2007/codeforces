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

vector<vector<int> > tree;
vector<int> ansa;
        vector<int> ansb;
        int cur = 1;

bool dfs(int v, int p){
    bool isleaf = true;
    vector<int> friends;
    int backup = -1;
    for(auto u : tree[v]){
        if(u == p) continue;
        bool b = dfs(u, v);
        if(b) {
            isleaf = false;
            friends.push_back(u);
        }
        else {
            backup = u;
        }
    }
    if(!isleaf){
        for(int i=0; i<friends.size(); i++){
            ansa[friends[i]] = cur + i;
            ansb[friends[i]] = cur + i + 1;
        }
        ansa[v] = cur + friends.size();
        ansb[v] = cur;
        cur = cur + friends.size() + 1;
    }
    if(p == -1 && isleaf){
        ansa[v] = ansa[backup];
        ansa[backup]++;
        ansb[v] = ansa[backup];
        cur++;
    }
    return isleaf;
}

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
        vector<bool> seen(n, false);
        
        tree = vector<vector<int> >(n);
        ansa = vector<int>(n, -1);
        ansb = vector<int>(n, -1);
        cur = 1;
        for(int i=0; i<n; i++){
            if(seen[i]) continue;
            g[i].push_back(i);
            sort(g[i].begin(), g[i].end());
            int z = 0;
            if(g[i].size() == n){
                ansa[i] = cur;
                ansb[i] = cur;
                cur++;
                continue;
            }
            while(g[i].size() > z && g[i][z] == z) z++;
            tree[i].push_back(z);
            tree[z].push_back(i);
            seen[i] = true;
            seen[z] = true;
        }
        for(int i=0; i<n; i++){
            if(ansa[i] != -1) continue;
            dfs(i, -1);
        }
        for(int i=0; i<ansa.size(); i++){
            cout << ansa[i] << " ";      
        }
        cout << endl;
        for(int i=0; i<ansb.size(); i++){
            cout << ansb[i] << " ";      
        }
        cout << endl;
    }
    
}