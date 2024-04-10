# include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
 
const int xn = 5e1+10;
bool mark[xn];
vector <int> adj[xn];
ll mlf[xn];
 
void DFS(int v, int t){
	mark[v] = true;
	mlf[t]++;
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS(u, t);
	}
}
 
int main(){
	int n, m;
	cin >> n >> m;
	if (m == 0){
		cout << 1 << endl;
		return 0;
	}
	int x, y;
	for (int i=0; i<m; i++) cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
	int t = 0;
	for (int i=0; i<n; i++)
		if (!mark[i+1]) DFS(i+1, t), t++;
	ll ans = 0;
	for (int i=0; i<t; i++) ans += mlf[i]-1;
	ll s = 1;
	for (int i=0; i<ans; i++) s *= 2;
	cout << s << endl;
	return 0;
}