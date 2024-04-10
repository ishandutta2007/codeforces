// Null
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
const int N = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<int> G[N];
int n;
ll ans;
int sub[N];

int DFS(ll u, ll p){
	sub[u] = 1;
	for(auto adj : G[u]){
		if(adj == p) continue;
		sub[u] += DFS(adj, u);
	}
	ans += min(sub[u], n - sub[u]);
	return sub[u];
}
vector<int> V;
void dfs(ll u, ll p){
	V.pb(u);
	for(auto adj : G[u]) if(adj != p) dfs(adj, u);
}
int des[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	DFS(1, -1);
	cout << ans + ans << '\n';

	ll cen = 1;
	bool fnd = false;
	while(!fnd){
		fnd = true;
		for(auto adj : G[cen]){
			if(sub[adj] >= sub[cen]) continue;
			if(sub[adj] + sub[adj] > n){
				fnd = false;
				cen = adj;
				break;
			}
		}
	}
	dfs(cen, -1);
	ll jmp = n/2;
	for(int i = 0; i < n; i++){
		ll idx = (i + jmp) % n;
		des[V[i]] = V[idx];
	}
	for(int i = 1; i <= n; i++) cout << des[i] << ' ';
	cout << '\n';
	return 0;
}