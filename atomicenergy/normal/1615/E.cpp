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
vector<vector<ll> > g;

set<pair<ll, ll>> dfs(ll v, ll p){
  set<pair<ll, ll>> ans;

  for(ll i=0; i<g[v].size(); i++){
    ll u = g[v][i];
    if(u == p) continue;
    set<pair<ll, ll>> s = dfs(u, v);
    if(s.size() > ans.size()){
        swap(ans, s);
    }
    for(auto p : s){
        ans.insert(p);
    }
  }
  if(ans.empty()){
      ans.insert({1, v});
  }else{
      auto big = *ans.rbegin();
      ans.erase(big);
      big.first++;
      ans.insert(big);
  }
  
  return ans;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
        ll n, k;
        cin >> n >> k;
        g = vector<vector<ll> >(n);
        for(ll i=0; i<n-1; i++){
            ll x, y;
          cin >> x >> y;
          x--, y--;
          g[x].push_back(y);
          g[y].push_back(x);
        }
        auto s = dfs(0, -1);
        ll w = 0;
        ll mx = -1000000000000ll;
        for(ll r=1; r<=k; r++){
            if(!s.empty()){
                auto big = *s.rbegin();
                s.erase(big);
                w += big.first - 1;
            }else{
                w--;
            }
           // cout << r << " " << w << endl;
            if((n - r - w) >= n/2){
                mx = max(mx, (n - r - n/2) * (r - n/2));
            }else{
                mx = max(mx, w * (r - (n - r - w)));
            }
        }
        cout << mx << endl;

    
    
}