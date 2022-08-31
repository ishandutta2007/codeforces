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
 
const ll   N     =  2e+5+3;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll a[N],n,u,m;
set <ll> s[4];

int main(){
	fastio;

	cin>>n;

	for(ll i = 0; i < n; i++){
		cin>>a[i];
	}	
	for(ll i = 0; i < n; i++){
		cin>>u;
		s[u].insert(a[i]);
	}
	for(ll i = 0; i < n; i++){
		cin>>u;
		s[u].insert(a[i]);
	}

	cin>>m;
	while(m--){
		cin>>u;
		if(s[u].size() > 0){
			auto it = s[u].begin();
			ll v = *it;
			s[1].erase(v);
			s[2].erase(v);
			s[3].erase(v);
			cout<<v<<" ";
		}
		else cout<<-1<<" ";
	}

	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}