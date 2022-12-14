/**
 *    author:  Atreus
 *    created: 03.02.2019 12:55
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 500 + 10;
int adj[maxn][maxn], h[maxn];
int n;
void dfs(int v){
	for (int u = 1; u <= n; u++){
		if (u != v and adj[v][u] == 0){
			if (h[u] == -1){
				h[u] = h[v] + 1;
				dfs(u);
			}
			if (h[u] % 2 == h[v] % 2){
				cout << "No" << endl;
				exit(0);
			}
		}
	}
}

int deg[maxn];
char c[maxn];
int main(){
	ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		adj[v][u] = 1;
		adj[u][v] = 1;
		deg[v] ++;
		deg[u] ++;
	}
	memset(h, -1, sizeof h);
	for (int v = 1; v <= n; v++){
		if (deg[v] == n - 1)
			c[v] = 'b';
		else{
			if (h[v] == -1){
				h[v] = 0;
				dfs(v);
			}
			if (h[v] & 1)
				c[v] = 'a';
			else
				c[v] = 'c';
		}
	}
	for (int v = 1; v <= n; v++){
		for (int u = v + 1; u <= n; u++){
			if (abs(c[v] - c[u]) <= 1){
				m --;
			}
		}
	}
	if (m != 0)
		return cout << "No" << endl, 0;
	cout << "Yes\n";
	for (int v = 1; v <= n; v++){
		cout << c[v];
	}
	cout << endl;
}