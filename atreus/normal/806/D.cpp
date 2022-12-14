/**
 *    author:  Atrues
 *    created: 28.01.2019 14:27
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2000 + 5;
int n;
ll dis[maxn];
bool mark[maxn], good[maxn];
int adj[maxn][maxn];

void dijkstra(){
	for (int _ = 1; _ <= n; _++){
		int v = -1;
		for (int u = 1; u <= n; u++)
			if (!mark[u] and (v == -1 or dis[v] > dis[u]))
				v = u;
		mark[v] = 1;
		for (int u = 1; u <= n; u++)
			dis[u] = min(dis[u], dis[v] + adj[v][u]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	int mnm = 1e9;
	for (int v = 1; v <= n; v++){
		for (int u = 1; u <= n - v; u++){
			cin >> adj[v][v + u];
			mnm = min(mnm, adj[v][v + u]);
			adj[v + u][v] = adj[v][v + u];
		}
	}
	memset(dis, 63, sizeof dis);
	for (int v = 1; v <= n; v++){
		for (int u = 1; u <= n; u++){
			if (v == u)
				continue;
			adj[v][u] -= mnm;
			dis[v] = min(dis[v], 2ll * adj[v][u]);
		}
	}
	dijkstra();
	for (int v = 1; v <= n; v++)
		cout << 1ll * mnm * (n - 1) + dis[v] << '\n';
}