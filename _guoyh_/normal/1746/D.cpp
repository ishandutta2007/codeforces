# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200051;
int T, n;
ll k;
int fa[MAXN];
ll w[MAXN];
vector <int> g[MAXN];
ll f0[MAXN], f1[MAXN];
ll a[MAXN];
void dfs(int nw, ll k1){
	// cerr << "dfs " << nw << ' ' << k1 << '\n';
	for (int nxtn : g[nw]) dfs(nxtn, k1 / g[nw].size());
	int asz = 0;
	ll tol = 0;
	for (int nxtn : g[nw]){
		tol += f0[nxtn];
		a[++asz] = f1[nxtn] - f0[nxtn];
	}
	f0[nw] = f1[nw] = tol;
	f0[nw] += k1 * w[nw];
	f1[nw] += (k1 + 1) * w[nw];
	if (g[nw].size() == 0) return;
	sort(a + 1, a + asz + 1, [&](ll u, ll v){ return u > v; });
	for (int i = 1; i <= asz; i++){
		if (i <= k1 % g[nw].size()) f0[nw] += a[i];
		if (i <= k1 % g[nw].size() + 1) f1[nw] += a[i];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--){
		cin >> n >> k;
		for (int i = 2; i <= n; i++){
			cin >> fa[i];
			g[fa[i]].push_back(i);
		}
		for (int i = 1; i <= n; i++) cin >> w[i];
		dfs(1, k);
		cout << f0[1] << '\n';
		for (int i = 1; i <= n; i++) g[i].clear();
	}
	return 0;
}