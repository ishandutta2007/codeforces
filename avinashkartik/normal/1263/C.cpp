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
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define	 x                     first                 
#define  y                     second                
 
const ll   N  =  2e+5+5;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll n;
vll a;
 
int main(){
    fastio;
    ll t;
    cin>>t;
    while(t--){
	    cin>>n;
	    a.clear();
	    for(ll i = sqrt(n) + 1; i > 0; i--){
	    	a.push_back(n/i);
	    }
	    ll ct = a.size();
	    ct += a[0];
	    cout<<ct<<endl;
	    for(int i = 0; i < a[0]; i++) cout<<i<<" ";
	    for(auto it : a) cout<<it<<" ";
	    cout<<endl;
	}
}