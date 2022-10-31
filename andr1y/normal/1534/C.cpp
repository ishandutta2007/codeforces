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
const ll inf = 0x3fff3fff3fff3ff;
const ll N = 4e5+18;
const ll M = 1e9+7;
ll p[N], rng[N], a[N];
ll _f(ll v){
	return p[v]==v?v:p[v]=_f(p[v]);
}
void _u(ll a, ll b){
	a=_f(a), b=_f(b);
	if(a==b) return;
	if(rng[b]>rng[a])swap(a, b);
	p[b]=a;
	if(rng[a]==rng[b]) ++rng[a];
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n;
		cin >> n;
		for(ll i = 1;i<=n;i++){cin>>a[i];p[i]=i,rng[i]=0;}
		for(ll b, i = 1;i<=n;i++){cin>>b;_u(a[i], b);}
		set<ll> rs;for(ll i = 1;i<=n;i++) rs.insert(_f(i));
		ll res=1;
		for(auto &i : rs){
			res=(res*2)%M;
		}
		cout<<res<<'\n';
	}
}