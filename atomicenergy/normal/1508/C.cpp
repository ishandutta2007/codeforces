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
    vector<ll> rt, sz;

    uf(ll n) {
        rt.resize(n);
        sz.resize(n);
        for (ll i = 0; i < n; i++) {
            rt[i] = i;
            sz[i] = 1;
        }
    }

    ll id(ll x) {
        if (rt[x] == x) return x;
        return rt[x] = id(rt[x]);
    }

    bool join(ll x, ll y) {
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
    ll n, m;
    cin >> n >> m;
    /*if(n >= 700){
        cout << 0 << endl;
        return 0;
    }
    for(ll i=0; i<n; i++){
        for(ll j=i+1; j<n; j++){
            graph[i][j] = 0;
        }
    }*/
    vector<pair<ll, pair<ll, ll> > > v;
    ll xorall = 0;
    set<pair<ll, ll> > edges;
    for(ll i=0; i<m; i++){
        ll x, y, z;

        cin >> x >> y >> z;
        x--;
        y--;
 
        edges.insert({x, y});
        edges.insert({y, x});
        xorall ^= z;
        v.push_back({z, {x, y}});
    }
    for(ll i=0; i<n; i++){
        //sort(graph[i].begin(), graph[i].end());
    }
    sort(v.begin(), v.end());
    uf u(n);
    uf vv(n);
    ll ans = 0;
    set<ll> notseen;
    vector<ll> seen;
    for(ll i=0; i<n; i++){
        notseen.insert(i);
    }
    ll comps = 0;
    while(!notseen.empty()){
        seen.clear();
        seen.push_back(*(notseen.begin()));
        notseen.erase(notseen.begin());
        comps++;
        for(ll i=0; i<seen.size(); i++){
            for(auto j = notseen.begin(); j!=notseen.end();){
                if(edges.count({seen[i], *j})){
                    j++;
                }else{
                    u.join(seen[i], *j);
                    seen.push_back(*j);
                    auto jj = j;
                    j++;
                    notseen.erase(jj);
                }
            }
        }
    }
    bool needextra = ((n-comps) == (n*(n-1))/2 - m);

    for(auto e : v){
        if(u.id(e.second.first) == u.id(e.second.second)){
            if(vv.id(e.second.first) == vv.id(e.second.second)) continue;
            if(needextra){
                needextra = false;
                ans += min(e.first, xorall);
            }
        }else{
            u.join(e.second.first, e.second.second);
            vv.join(e.second.first, e.second.second);
            ans += e.first;
        }
    }

    cout << ans << endl;
    
}