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
set<ll, greater<ll>> st[N];
bool isbad[N];
ll bc=0;
void add(ll v, ll u){
	if(u>v){
		if(!isbad[v]) ++bc;
		isbad[v]=1;
	}
	st[v].insert(u);
}
void rem(ll v, ll u){
	if(isbad[v]){
		isbad[v]=0;
		--bc;
	}
	st[v].erase(u);
	if(!st[v].empty() && *st[v].begin() > v){
		isbad[v]=1;
		++bc;
	}
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, m;
	cin >> n >> m;
	for(ll a, b, i=0;i<m;i++){
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	ll q;
	cin >> q;
	while(q--){
		ll type, a, b;
		cin >> type;
		if(type==1){
			cin >> a >> b;
			add(a, b);
			add(b, a);
		}else if(type==2){
			cin >> a >> b;
			rem(a, b);
			rem(b, a);
		}else{
			cout<<n-bc<<'\n';
		}
	}
}