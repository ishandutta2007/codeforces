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
const int Inf = N + N;

vector<int> G[N];
int n;
ll ans;
ll dp[N], dp2[N];

void DFS(ll u, ll p){
	dp[u] = Inf;
	dp2[u] = 0;
	for(auto adj : G[u]){
		if(adj == p) continue;
		DFS(adj, u);
		dp[u] = min({dp[u] + min(dp[adj], 1 + dp2[adj]), dp2[u] + 1 + min(dp[adj], dp2[adj])});
		dp2[u] += dp[adj];
	}
}
vector<int> H[N];
void DFS2(ll u, ll p, ll st){
	if(st == 2){
		for(auto adj : G[u]){
			if(adj != p) DFS2(adj, u, 1);
		}
		return ;
	}
	int fl = 0, la = -1;
	for(auto adj : G[u]){
		if(adj == p) continue;
		la = adj;
		if(1 + dp2[adj] <= dp[adj]){
			DFS2(adj, u, 2);
			H[u].pb(adj);
			H[adj].pb(u);
			fl = 1;
		} else {
			DFS2(adj, u, 1);
		}
	}
	if(!fl){
		assert(la != -1);
		H[u].pb(la);
		H[la].pb(u);
	}
}

int mk[N];
vector<int> V;
void dfs(ll u){
	V.pb(u);
	mk[u] = 1;
	for(auto adj : H[u]) if(!mk[adj]) dfs(adj);
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
	cout << dp[1] + dp[1] << '\n';
	debug("A");
	DFS2(1, -1, 1);
	debug("B");
	for(int i = 1; i <= n; i++){
		if(mk[i]) continue;
		V.clear();
		dfs(i);
		int m = V.size();
		for(int i = 0; i < m; i++) des[V[i]] = V[(i + 1) % m];
	}
	/*
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
	*/
	for(int i = 1; i <= n; i++) cout << des[i] << ' ';
	cout << '\n';
	
	return 0;
}