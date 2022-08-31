#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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

template<typename has_less>
using ordered_set =
tree<has_less,
	null_type,
	less<has_less>,
	rb_tree_tag,
	tree_order_statistics_node_update>;
 
ll n,a[N],m,u,v,res[N],ans;
ordered_set <pll> s;
vpll vp;
vector<pair<pll,ll>> mp;
 
bool comp(pll &p, pll &q){
	if(p.first == q.first) return p.second < q.second;
	return p.first > q.first;
}
 
int main(){
    fastio;
    ll t;
    cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		vp.push_back({a[i],i});
	}
	sort(vp.begin(), vp.end(), comp);
	//for(auto it : vp) cout<<it.first<<" "<<it.second<<endl;
	
	cin>>m;
	for(int i = 0; i < m; i++){
		cin>>u>>v;
		mp.push_back({{u,v},i});
	}
	sort(mp.begin(), mp.end());
	ll ct = 0;
	for(int i = 0; i < m; i++){
		if(mp[i].first.first != ct){
			for(; ct < mp[i].first.first; ct++){
				s.insert({vp[ct].second,vp[ct].first});
			}
		}
		v = mp[i].first.second-1;
		auto ans = s.find_by_order(v);
		res[mp[i].second] = (*ans).second;
		//cout<<ans[mp[i].first.second-1]<<endl;
	}
	for(int i = 0; i < m; i++){cout<<res[i]<<endl;}
}