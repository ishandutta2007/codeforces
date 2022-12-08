#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define pb push_back
#define F first
#define S second

const int MAXN=2e5+7;
vector<ll>g[MAXN],w[MAXN];
ll d[MAXN];
set<pair<ll,ll> >st;

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m;cin >> n >> m;
	for (ll i=0;i<m;i++){
		ll x,y,z;cin >> x >> y >> z;
		g[x].pb(y);
		g[y].pb(x);
		w[x].pb(2*z);
		w[y].pb(2*z);
	}
	for (ll i=1;i<=n;i++){
		cin >> d[i];
		st.insert({d[i],i});
	}
	while (st.size()){
		auto p=st.begin();
		ll x=p->S;
		st.erase(p);
		for (ll i=0;i<(ll)g[x].size();i++){
			ll y=g[x][i];
			if (d[y] > d[x]+w[x][i]){
				st.erase({d[y],y});
				d[y] = min(d[x]+w[x][i],d[y]);
				st.insert({d[y],y});
			}
		}
	}
	for (ll i=1;i<=n;i++)
		cout << d[i] << '\n';
}