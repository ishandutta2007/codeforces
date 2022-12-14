#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5000 + 5;

vector<pair<int,int> > t[maxn];
int par[maxn], paredge[maxn], h[maxn];
int a[maxn], b[maxn], g[maxn];
int f[maxn];

void dfs(int v, int p = -1){
	for (auto edge : t[v]){
		int u = edge.first, idx = edge.second;
		if (u == p)
			continue;
		h[u] = h[v] + 1;
		paredge[u] = idx;
		par[u] = v;
		dfs(u, v);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back({u, i});
		t[u].push_back({v, i});
	}
	par[1] = -1;
	dfs(1);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++){
		cin >> a[i] >> b[i] >> g[i];
		int v = a[i], u = b[i];
		while (v != u){
			if (h[v] < h[u])
				swap(v, u);
			int idx = paredge[v];
			f[idx] = max(f[idx], g[i]);
			v = par[v];
		}
	}

	for (int i = 0; i < q; i++){
		int v = a[i], u = b[i], x = 1e9;
		while (v != u){
			if (h[v] < h[u])
				swap(v, u);
			int idx = paredge[v];
			x = min(x, f[idx]);
			v = par[v];
		}
		if (x != g[i])
			return cout << -1 << '\n', 0;
	}
	for (int i = 0; i < n - 1; i++)
		cout << max(1, f[i]) << " ";
	cout << '\n';
}