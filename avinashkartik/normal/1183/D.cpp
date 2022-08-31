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

const ll   N  =  2e+5+5;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,a[N],ind;
set <ll> s;
um m;
vll c;

int main(){
    fastio;
    ll t;
    cin>>t;
    while(t--){
    	s.clear();
    	c.clear();
	    cin>>n;
	    for(int j = 0; j < n; j++){
	    	cin>>a[j];
	    	s.insert(a[j]);
	    	m[a[j]]++;
	    }
	    for(auto it : s){
	    	c.push_back(m[it]);
	    	m[it] = 0;
	    }
	    sort(c.begin(), c.end(),greater <ll>());
	    ll prev = c[0]+1;
		ll ct = 0;
		for(auto it : c){
			prev = max(min(prev-1,it),0ll);
			ct += prev;
		}
		cout<<ct<<endl;
	}
}