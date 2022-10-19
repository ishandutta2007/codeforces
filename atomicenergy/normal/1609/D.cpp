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
    vector<int> rt, sz;

    uf(int n) {
        rt.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            rt[i] = i;
            sz[i] = 1;
        }
    }

    int id(int x) {
        if (rt[x] == x) return x;
        return rt[x] = id(rt[x]);
    }

    bool join(int x, int y) {
        x = id(x);
        y = id(y);
        if (x == y) return false;
        rt[x] = rt[y];
        sz[y] += sz[x];
        sz[x] = 0;
    return true;
    }
};



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    uf uf(n);

    set<pair<int, int>> s;
    for(int i=0; i<n; i++){
        s.insert({1, i});
    }
    int amt = 1;
    for(int i=0; i<m ; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        s.erase({uf.sz[uf.id(x)], uf.id(x)});
        if(uf.id(x) != uf.id(y)){
            s.erase({uf.sz[uf.id(y)], uf.id(y)});
        }
        if(uf.join(x, y)){
            
        }else{
            amt++;
        }
        s.insert({uf.sz[uf.id(x)], uf.id(x)});

        //get amt highest
        int tot = 0;
        int j=0;
        for(auto i = s.rbegin(); (j < amt && i != s.rend()); i++, j++){
            tot += (*i).first;
        }
        cout << tot-1 << endl;
    }
    
}