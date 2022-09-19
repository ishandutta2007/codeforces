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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<ll> G[N];
ll dep[N], par[N], mk[N];
vector<ll> D[N];
ll sq, lp;

void DFS(ll u, ll p, ll d){
	par[u] = p;
	mk[u] = 1;
	dep[u] = d;
	D[dep[u] % lp].pb(u);
	for(auto adj : G[u]){
		if(!mk[adj]) DFS(adj, u, d + 1);
	}

}


vector<pll> E;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	sq = sqrt(n);
	lp = sq;
	if(sq * sq < n) sq ++;
	debug(sq);
	ll u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
		E.pb({u, v});
	}
	DFS(1, -1, 0);
	ll mx = 0;
	for(int i = 1; i < lp; i++) if(D[mx].size() < D[i].size()) mx = i;
	for(auto e : E){
		u = e.F;
		v = e.S;
		//cerr << mx << " " << dep[u] << " " << dep[v] << '\n';
		if(dep[u] % lp == dep[v] % lp && dep[u] % lp == mx){
			if(dep[u] < dep[v]) swap(u, v);
			cout << "2\n";
			cout << dep[u] - dep[v] + 1 << '\n';
			while(u != v){
				cout << u << " ";
				u = par[u];
			}
			cout << u << '\n';
			return 0;
		}
	}
	cout << "1\n";
	for(int i = 0; i < sq; i++) cout << D[mx][i] << ' ';;
	return 0;
}