#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 2e5, mod = 1e9 + 7;

int n, a[maxn], ev[maxn], od[maxn];
vector<int> g[maxn];

void dfs1(int v, int p) {
	for(int to : g[v]) {
		if(to == p) continue;
		dfs1(to, v);
		ev[v] += od[to];
		od[v] += ev[to] + 1;
	}
}

ll ans;

void dfs2(int v, int p, int evup, int odup) {
	for(int i = 0; i < sz(g[v]); i++)
		if(g[v][i] == p) {
			g[v].erase(g[v].begin() + i);
			break;
		}
	ans = (ans + ll(n) * (a[v] % mod + mod)) % mod;
	for(int to : g[v]) {
		ans = (ans + (a[v] % mod + mod) * ll(od[to]) % mod * (n - 1 - ev[to] - od[to])) % mod;
		ans = (ans + (-a[v] % mod + mod) * ll(ev[to] + 1) % mod * (n - 1 - ev[to] - od[to])) % mod;
	}
	ans = (ans + (a[v] % mod + mod) * ll(evup) % mod * (n - evup - odup)) % mod;
	ans = (ans + (-a[v] % mod + mod) * ll(odup) % mod * (n - evup - odup)) % mod;
	if(!sz(g[v])) return;
	int totev = 0, totod = 0;
	for(int to : g[v]) {
		totev += ev[to] + 1;
		totod += od[to];
	}
	swap(evup, odup);
	odup++;
	for(int to : g[v]) {
		dfs2(to, v, evup + totev - ev[to] - 1, odup + totod - od[to]);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v); g[v].push_back(u);
	}
	dfs1(0, -1);
	dfs2(0, -1, 0, 0);
	cout << ans;
}