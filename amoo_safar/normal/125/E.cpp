#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int Maxn = 5e3 + 10;
const ll Inf = 1e9;
const ll Log = 30;

vector< pair<pll, pll> > E;

ll par[Maxn];

ll get(ll u){
	if(par[u] == u) return u;
	return par[u] = get(par[u]);
}
bool merge(ll u, ll v){
	u = get(u);
	v = get(v);
	if(u == v) return false;
	par[u] = v;
	return true;
}

vector<ll> ans;

ll check(ll x){
	for(auto &e : E)
		if((e.S.F == 1) || (e.S.S == 1))
			e.F.F += x;
	ans.clear();
	sort(all(E));
	iota(par, par + Maxn, 0);
	ll res = 0;
	
	for(auto e : E){
		if(merge(e.S.F, e.S.S)){
			if((e.S.F == 1) || (e.S.S == 1)) res ++;
			ans.pb(e.F.S);
		}
	}
	
	for(auto &e : E)
		if((e.S.F == 1) || (e.S.S == 1))
			e.F.F -= x;
	//cerr << res << '\n';
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	ll u, v, w;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> w;
		w *= 2;
		E.pb({{w, i}, {u, v}});
	}
	ll L = -Inf;
	ll R = Inf;
	//cerr << check(R) << '\n';
	if(k < check(R)) return cout << -1, 0;
	
	ll mid;
	while(L + 1 < R){
		mid = (L + R) >> 1;
		
		if(check(mid) <= k){
			//cerr << "! " << check(mid) << '\n';
			R = mid;
		}
		else L = mid;
	}
	//cerr << check(L) << '\n';
	check(R);
	cout << n - 1 << '\n';
	for(auto x : ans) cout << x + 1 << ' ';
	return 0;
}