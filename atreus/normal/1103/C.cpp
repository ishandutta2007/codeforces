/**
 *    author:  Atreus
 *    created: 22.01.2019
 **/
#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 3e5 + 10;

bool visited[maxn], isleaf[maxn];
int par[maxn], h[maxn];
vector <int> g[maxn], t[maxn];

void dfs(int v, int p = -1){
	visited[v] = 1;
	par[v] = p;
	isleaf[v] = 1;
	for (auto u : g[v]){
		if (!visited[u]){
			t[v].push_back(u);
			t[u].push_back(v);
			isleaf[v] = 0;
			h[u] = h[v] + 1;
			dfs(u, v);
		}
	}
}

int n, k;

int dis[maxn];
int root;
int par2[maxn];

void dfs2(int v, int p = -1){
	par2[v] = p;
	for (auto u : t[v]){
		if (u != p){
			dis[u] = dis[v] + 1;
			dfs2(u, v);
		}
	}
}

void perimeter(){
	dfs2(1);
	int w = -1;
	for (int u = 1; u <= n; u++)
		if (w == -1 or dis[w] < dis[u])
			w = u;
	memset(dis, 0, sizeof dis);
	dfs2(w);
	int z = -1;
	for (int u = 1; u <= n; u++)
		if (z == -1 or dis[z] < dis[u])
			z = u;
	if (dis[z] + 1 < n / k)
		return;
	cout << "PATH" << endl;
	cout << dis[z] + 1 << endl;
	while (z != w){
		cout << z << " ";
		z = par2[z];
	}
	cout << w << endl;
	exit(0);
}

void print_path(int v, int u){
	while (v != u){
		cout << v << " ";
		v = par[v];
	}
	cout << u << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	root = rand() % n + 1;
	dfs(root);
	perimeter();


	cout << "CYCLES" << endl;
	for (int v = 1; k > 0 and v <= n; v++){
		if (isleaf[v]){
			k --;
			int fi = g[v][0], se = g[v][1];
			if (fi == par[v])
				fi = g[v][2];
			if (se == par[v])
				se = g[v][2];
			if (h[fi] > h[se])
				swap(fi, se);
		
			if ((h[v] - h[fi] + 1) % 3 != 0){
				cout << h[v] - h[fi] + 1 << endl;
				print_path(v, fi);
			}
			else if ((h[v] - h[se] + 1) % 3 != 0){
				cout << h[v] - h[se] + 1 << endl;
				print_path(v, se);
			}
			else{
				cout << h[se] - h[fi] + 2 << endl;
				cout << v << " ";
				print_path(se, fi);
			}
		}
	}
}