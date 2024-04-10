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
vector<vector<long long>> g, h;

long long mx;

//point update, range query, 0-indexed
struct bit {
    vector<long long> b;
    void init(int n){b.resize(n+1);}
    bit(){}
    bit(int n){init(n);}
    inline void update(int i, long long v) {
        query(i, i);
        v-=query(i, i);
        for(++i; i<(int)b.size(); i+=(i&-i))
            b[i] += v;
    }
    //sum of the first i values
    long long prefix(int i) const {
        long long a = 0;
        for(; i; i^=(i&-i))
            a += b[i];
        return a;
    }
    inline long long query(int l, int r) const {
        return prefix(r+1)-prefix(l);
    }
};


bit s;
vector<long long> l;
vector<long long> r;
vector<vector<long long> > ancs;
long long cr = 0;

long long blackinsubtree(long long v){
    return s.query(l[v], r[v])%1000000;
}

long long redinsubtree(long long v){
    return s.query(l[v], r[v])/1000000;
}

void add(long long v){
    //check if v has any red children
    bool b = redinsubtree(v);
    //check if v has any red ancestor
    long long a = v;
    if(!b){
        for(long long i=18; i>=0; i--){
            if(ancs[i][a] != -1){
                if(redinsubtree(ancs[i][a]) == 0){
                    a = ancs[i][a];
                }
            }
        }
        a = ancs[0][a];
    }
    

    //mark v as black
    if(b) s.update(l[v], 1);
    //if no red children, mark v as red.
    if(!b){
        s.update(l[v], 1000001);
        cr++;
        if(!b && a!= -1 && s.query(l[a], l[a]) == 1000001) {
            //if a red ancestor, mark that ancestor to black
            s.update(l[a], 1);
            cr--;
        }
        mx = max(mx, cr);
    }
    
    
}

void remove(long long v){
    //if v is not red, we can remove it and return
    if(s.query(l[v], l[v]) == 1){
        s.update( l[v], 0);
        return;
    }
    cr--;
    s.update( l[v], 0);
    //otherwise, check if it has any black ancestors
    long long a = v;
    
        for(long long i=18; i>=0; i--){
            if(ancs[i][a] != -1){
                if(blackinsubtree(ancs[i][a]) == 0){
                    a = ancs[i][a];
                }
            }
        }
        a = ancs[0][a];
    if(a!=-1 && redinsubtree(a)==0){
        cr++;
        //mark its lowest black ancestor red if that doesn't have any red children
        mx = max(mx, cr);
        s.update( l[a], 1000001);
    }
    
}

void dfs(long long v, long long p){
  add(v);
  for(long long i=0; i<g[v].size(); i++){
    long long u = g[v][i];
    if(u == p) continue;
    dfs(u, v);
  }
  remove(v);
}

long long i = 0;
void dfsh(long long v, long long p){
    l[v] = i;
    i++;
    for(long long i=0; i<h[v].size(); i++){
        long long u = h[v][i];
        if(u == p) continue;
        dfsh(u, v);
    }
    r[v] = i-1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    long long tests;
    cin >> tests;
    for(long long casenum = 1; casenum <= tests; casenum++){
        long long n;
        cin >> n;
        g = vector<vector<long long>>(n);
        h = vector<vector<long long>>(n);
        s = bit(2*n);
        l = vector<long long>(n);
        r = vector<long long>(n);
        ancs = vector<vector<long long> >(19, vector<long long>(n));
        mx = 0;
        cr = 0;
        for(long long i=1; i<n; i++){
            long long x;
            cin >> x;
            x--;
            g[x].push_back(i);
        }

        for(long long i=1; i<n; i++){
            long long x;
            cin >> x;
            x--;
            h[x].push_back(i);
            ancs[0][i] = x;
        }
        ancs[0][0] = -1;

        for(long long i=1; i<=18; i++){
            for(long long j=0; j<n; j++){
                if(ancs[i-1][j] == -1) ancs[i][j] = -1;
                else ancs[i][j] = ancs[i-1][ancs[i-1][j]];
            }
        }
        i = 0;
        
        dfsh(0, -1);
        dfs(0, -1);
        cout << mx << endl;
        
    }
    
}