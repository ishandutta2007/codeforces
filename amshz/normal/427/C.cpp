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
const int xn = 1e5+10;
const int xlg = 22;
const int SQ = 233;
const int sq = 1e5+10;
const ll inf = 1e18+10;
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
 
 
int n, m, cnt, Par[xn], D[xn];
ll a[xn], Ways = 1, Ans;
vector <int> adj[xn], adj2[xn], G[xn], Comp[xn];
stack <int> Stack;
bool Mark[xn];

void DFS2(int v){
	Mark[v] = true;
	for (int i = 0; i < adj[v].size(); i ++){
		int u = adj[v][i];
		if (Mark[u]) continue;
		if (Par[v] != Par[u]) D[Par[u]] ++;
		DFS2(u);
	}
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
	Stack.push(v);
}

void SCC(){
	for (int i = 1; i <= n; i ++){
		if (Mark[i]) continue;
		DFS(i);
	}
	memset(Mark, false, sizeof Mark);
	
	while (Stack.size()){
		int v = Stack.top();
		Stack.pop();
		if (Mark[v]) continue;
		SFD(v, cnt ++);
	}
	memset(Mark, false, sizeof Mark);
	
	for (int i = 1; i <= n; i ++){
		if (Mark[i]) continue;
		DFS2(i);
	}
}

 
 
int main(){
	fast_io;
	
	
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	cin >> m;
	int v, u;
	for (int i = 0; i < m; i ++){
		cin >> v >> u;
		adj[v].push_back(u);
		adj2[u].push_back(v);
	}
	
	SCC();
	
	for (int i = 0; i < cnt; i ++){
		ll mn = inf, t = 0;
		for (int j = 0; j < Comp[i].size(); j ++){
			v = Comp[i][j];
			mn = min(mn, a[v]);
		}
		for (int j = 0; j < Comp[i].size(); j ++){
			v = Comp[i][j];
			if (a[v] == mn) t ++;
		}
		Ans += mn;
		Ways *= t, Ways = (Ways + MD) % md;
	}
	
	cout << Ans << sep << Ways << endl;
	
	
	return 0;
}