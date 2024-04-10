# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

# define F first
# define S second

const int xn = 1e5+10;

vector <int> adj[xn];
map < pair <int, int> , bool> w;
pair <int, int> p1;
ll tzd[xn], lnz[xn], lnb[xn], ans, n;
bool mark[xn];

bool fn1(string a){
	for (int i=0; i<a.size(); i++)
		if (a[i] != '4' and a[i] != '7') return false;
	return true;
}

void DFS3(int v){
	mark[v] = true;
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		if (w[{v, u}]) lnb[u] += (n - tzd[u]);
		else lnb[u] += (lnb[v] + lnz[v] - lnz[u]);
		DFS3(u);
	}
}

void DFS2(int v){
	mark[v] = true;
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS2(u);
		if (w[{v, u}]) lnz[v] += tzd[u];
		else lnz[v] += lnz[u];
	}
}

void DFS(int v){
	mark[v] = true;
	tzd[v]++;
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS(u);
		tzd[v] += tzd[u];
	}
}

int main(){
	cin >> n;
	int x, y;
	string z;
	for (int i=0; i<n-1; i++)
		cin >> x >> y >> z, adj[x].push_back(y), adj[y].push_back(x), w[{x, y}] = fn1(z), w[{y, x}] = fn1(z);
	
	DFS(1);
	
	for (int i=0; i<=n; i++) mark[i] = false;
	DFS2(1);
	
	for (int i=0; i<=n; i++) mark[i] = false;
	DFS3(1);
	
	for (int i=1; i<=n; i++)
		ans += (lnz[i] + lnb[i]) * (lnz[i] + lnb[i] -1);
	
	cout << ans << endl;
	return 0;
	
}