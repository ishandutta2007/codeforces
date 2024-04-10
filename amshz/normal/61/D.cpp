# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int xn = 1e5+10;
vector <int> adj[xn];
bool mark[xn];
map < pair <int, int>, ll > dis;
ll ans = 0;

void DFS2(int v, ll s){
	mark[v] = true;
	int t = 0;
	pair <int, int> pr;
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		pr.first = v;
		pr.second = u;
		ll s2 = s + dis[pr];
		DFS2(u, s2);
		t++;
	}
	if (t == 0) ans = max(ans, s);
}

ll DFS(int v){
	ll s = 0;
	pair <int, int> pr;
	mark[v] = true;
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		pr.first = v, pr.second = u;
		s += 2*dis[pr] + DFS(u);
	}
	return s;
}

int main(){
	int n;
	cin >> n;
	int x, y, z;
	pair <int, int> pr;
	for (int i=0; i<n-1; i++)
		cin >> x >> y >> z, adj[x].push_back(y), adj[y].push_back(x), pr.first = x, pr.second = y, dis[pr] = z, swap(pr.first, pr.second), dis[pr] = z;
	ll s = DFS(1);
	for (int i=1; i<=n; i++) mark[i] = false;
	DFS2(1, 0);
	cout << s-ans << endl;
	return 0;
}