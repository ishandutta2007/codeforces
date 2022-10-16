#include "bits/stdc++.h"
using namespace std;

#define pb push_back

int c[2*100010];

vector <int> adj[2*100010];

int mx = 1;

void dfs(int i, int par){
	int col = 1;
	for(auto j: adj[i]){
		if(j==par) continue;
		while(col==c[par] or col==c[i]) col++;
		c[j] = col++;
		dfs(j,i);
	}
	mx = max(mx, col-1);
}

main(){
	int n;
	cin >> n;
	for(int i = 1, x, y; i < n; i++){
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	c[1] = 1;
	dfs(1,0);
	cout << mx << endl;
	for(int i = 1; i <=n; i++) cout << c[i] << ' ';
}