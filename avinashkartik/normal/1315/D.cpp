#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an lleratcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  unsigned long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<string,ll>  um;
typedef  vector<pll>           vpll;
#define  x                     first                 
#define  y                     second
#define  endl                  "\n"  
#define  pb                    push_back              
 
const ll   N     =  2e+5+7;
const ll   MAXN  =  1e+9;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll n,a[N],t[N],ans = 0,res = 0;
vpll v;
multiset<ll> s;

int main(){
    fastio;
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>t[i];
    for(int i = 0; i < n; i++) v.pb({a[i],t[i]});
    sort(v.begin(), v.end());
    ll i = 0;
    while(i < n){
        ll st = i,m;
        while(i < n && v[i].x == v[st].x){ s.insert(v[i].y); res += v[i].y; i++; }
        if(i == n) m = MAXN;
        else m = v[i].x - v[st].x + 1;
        ll ct = 0;
        //cout<<m;
        while(m--){
            auto it = s.end();
            it--;
            //cout<<ct<<" "<<(*it)<<" "<<res<<endl;
            if(m){ ans += ct*(*it); res -= (*it); s.erase(it); }
            else ans += ct*res;
            ct++;
            if(s.size() == 0) break;
        }
    }
    cout<<ans<<endl;
}