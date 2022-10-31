# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const ll MD = md * 100;
const int xn = 1e6 + 10;
const int xm = 1e5;
const int SQ = 233;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}


struct edge{
	int V, U;
	ll W;
};
 
 
int n, m, cnt, Par[xn], S, D[xn];
ll ans, PS[xn], Val[xn], dp[xn];
vector <int> adj[xn], adj2[xn], Comp[xn], vec;
vector <pair <int, ll> > G[xn];
bool Mark[xn];
edge E[xn];




void Build(){
	for (ll i = 1; i <= xm; i ++) PS[i] = PS[i - 1] + (i - 1) * i / 2;
}


ll Find(ll x){
	if (!x) return x;
	
	ll l = 1, r = xm, mid;
	while (r - l > 1){
		mid = (l + r) / 2;
		if (mid * (mid - 1) / 2 <= x) l = mid;
		else r = mid;
	}
	//ll l = ll(sqrt(x * 2));
	//if (l * (l + 1) / 2 <= x) l ++;
	
	return x * l - PS[l];
}


void DFS2(int v){
	Mark[v] = true;
	for (int i = 0; i < G[v].size(); i ++){
		int u = G[v][i].F;
		if (Mark[u]) continue;
		DFS2(u);
	}
	vec.push_back(v);
}


void SFD(int v, int c){
	Mark[v] = true;
	for (int i = 0; i < adj2[v].size(); i ++){
		int u = adj2[v][i];
		if (Mark[u]) continue;
		SFD(u, c);
	}
	Comp[c].push_back(v);
	Par[v] = c;
}


void DFS(int v){
	Mark[v] = true;
	for (int i = 0; i < adj[v].size(); i ++){
		int u = adj[v][i];
		if (Mark[u]) continue;
		DFS(u);
	}
	vec.push_back(v);
}

void SCC(){
	for (int i = 1; i <= n; i ++){
		if (Mark[i]) continue;
		DFS(i);
	}
	memset(Mark, false, sizeof Mark);
	
	while (vec.size()){
		int v = vec.back();
		vec.pop_back();
		if (Mark[v]) continue;
		SFD(v, cnt ++);
	}
	memset(Mark, false, sizeof Mark);
	
	for (int i = 0; i < m; i ++){
		int v = E[i].V, u = E[i].U;
		ll w = E[i].W;
		int pv = Par[v], pu = Par[u];
		if (pv == pu){
			E[i].W = Find(w);
			continue;
		}
		G[pv].push_back({pu, w});
	}
	
}

 
 
int main(){
	fast_io;
	
	Build();
	
	cin >> n >> m;
	int v, u;
	ll w;
	for (int i = 0; i < m; i ++){
		cin >> v >> u >> w;
		adj[v].push_back(u);
		adj2[u].push_back(v);
		E[i].V = v, E[i].U = u;
		E[i].W = w;
	}
	cin >> S;
	
	SCC();
	
	for (int i = 0; i < m; i ++){
		int v = E[i].V, u = E[i].U;
		ll w = E[i].W;
		if (Par[v] == Par[u]) Val[Par[v]] += w;
	}
	
	DFS2(Par[S]);
	
	for (int i = 0; i < cnt; i ++) dp[i] = Val[i];
	
	
	for (int pnt = 0; pnt < vec.size(); pnt ++){
		int v = vec[pnt];
		for (int i = 0; i < G[v].size(); i ++){
			int u = G[v][i].F;
			ll w = G[v][i].S;
			dp[v] = max(dp[v], Val[v] + dp[u] + w);
		}
	}
	
	cout << dp[Par[S]] << endl;
	
	return 0;
}