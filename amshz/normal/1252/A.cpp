# include <bits/stdc++.h>

using namespace std;

# define F first
# define S second

const int xn = 3e2+10;
vector <int> adj[xn], adj2[xn], ans;
bool mark[xn], fl[xn];
int o[xn], k, f, d[xn];
pair <int, int> lr[xn];

void DFS3(int v){
	mark[v] = true;
	ans.push_back(v);
	if (fl[v]) d[v] = f, f++;
	for (int i=0; i<adj2[v].size(); i++){
		int u = adj2[v][i];
		if (mark[u]) continue;
		DFS3(u);
		ans.push_back(v);
	}
}

void DFS2(int v){
	mark[v] = true;
	int mn = 1e9, mx = 0;
	vector < pair <pair <int, int> , int> > vec;
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS2(u);
		vec.push_back({lr[u], u});
		mn = min(mn, lr[u].F), mx = max(mx, lr[u].S);
	}
	if (vec.size() == 0) lr[v].F = o[v], lr[v].S = o[v];
	sort(vec.begin(), vec.end());
	for (int i=0; i<vec.size(); i++)
		adj2[v].push_back(vec[i].S);
	if (vec.size() > 0) lr[v].F = mn, lr[v].S = mx;
}

void DFS(int v){
	mark[v] = true;
	int t = 0;
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS(u);
		t++;
	}
	if (t == 0) k++, fl[v] = true;
}

int main(){
	int n;
	cin >> n;
	int x ,y;
	for (int i=0; i<n-1; i++)
		cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
	DFS(1);
	for (int i=0; i<k; i++) cin >> x, o[x] = i;
	for (int i=0; i<=n; i++) mark[i] = false;
	DFS2(1);
	for (int i=0; i<=n; i++) mark[i] = false;
	DFS3(1);
	for (int i=0; i<n; i++){
		if (fl[i] and d[i] != o[i]){
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i=0; i<ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}