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
const int xn = 2e5+10;
const int xm = 5e5+10;
const int xk = 1e5+10;
const int SQ = 320;
const int SQ2 = 4090;
const int SQ3 = 75;
const int inf = 1e9+10;
 
 
int n, Root, dist[xn], A, B, C, ans;
vector <int> adj[xn], Path;
queue <int> q;
bool Mark[xn], flag;


void Find_path(int v){
	Mark[v] = true;
	if (v == B) flag = true;
	for (int i = 0; i < adj[v].size(); i ++){
		int u = adj[v][i];
		if (Mark[u]) continue;
		Find_path(u);
		if (flag){
			Path.push_back(v);
			return;
		}
	}
}


void DFS(int v){
	Mark[v] = true;
	for (int i = 0; i < adj[v].size(); i ++){
		int u = adj[v][i];
		if (Mark[u]) continue;
		dist[u] = dist[v] + 1;
		DFS(u);
	}
}


 
 
int main(){
	fast_io;
	
	
	cin >> n;
	for (int i = 0; i < n - 1; i ++){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	
	Root = 1, A = 1;
	DFS(1);
	for (int i = 1; i <= n; i ++)
		if (dist[i] > dist[A]) A = i;
	
	memset(Mark, false, sizeof Mark);
	memset(dist, 0, sizeof dist);
	DFS(A);
	B = 1;
	for (int i = 1; i <= n; i ++)
		if (dist[i] > dist[B]) B = i;
	ans += dist[B];
	
	memset(Mark, false, sizeof Mark);
	Find_path(A);
	
	for (int i = 1; i <= n; i ++) dist[i] = -1;
	for (int i = 0; i < Path.size(); i ++) dist[Path[i]] = 0, q.push(Path[i]);
	
	while (q.size()){
		int v = q.front();
		q.pop();
		for (int i = 0; i < adj[v].size(); i ++){
			int u = adj[v][i];
			if (dist[u] != -1) continue;
			dist[u] = dist[v] + 1;
			q.push(u);
		}
	}
	
	C = A;
	for (int i = 1; i <= n; i ++){
		if (i == A || i == B) continue;
		if (dist[i] >= dist[C]) C = i;
	}
	ans += dist[C];
	
	cout << ans << endl << A << sep << B << sep << C << endl;
	
	
	
	return 0;
}