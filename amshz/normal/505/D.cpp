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
const int xn = 1e5 + 10;
const int xm = 1e5;
const int SQ = 233;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}


int n, m, ans, Flag;
vector <int> adj[xn], G[xn], Comp, adj2[xn], Stack;
bool Mark[xn], mark[xn];


void DFS2(int v){
	mark[v] = true;
	for (int i = 0; i < adj[v].size(); i ++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS2(u);
	}
	Stack.push_back(v);
}

void SFD(int v){
	mark[v] = true;
	for (int i = 0; i < adj2[v].size(); i ++){
		int u = adj2[v][i];
		if (mark[u]) continue;
		SFD(u);
	}
}


void DFS(int v){
	Mark[v] = true;
	Comp.push_back(v);
	for (int i = 0; i < G[v].size(); i ++){
		int u = G[v][i];
		if (Mark[u]) continue;
		DFS(u);
	}
}

void Solve(){
	memset(mark, false, sizeof mark);
	for (int i = 0; i < Comp.size(); i ++){
		int v = Comp[i];
		if (mark[v]) continue;
		DFS2(v);
	}
	memset(mark, false, sizeof mark);
	Flag = 0;
	while (Stack.size()){
		int v = Stack.back();
		Stack.pop_back();
		if (mark[v]) continue;
		SFD(v);
		Flag ++;
	}
	ans -= (Flag == Comp.size());
}

 
 
int main(){
	fast_io;
	
	cin >> n >> m;
	int v, u;
	ans = n;
	for (int i = 0; i < m; i ++){
		cin >> v >> u;
		adj[v].push_back(u);
		adj2[u].push_back(v);
		G[v].push_back(u);
		G[u].push_back(v);
	}
	
	for (int i = 1; i <= n; i ++){
		if (Mark[i]) continue;
		Comp.resize(0);
		DFS(i);
		Solve();
	}
	
	cout << ans << endl;
	
	return 0;
}