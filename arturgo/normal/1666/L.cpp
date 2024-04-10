#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[200 * 1000];

int colors[200 * 1000];
int parents[200 * 1000];

int s;

void dfs(int u, int c, int p) {
	if(u == s) return;
	if(colors[u] == c) return;
	if(colors[u] != 0) { 
		//truc spcial
		cout << "Possible" << endl;
		
		vector<int> path1, path2;
		
		int x = u;
		while(x != -1) {
			path1.push_back(x);
			x = parents[x];
		}
		
		path2.push_back(u);
		int y = p;
		while(y != -1) {
			path2.push_back(y);
			y = parents[y];
		}
		
		reverse(path1.begin(), path1.end());
		reverse(path2.begin(), path2.end());
		cout << path1.size() << endl;
		for(int x : path1) cout << 1 + x << " ";
		cout << endl << path2.size() << endl;
		for(int y : path2) cout << 1 + y << " ";
		cout << endl;
		
		exit(0);
	}
	
	parents[u] = p;
	colors[u] = c;
	
	for(int v : adj[u]) {
		dfs(v, c, u);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m >> s;
	s--;
	
	for(int i = 0;i < m;i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
	}
	
	parents[s] = -1;
	for(int v : adj[s]) {
		dfs(v, 1 + v, s);
	}
	
	cout << "Impossible" << endl;
	return 0;
}