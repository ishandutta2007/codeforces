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
const ll N = 1e5+18;
ll p1[N], p2[N];
ll f1(ll v){
	return p1[v]==v?v:p1[v]=f1(p1[v]);
}
ll f2(ll v){
	return p2[v]==v?v:p2[v]=f2(p2[v]);
}
bool u1(ll a, ll b){
	a=f1(a), b=f1(b);
	if(a==b) return 0;
	p1[b]=a;
	return 1;
}
bool u2(ll a, ll b){
	a=f2(a), b=f2(b);
	if(a==b) return 0;
	p2[b]=a;
	return 1;
}
bool u(ll a, ll b){
	if(f1(a)==f1(b) || f2(a)==f2(b)) return 0;
	return u1(a, b)&&u2(a, b);
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, m1, m2;
	cin >> n >> m1 >> m2;
	for(ll i = 1;i<=n;i++) p1[i]=i, p2[i]=i;
	for(ll a, b, i=0;i<m1;i++){
		cin >> a >> b;
		u1(a, b);
	}
	for(ll a, b, i=0;i<m2;i++){
		cin >> a >> b;
		u2(a, b);
	}
	vector<pll> res;
	for(ll i = 1;i<=n;i++){
		for(ll j = i+1;j<=n;j++){
			if(u(i, j)) res.push_back({i, j});
		}
	}
	cout<<res.size()<<'\n';
	for(auto i : res) cout<<i.x<<' '<<i.y<<'\n';
}