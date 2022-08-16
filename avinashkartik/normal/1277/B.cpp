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
 
int n,a[N],b[26];
set <ll>s;

int main(){
	fastio;
	ll te;
	cin>>te;
	while(te--){
		s.clear();
		cin>>n;
		for(int i = 0;i<n;i++){
			cin>>a[i];
			if(a[i]%2 == 0) s.insert(a[i]);
		}
		ll ans = 0;
		while(s.size() > 0){
			auto it = s.end();
			it--;
			ll t = (*it);
			s.erase(t);
			if(t%4 == 0) s.insert(t/2);
			ans++;
		}
		cout<<ans<<endl;
	}

	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}