//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <string>
#include <bitset>
#include <numeric>
#include <iomanip>
#include <limits.h>
#include <tuple>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll a[N];
vector <int> g[N];

void Main(){
    ll mx=0;
    ll n;
    cin >> n;
    for (int i=0;i<=n+1;i++){
        g[i].clear();
    }
    for (int i=1;i<=n;i++){
        cin >> a[i];
        g[a[i]].pb(i);
      //  cout << a[i] << " " << i << endl;
    }
    queue <pii> q;
    q.push({n+1,0});
    q.push({0,1});
    vector <int> ans;;
    
    while(q.size()){
        pii V=q.front();
        ll v=V.F;
        ll w=V.S;
        q.pop();
        if (v!=n+1 && v!=0) ans.pb(v);
        if (w==1) mx=max(mx,v);
        for (auto u : g[v]){
            if (g[u].size()==0) q.push({u,1-w});
        }
        for (auto u : g[v]){
            if (g[u].size()!=0) q.push({u,1-w});
        }
    }
     
    cout << mx << endl;
    for (auto u : ans){
        cout << u << " ";
    }
    cout << endl;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    
    while(t--) Main();
}