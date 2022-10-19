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


    int SZ = 0; //the number of sccs
    vector<int> ID; //id[v] is the scc id of v
    int LS = 0;
    vector<int> L;
    vector<vector<int>> R, g;
    vector<int> a;

    void dfs1(int v) {
        if (ID[v]) return;
        ID[v] = 1;
        for (auto u : g[v])
            dfs1(u);
        L[LS++] = v;
    }

    void dfs2(int v, int r) {
        if (~ID[v]) return;
        ID[v] = r;
        for (int u : R[v])
            dfs2(u, r);
    }

    //First: list of vertices in each components, in topological order.
    //second: graph shrinking each SCC to a vertex, should be a DAG in topological order.
    pair<vector< vector<int> >, vector<vector<int> > > scc() {
        SZ = 0;
        LS = 0;
        R.clear();
        ID.clear();
        L.clear();
        int n = g.size();
        R.resize(n), ID.resize(n), L.resize(n);
        for (int i = 0; i < n; i++) {
            for (auto u : g[i]) {
                R[u].push_back(i);
            }
        }
        for (int v = 0; v < n; ++v)
            dfs1(v);
        fill(ID.begin(), ID.end(), -1);
        int mx = 0;
        for (int i = n - 1; i >= 0; --i) {
            
            if (ID[L[i]] == -1)
                dfs2(L[i], SZ++);
        }
        for (int i = 0; i < n; i++) {
            mx = max(mx, ID[i]);
        }
        vector<vector<int>> A(mx+1);
        vector<vector<int>> B(mx+1);
        for (int u = 0; u < n; ++u) {
            A[ID[u]].push_back(u);
            for (int v : g[u])
                if (ID[u] != ID[v])
                    B[ID[u]].push_back(ID[v]);
        }
        for (int i = 0; i < SZ; ++i) {
            sort(B[i].begin(), B[i].end());
            B[i].erase(unique(B[i].begin(), B[i].end()), B[i].end());
        }
        return { A, B };
    }
    

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tests;
    cin >> tests;
    for(int casenum = 1; casenum <= tests; casenum++){
        int n;
        cin >> n;
        vector<int> v;
        map<int, int> freq;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            x--;
            v.push_back(x);
            freq[x]++;
        }
        int mx = 0;
        bool morethanonemax = false;
        int themx = 0;
        int amt = 0;
        for(auto p : freq){
            if(p.second > mx){
                mx = p.second;
                themx = p.first;
                morethanonemax = false;
                amt = 1;
            }
            else if(p.second == mx){
                morethanonemax = true;
                amt++;
            }
        }
        vector<int> u;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            x--;
            u.push_back(x);
        }
        int desired = (n - mx);
        bool ok = true;
        for(int i=0; i<n; i++){
            if(morethanonemax && v[i] == u[i]) ok = false;
            if(!morethanonemax && freq[v[i]] != mx && v[i] == u[i]) ok = false;
        }
        if(!morethanonemax){
            set<pair<int, int>> ind;
            vector<pair<int, int> > edges;
            g = vector<vector<int> > (n);

            for(int i=0; i<n; i++){
                if(v[i] == themx || u[i] == themx) continue;
                g[v[i]].push_back(u[i]);
            }
            auto p = scc();
            for(auto v : p.first){
                if(v.size() > 1) ok = false;
            }
        }else{
            set<pair<int, int>> ind;
            vector<pair<int, int> > edges;
            g = vector<vector<int> > (n);
            a = vector<int > (n, -1);
            vector<int> starts;
            set<pair<int, int>> todo;
            set<int> ends;
            for(int i=0; i<n; i++){
                if(v[i] == themx || u[i] == themx) {
                    if(v[i] = themx){
                        a[u[i]] = 0;
                        starts.push_back(u[i]);
                        todo.insert({0, u[i]});
                    }else{
                        ends.insert(v[i]);
                    }
                    continue;
                }
                g[v[i]].push_back(u[i]);
            }

            auto p = scc();
            for(auto v : p.first){
                if(v.size() > 1) {
                    ok = false;
                }
            }
            if(ok != false) {
            while(!todo.empty()){
                auto i = *(todo.begin());
                if(a[i.second] != -1) {
                    todo.erase(i);

                    continue;
                };
                a[i.second] = i.first; 
                for(auto j : g[i.second]){
                    todo.insert({i.first + (freq[i.second] == mx?1:0), u[j]});
                }
                if(ends.count(i.second) && i.first + (freq[i.second] == mx?1:0) != amt-1) ok = false;
                todo.erase(i);
            }
            }

            
        }

        cout << (ok?"AC":"WA") << endl;
    }
    
    
    
    
    
}