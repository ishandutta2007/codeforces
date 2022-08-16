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

ll n,a[N];
set <ll> s;
um m;
vll v;

int main(){
    fastio;
    ll t;
    cin>>t;
    while(t--){
    	s.clear();
    	v.clear();
    	cin>>n;
    	for(int i = 1; i <= n; i++) s.insert(i);
    	for(int i = 0; i < n; i++) cin>>a[i];
    	v.push_back(a[0]);
    	ll prev = a[0];
    	s.erase(a[0]);
    	int flag = 0;
    	for(int i = 1; i < n; i++){
    		if(a[i] == prev){
    			auto ind = s.lower_bound(0);
    			//cout<<*ind;
	    		if((*ind) > prev){
	    			flag = 1;
	    			break;
	    		}
	    		v.push_back(*ind);
	    		s.erase(*ind);
	    	}
	    	else{
	    		//cout<<a[i];
	    		v.push_back(a[i]);
    			prev = a[i];
    			s.erase(a[i]);
	    	}
    	}
    	if(flag == 1){
    		cout<<-1<<endl;
    	}
    	else{
    		for(auto it : v)cout<<it<<" ";
    		cout<<endl;
    	}
	}
}