# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 1e5 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll gcd(ll a, ll b){
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return (gcd(b, a % b));
}

map <ll, ll> Mp;
int n, Root = 1;
ll ans, a[xn];
vector <int> adj[xn];
set <pii> st[xn];
bool Mark[xn];

void DFS(int v){
	Mark[v] = true;
	for (int u : adj[v]){
		if (Mark[u]) continue;
		Mp.clear();
		for (pii x : st[v]) Mp[gcd(x.F, a[u])] += x.S;
		Mp[a[u]] ++;
		for (pii x : st[v]) st[u].insert({gcd(x.F, a[u]), Mp[gcd(x.F, a[u])]}) ;
		st[u].insert({a[u], Mp[a[u]]});
		DFS(u);
	}
}
 
 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 0; i < n - 1; i ++){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	st[Root].insert({a[Root], 1});
	DFS(Root);
	for (int i = 1; i <= n; i ++)
		for (pii x : st[i]) ans = (ans + (x.F * x.S + 10 * md) % md) % md;
		
	cout << ans << endl;
	
	return 0;
}