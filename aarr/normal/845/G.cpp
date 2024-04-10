#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 5, LG = 30;

vector <pair <int, int> > adj[N];
int h[N];
int a[LG];
int par[N][LG];
int z[N][LG];
bool mark[N];
int pth = 0;

int get(int x, int y) {
	return (x >> y) & 1;
}

void add(int x) {
	for (int i = LG - 1; i >= 0; i--) {
		if (get(x, i)) {
			if (!a[i]) {
				a[i] = x;
				break;
			}
			else {
				x ^= a[i];
			}
		}
	}
}

bool dfs(int v) {
	bool b = false;
	mark[v] = true;
	for (auto p : adj[v]) {
		int u = p.first, w = p.second;
		if (!mark[u]) {
			h[u] = h[v] + 1;
			par[u][0] = v;
			z[u][0] = w;
			for (int i = 1; i < LG; i++) {
				par[u][i] = par[par[u][i - 1]][i - 1];
				z[u][i] = z[u][i - 1] ^ z[par[u][i - 1]][i - 1];
			}	
			if (dfs(u)) {
				b = true;
				pth ^= w;
			}
			
		}
		else {
			if (h[u] > h[v]) {
				continue;
			}
			int k = w;
			int x = v;
			for (int i = LG - 1; i >= 0; i--) {
				if (h[x] - (1 << i) >= h[u]) {
					k ^= z[x][i];
					x = par[x][i];
				}
			}
		//	cout << "72 " << v << " " << u << " " << k << endl;
			add(k);
		}
	}
	
	
	
	if (v == 1 || b) {
		return true;
	}
	return false;
}


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	for (int i = 0; i < LG; i++) {
		par[n][i] = n;
	}
	dfs(n);
//	cout << "75 " << pth << endl;
	int ans = pth;
	for (int i = LG - 1; i >= 0; i--) {
		ans = min(ans, ans ^ a[i]);
	}
	cout << ans;
	
	return 0;
}