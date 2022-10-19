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



struct uf {
    vector<long long> rt, sz;

    uf(long long n) {
        rt.resize(n);
        sz.resize(n);
        for (long long i = 0; i < n; i++) {
            rt[i] = i;
            sz[i] = 1;
        }
    }

    long long id(long long x) {
        if (rt[x] == x) return x;
        return rt[x] = id(rt[x]);
    }

    bool join(long long x, long long y) {
        x = id(x);
        y = id(y);
        if (x == y) return false;
        rt[x] = rt[y];
        sz[y] += sz[x];
        sz[x] = 0;
    return true;
    }
};

    vector<vector<pair<long long, long long>> > g;
    vector<vector<pair<long long, pair<long long, long long>>> > g2;
    long long n, m, x;
vector<long long> l;
long long dfs(long long v, long long p){
  long long excess = 0;
  excess += l[v] - x;
  for(long long i=0; i<g[v].size(); i++){
    long long u = g[v][i].first;
    if(u == p) continue;
    long long z= dfs(u, v);
    excess += z;
    g2[v].push_back({z, {u, g[v][i].second}});
  }
  sort(g2[v].begin(), g2[v].end());
  reverse(g2[v].begin(), g2[v].end());
  return excess;
}

void dfs2(long long v, long long p, long long attop){

    attop += l[v];
    for(long long i=0; i<g2[v].size(); i++){
        long long u = g2[v][i].second.first;
        if(u == p) continue;
        if(attop  >= x){
            cout << g2[v][i].second.second << endl;
            dfs2(u, v, attop -x);
        }else{
            dfs2(u, v, 0);
            cout << g2[v][i].second.second << endl;
        }
        attop += g2[v][i].first;
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    
    cin >> n >> m >> x;
    
    long long s = 0;
    for(long long i=0; i<n; i++){
        long long x;
        cin >> x;
        l.push_back(x);
        s+=x;
    }
    if(s < (n-1) * x){
        cout << "NO" << endl;
        return 0;
    }
    g = vector<vector<pair<long long, long long>> >(n);
    g2 = vector<vector<pair<long long, pair<long long, long long>>> >(n);
    cout <<"YES" << endl;
    uf u(n);
    for(long long i=0; i<m; i++){
        long long x, y;
      cin >> x >> y;
      x--, y--;
      if(u.join(x, y)){
        g[x].push_back({y, i+1});
        g[y].push_back({x, i+1});
      }
    }
    dfs(0, -1);
    dfs2(0, -1, 0);
    
    
    
}