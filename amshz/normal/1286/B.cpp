# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e3+10;
const int xm = 3e5+10;
const int SQ = 500;
const ll inf = 1e18+10;

int n, p[xn], c[xn], a[xn], sz[xn], root;
vector <int> adj[xn];
bool fl1;

void DFS2(int v, int x, int y, int z){
	a[v] += z;
	if (a[v] >= x) a[v] += y;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		DFS2(u, x, y, z);
	}
}


void DFS(int v){
	sz[v] = 1;
	//a[v] = 1;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		DFS(u);
		sz[v] += sz[u];
	}
	int s = 0;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		s += sz[u];
		if ((s-sz[u] < c[v] && s >= c[v]) || (s-sz[u] <= c[v] && s >= c[v] && c[v] == 0)) DFS2(u, c[v]+1, 1, s-sz[u]), s++;
		else DFS2(u, 0, s-sz[u], 0);
	}
	a[v] = c[v] + 1;
}

 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> p[i] >> c[i];
		if (p[i]) adj[p[i]].pb(i);
		else root = i;
	}
	DFS(root);
	
	for (int i = 1; i <= n; i++) if (c[i] > sz[i] - 1) fl1 = true;
	
	if (fl1){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++) cout << a[i] << sep;
	cout << endl;
	
	
	return 0;
}