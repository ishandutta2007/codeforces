# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 3e5+10;
const int xm = 1e2+10;
const int SQ = 1000;
const int sq = 1e3+10;
const int inf = 1e9+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

int n, s;
vector <int> adj[xn];
bool f[xn][2], mark[xn];


void DFS(int v){
	mark[v] = true;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS(u);
	}
}



int main(){
	fast_io;
	
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> f[i][0];
	for (int i = 1; i <= n; i++) cin >> f[i][1];
	
	int last = 0;
	for (int i = 1; i <= n; i++){
		if (!f[i][0]) continue;
		adj[last].pb(i);
		last = i;
	}
	last = n + 1;
	for (int i = n; i >= 1; i--){
		if (!f[i][1]) continue;
		adj[last].pb(i);
		last = i;
	}
	
	DFS(1);
	
	if (mark[s]) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	
	
	return 0;
}