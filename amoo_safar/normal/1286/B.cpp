#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 2e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<pll> V[Maxn];
vector<ll> G[Maxn];
ll c[Maxn];
void DFS(ll u, ll p){
	ll sm = 0;
	for(auto adj : G[u]){
		if(adj == p) continue;
		DFS(adj, u);
		for(auto x : V[adj]){
			V[u].pb({x.F + sm,x.S});
		}
		sm += V[adj].size();
	}
	if(c[u] > sm){
		cout << "NO\n";
		exit(0);
	}
	for(auto &x : V[u]){
		if(x.F >= c[u] + 1) x.F = x.F + 1;
	}
	V[u].pb({c[u] + 1, u});
}


ll ans[Maxn];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll p;
	ll rt;
	for(int i = 1; i <= n; i++){
		cin >> p >> c[i];
		if(p != 0){
			G[i].pb(p);
			G[p].pb(i);
		} else rt = i;
	}
	DFS(rt, -1);
	for(auto x : V[rt]) ans[x.S] = x.F;
	cout << "YES\n";
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	
	return 0;
}