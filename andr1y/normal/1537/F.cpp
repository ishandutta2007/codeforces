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
ll ov[N], ot[N];
ll sc[3], col[N];
bool bi=1;
void dfs(ll v){
	sc[col[v]]+=ot[v]-ov[v];
	for(auto &i : d[v]){
		if(!col[i]) {
			col[i] = 3^col[v];
			dfs(i);
		}
		if(col[i]==col[v]) bi=0;
	}
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n, m;
		cin >> n >> m;
		for(ll i =1;i<=n;i++){
			d[i].clear();
			col[i]=0;
		}
		ll x=0;
		for(ll i = 1;i<=n;i++) {cin >> ov[i];x^=(ov[i]&1);}
		for(ll i = 1;i<=n;i++) {cin >> ot[i];x^=(ot[i]&1);}
		for(ll a, b, i=0;i<m;i++){
			cin >> a>> b;
			d[a].push_back(b);
			d[b].push_back(a);
		}
		if(x){
			cout<<"NO\n";
			continue;
		}
		sc[2]=sc[1]=0;bi=1;col[1]=1;dfs(1);
		if(!bi || sc[1]==sc[2]) cout<<"YES\n";
		else cout<<"NO\n";
	}
}