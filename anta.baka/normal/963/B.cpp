#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
//#define int long long
const int maxn = 2e5, mod = 1e9 + 9;

int n, par[maxn];
vector<int> g[maxn], ord;

void dfs1(int v) {
	par[v] ^= 1;
	ord.push_back(v);
	for(int to : g[v]) {
		if(par[to] & 1) dfs1(to);
	}
}

void dfs(int v, int p) {
	for(int to : g[v]) {
		if(to != p) dfs(to, v);
	}
	if(!par[v]) {
		ord.push_back(v);
		for(int to : g[v]) {
			if(to != p && par[to]) dfs1(to);
		}
		if(p != -1) par[p] ^= 1;
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		int v; cin >> v; v--;
		if(v != -1) {
			g[i].push_back(v);
			g[v].push_back(i);
		}
	}
	for(int i = 0; i < n; i++) par[i] = (sz(g[i]) & 1);
	dfs(0, -1);
	if(sz(ord) != n) cout << "NO";
	else {
		cout << "YES\n";
		for(int v : ord) cout << v + 1 << '\n';
	}
}