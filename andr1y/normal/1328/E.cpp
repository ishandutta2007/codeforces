//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
vector<ll> d[N];
ll p[N], h[N];
ll tin[N], tout[N], timer = 0;
void dfs(ll v, ll pp = 0, ll hh = 1){
	p[v] = pp, h[v] = hh;
	tin[v] = ++timer;
	for(auto i : d[v]){
		if(i==pp) continue;
		dfs(i, v, hh+1);
	}
	tout[v] = ++timer;
}
bool upper(ll a, ll b){
	return tin[a]<=tin[b] && tout[a]>=tout[b];
}
ll qs[N], kc = 0;
pair<ll, ll> ks[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll n, m;
	cin >> n >> m;
	for(ll a, b, i = 0;i<n-1;i++){
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	dfs(1);
	while(m--){
		ll d;
		cin >> d;
		kc = 0;
		for(ll i = 0;i<d;i++){
			cin >> qs[i];
			if(qs[i]^1){
				ks[kc++] = {h[p[qs[i]]], p[qs[i]]};
			}
		}
		sort(ks, ks+kc, greater<pair<ll, ll>>());
		bool ok = 1;
		for(ll i = 1;i<kc && ok;i++){
			if(ks[i].first == ks[i-1].first && ks[i].second != ks[i-1].second) ok = 0;
		}
		if(!ok){
			cout << "NO\n";
			continue;
		}
		for(ll i = 1;i<kc && ok;i++){
			if(ks[i].second != ks[i-1].second && !upper(ks[i].second, ks[i-1].second)) ok = 0;
		}
		if(ok)cout << "YES\n";
		else cout << "NO\n";
	}
}