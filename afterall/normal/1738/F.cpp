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
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e3+100;
ll par[N];
ll d[N];
ll mark[N];
ll ask(ll v){
    cout << "? " << v << endl;
    ll u;
    cin >> u;
    return u;
    
}
ll getpar(ll v){
    if (par[v]==v) return v;
    return par[v]=getpar(par[v]);
}
void Main(){
    ll n;
    cin >> n;
    vector <pii> a;
    for (int i=1;i<=n;i++){
        par[i]=i;
        mark[i]=0;
        cin >> d[i];
        a.pb({d[i],i});
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for (auto U : a){
        ll u=U.S;
        if (mark[getpar(u)]) continue;
        mark[u]=1;
        for (int i=1;i<=d[u];i++){
            ll v=ask(u);
            if (mark[getpar(v)]){
                par[u]=getpar(v);
                break;
            }
            else{
                par[v]=getpar(u);
            }
        }
    }
    cout << "! " << endl;
    for (int i=1;i<=n;i++){
        cout << getpar(i) << " " ;
    }
    cout << endl;
    
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    
    while(t--) Main();
}