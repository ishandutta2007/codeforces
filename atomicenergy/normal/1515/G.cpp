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
    vector<vector<pair<long long, long long>> > g;
    vector<vector<pair<long long, long long>> > h;
vector<long long> seen;
vector<long long> seen2;
vector<long long> dist;
vector<long long> gcds;
vector<long long> par;
vector<long long> comp;
long long cur = 0;

long long gcd(long long a, long long b){
    if(a ==0  || b == 0) return a+b;
    if(a < b) return gcd(b, a);
    return gcd(a%b, b);
}


void dfs(long long v, long long p, long long d){
    if(seen[v]){
        //gcds[cur] = gcd(gcds[cur], d+dist[v]);
        return;
    }
    par[v] = cur;
  dist[v] = d;
  seen[v] = true;
  for(long long i=0; i<g[v].size(); i++){
    long long u = g[v][i].first;
    if(comp[u] != comp[v]) continue;
    dfs(u, v, d+g[v][i].second);
  }
  
}

void dfs2(long long v, long long p, long long d){
    gcds[cur] = gcd(gcds[cur], d+dist[v]);
    if(seen2[v]){
        
        return;
    }
    par[v] = cur;
  seen2[v] = true;
  
  for(long long i=0; i<h[v].size(); i++){
    long long u = h[v][i].first;
    if(comp[u] != comp[v]) continue;
    dfs2(u, v, d+h[v][i].second);
  }
  
}

int SZ = 0; //the number of sccs
    vector<int> ID; //id[v] is the scc id of v
    int LS = 0;
    vector<int> L;
    vector<vector<int>> R, gg;

    void dfs1(int v) {
        if (ID[v]) return;
        ID[v] = 1;
        for (auto u : gg[v])
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
        int n = g.size();
        R.resize(n), ID.resize(n), L.resize(n);
        for (int i = 0; i < n; i++) {
            for (auto u : gg[i]) {
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
            for (int v : gg[u])
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
    
    long long n, m, q;
    cin >> n >> m;
    g = vector<vector<pair<long long, long long>> >(n);
    h = vector<vector<pair<long long, long long>> >(n);
    gg = vector<vector<int> >(n);
    for(long long i=0; i<m; i++){
        long long x, y, l;
      cin >> x >> y >> l;
      x--, y--;
      g[x].push_back({y, l});
      gg[x].push_back(y);
      h[y].push_back({x, l});
    }
    vector< vector<int> > aa = scc().first;
    comp = vector<long long>(n, false);
    int ii = 0;
    for(vector<int> a : aa){
        for(int z : a){
            comp[z] = ii;
        }
        ii++;
    }
       

    seen = vector<long long>(n, false);
    seen2 = vector<long long>(n, false);
        dist = vector<long long>(n, false);

    gcds = vector<long long>(n, false);
    par = vector<long long>(n, false);
    for(long long i=0; i<n; i++){
        if(!seen[i]){
            cur = i;
            dfs(i, -1, 0);
            dfs2(i, -1, 0);
        }
    }



    cin >> q;

    for(long long i=0; i<q; i++){
        long long v, s, t;
        cin >> v >> s >> t;
        v--;
        if(s == 0 || s % gcd(gcds[par[v]], t) == 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    
    
}