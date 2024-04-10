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
const int xn = 3e3+10;
const int xm = 1e6+10;
const int xk = 1e4+10;
const int SQ = 320;
const int sq = 6e2+10;
const ll inf = 1e18+10;

int n, m, a[xn], b[xn], f, c[xn];
vector <int> adj[xn], Ans;
bool mark[xn];


void DFS(int v, int t){
	mark[v] = true;
	b[v] = t;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS(u, t);
	}
}

void ziad(){
	int t = 0;
	for (int i = 1; i <= n; i++) mark[i] = false;
	for (int i = 1; i <= n; i++){
		if (mark[i]) continue;
		DFS(i, t++);
	}
	int v = 1, u;
	for (int i = 2; i <= n; i++){
		if (b[i] == b[v]) continue;
		u = i;
		break;
	}
	swap(a[v], a[u]);
	Ans.pb(v), Ans.pb(u);
	f++;
	
	for (int i = 1; i <= n; i++) adj[i].resize(0), adj[i].pb(a[i]);
	
}
void kam(){
	int t = 0;
	for (int i = 1; i <= n; i++) mark[i] = false;
	for (int i = 1; i <= n; i++){
		if (mark[i]) continue;
		DFS(i, t++);
	}
	int v, u;
	for (int i = 1; i <= n; i++){
		if (i == a[i]) continue;
		v = i;
		break;
	}
	for (int i = 1; i <= n; i++){
		if (i == v || b[i] != b[v]) continue;
		u = i;
		break;
	}
	swap(a[v], a[u]);
	Ans.pb(v), Ans.pb(u);
	f--;
	
	for (int i = 1; i <= n; i++) adj[i].resize(0), adj[i].pb(a[i]);
}

 
int main(){
	//fast_io;
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], adj[i].pb(a[i]);
	cin >> m;
	
	f = n;
	int t = 0;
	for (int i = 1; i <= n; i++){
		if (mark[i]) continue;
		DFS(i, t++);
	}
	f -= t;
	
	while (f != m){
		if (f > m) kam();
		else ziad();
	}
	
	cout << Ans.size()/2 << endl;
	for (int i = 0; i < Ans.size(); i++) cout << Ans[i] << sep;
	cout << endl;
	
	return 0;
}