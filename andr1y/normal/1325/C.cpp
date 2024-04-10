#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define x first
#define y second
#define pb push_back
const ll N = 1e5+228;
vector<pll> d[N];
vector<pll> oh[N];
ll ans[N];
ll pd[N];
ll n;
ll pp[N];
ll fz = 0;
bool dfs(ll v, ll p = 0){
	if(d[v].size() >= 3){
		ll k = 0;
		memset(ans, 0, sizeof(ans));
		for(auto i : d[v]){
			if(k== 3)break;
			if(k ==0) fz = i.y;
			ans[i.y] = k++;
		}
		return 1;
	}
	for(auto i : d[v]){
		if(i.x == p) continue;
		bool dd =dfs(i.x, v);
		if(dd) return 1;
	}
	return 0;
}
pll ed[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	for(ll a,  b,i = 0;i<n-1;i++){
		cin >> a >> b;
		d[a].pb({b, i});
		d[b].pb({a, i});
		ans[i] = i;
	}
	bool dd = dfs(1);
	if(dd){
		ll k = 3;
		for(ll i =0;i<n-1;i++){
			if(ans[i] == 0 && i != fz) ans[i] = k++;
			cout << ans[i] << '\n';
		}
	}else{
		for(ll i =0;i<n-1;i++){
			cout << ans[i] << '\n';;
		}
	}
}