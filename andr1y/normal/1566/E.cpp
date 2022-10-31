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
vector<ll> d[N];
bool leaf[N], bud[N];
ll lc=0, bc=0;
void dfs(ll v=1, ll p=0){
	ll kids=0;
	ll lf=0, bf=0;
	for(auto i : d[v]){
		if(i!=p){
			dfs(i, v), kids++;
			if(leaf[i])lf++;
			if(bud[i]) bf++;
		}
	}
	if(lf==0){
		lc++;
		leaf[v]=1;
	}else{
		if(v!=1){
			bud[v]=1;
			bc++;
		}
	}
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n;
		cin >> n;
		lc=0, bc=0;
		for(ll i =1;i<=n;i++) d[i].clear(), leaf[i]=0, bud[i]=0;
		for(ll a, b, i=1;i<n;i++){
			cin >> a >> b;
			d[a].push_back(b);
			d[b].push_back(a);
		}
		dfs();
		cout<<lc-bc<<'\n';
	}
}