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
 
const ll   N     =  1e+5+5;
const ll   mod   =  1e+6+3;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll c[N],n,l,r,t,m;
vector <pair<ll,pll>> v;
set <pll> s;

int main(){
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		cin>>l>>r>>t>>c[i];
		v.push_back({l,{t,i}});
		v.push_back({r+1,{-t,i}});
	}
	sort(v.begin(), v.end());
	ll ind = 0;
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		while(ind < 2*m && v[ind].x == i){
			if(v[ind].y.x > 0) s.insert(v[ind].y);
			else s.erase({-v[ind].y.x,v[ind].y.y});
			ind++;
		}
		if(s.size() > 0){
			auto it = s.begin();
			ans += c[(*it).y];
		}
	}
	cout<<ans;
}