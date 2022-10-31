# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 2e5+10;
const int xm = 30+10;
const int SQ = 200;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

int root;
ll dp[xn], ans, fact[xn], n;
vector <int> adj[xn];
bool mark[xn];

void DFS(int v){
	mark[v] = true;
	ll S = 1;
	dp[v] = S++;
	if (v == root) S--, dp[v] = n;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS(u);
		dp[v] = (dp[v] * dp[u] + 100 * md) % md;
		dp[v] = (dp[v] * S + 100 * md) % md;
		S++;
	}
}



int main(){
	fast_io;
	
	cin >> n;
	int v, u;
	for (int i = 0; i < n - 1; i++){
		cin >> v >> u;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	fact[0] = 1;
	for (ll i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i + 100 * md) % md;
	
	root = 1;
	DFS(root);
	
	cout << dp[root] << endl;
	
	
	return 0;
}