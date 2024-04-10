//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 2e5+18;
set<ll> verts;
set<ll> kamni;
set<ll> sz[N];
ll p[N];
ll f_(ll a){
	return p[a]==a?a:p[a]=f_(p[a]);
}
bool u_(ll a, ll b){
	a=f_(a), b=f_(b);
	if(a==b) return 0;
	if(sz[a].size()<sz[b].size()) swap(a, b);
	p[b]=a;
	verts.erase(b);
	for(auto &i : sz[b]) sz[a].insert(i);
	return 1;
}
ll a[N], edc=0;
pair<pll, ll> conn[N], edges[N];
ll rb[1000001];
vector<pll> dd[N];
ll len[N];
void dfs(ll v, ll p = -1){
	for(auto i : dd[v]){
		if(i.x!=p){
			len[i.x]=max(len[v], i.y);
			dfs(i.x, v);
		}
	}
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, q, s, d;
	cin >> n >> q >> s >> d;
	for(ll i = 0;i<n;i++){
		cin >> a[i];
		rb[a[i]]=i;
		kamni.insert(a[i]);
		p[i]=i, sz[i].insert(i);
		verts.insert(i);
	}
	for(;verts.size()>1;){
		ll conc=0;
		for(auto i : verts){
			for(auto &j : sz[i]) kamni.erase(a[j]);
			ll minv=inf, minp2=0, minp1=0;
			for(auto &j : sz[i]) {
				auto it1 = kamni.lower_bound(a[j]+d); if(it1!=kamni.end()){ll v = abs(d-abs(*it1-a[j]));if(v<minv)minv=v, minp2=rb[*it1], minp1=j;}
				if(it1!=kamni.begin()) {it1 = prev(it1);ll v = abs(d-abs(*it1-a[j]));if(v<minv)minv=v, minp2=rb[*it1], minp1=j;}
				it1 = kamni.lower_bound(a[j]-d); if(it1!=kamni.end()){ll v = abs(d-abs(*it1-a[j]));if(v<minv)minv=v, minp2=rb[*it1], minp1=j;}
				if(it1!=kamni.begin()) {it1 = prev(it1);ll v = abs(d-abs(*it1-a[j]));if(v<minv)minv=v, minp2=rb[*it1], minp1=j;}
			}
			for(auto &j : sz[i]) kamni.insert(a[j]);
			if(minv!=inf) conn[conc++]={{minp1, minp2}, minv};
		}
		for(ll i = 0;i<conc;i++){
			if(u_(conn[i].x.x, conn[i].x.y)) edges[edc++]=conn[i];
		}
	}
	for(ll i = 0;i<edc;i++){
		dd[edges[i].x.x].push_back({edges[i].x.y, edges[i].y});
		dd[edges[i].x.y].push_back({edges[i].x.x, edges[i].y});
	}
	dfs(s-1);
	while(q--){
		ll i , k;cin>> i >> k;
		--i;
		if(len[i]>k) cout<<"no\n";
		else cout<<"yes\n";
	}
}