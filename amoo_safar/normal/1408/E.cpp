// That's How much we have in common
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
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;
const ld EPS = 1e-7;


int par[N];
int Find(int u){
	return (par[u] == u ? u : par[u] = Find(par[u]));
}
bool Unite(int u, int v){
	u = Find(u); v = Find(v);
	if(u == v) return false;
	par[u] = v;
	return true;
}



vector< pair<ll, pll> > E;
ll a[N], b[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	iota(par, par + N, 0);

	ll ans = 0;
	ll n, m;
	cin >> m >> n;
	for(int i = 1; i <= m; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];

	for(int i = 1; i <= m; i++){

		ll sz;
		cin >> sz;
		//cerr << "! " << i << ' ' << sz << '\n';
		ll v;
		for(int j = 1; j <= sz; j++){
			cin >> v;
			E.pb({a[i] + b[v], {i, m + v}});
			ans += a[i] + b[v];
		}
	}
	//cerr << ans << '\n';
	sort(all(E));
	reverse(all(E));
	for(auto [w, e] : E){
		if(Unite(e.F, e.S))
			ans -= w;
	}
	cout << ans << '\n';
	return 0;
}