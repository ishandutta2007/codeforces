# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;

# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const ll md = 1e9+7;
const int xn = 3e5+10;
const int xk = 1e2+10;

ll n, s[xn], mn, mx;
vector <pii> adj[xn];
bool mark[xn];

void DFS(int v, int w){
	mark[v] = true;
	s[v] = 1;
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i].F;
		if (mark[u]) continue;
		
		DFS(u, adj[v][i].S);
		s[v] += s[u];
	}
	if (s[v]%2) mn += w;
	mx += w*min(s[v], 2*n-s[v]);
}


int main(){
	fast_io;
	
	int qq;
	cin >> qq;
	while (qq--){
		cin >> n;
		mn = 0, mx = 0;
		for (int i=0; i<=2*n; i++) mark[i] = 0, adj[i].resize(0);
		ll x, y, z;
		for (int i=0; i<2*n-1; i++) cin >> x >> y >> z, adj[x].pb({y, z}), adj[y].pb({x, z});
		DFS(1, 0);
		cout << mn << sep << mx << endl;
	}
	return 0;
}