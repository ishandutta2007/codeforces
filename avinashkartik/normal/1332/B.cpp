#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,vll>  um;
typedef  vector<pll>           vpll;
#define  x                     first                 
#define  y                     second                
 
const ll   N     =  2e5+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
#define maxBits 22
#define maxMask (1<<maxBits)
 
ll t=1,n,a[N],spf[1005],ans[N];
um m;;

void sieve(){
    for(int i = 2; i < 1001; i++) spf[i] = i;
    for(int i = 2; i*i <= 1005; i++){
        if(spf[i] == i){
            for(int j = i; j <= 1005; j += i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

int main(){
    fastio;
    sieve();
    cin>>t;
    while(t--){
        m.clear();
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            //cout<<spf[a[i]]<<" ";
            m[spf[a[i]]].push_back(i);
        }
        ll ct = 1;
        for(auto it : m){
            for(auto it1 : it.y) ans[it1] = ct;
            ct++;
        }
        cout<<ct-1<<endl;
        for(int i = 0; i < n; i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
}