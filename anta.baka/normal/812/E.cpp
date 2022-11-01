/*






  










*/

#include <bits/stdc++.h>

using namespace std;

#define int long long 

int n, a[100000];
vector<int> g[100000];
map<int,int> cnt;
int xr;
vector<bool> blue;
int cblue;
int ans;

int dfs(int v) {
	if(g[v].empty()) { xr ^= a[v]; return 1; }
	int parity;
	for(int to : g[v]) parity = !dfs(to);
	if(parity) xr ^= a[v];
	else cnt[a[v]]++, blue[v] = false, --cblue;
	return parity;
}

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 1; i < n; i++) {
		int p; cin >> p; --p;
		g[p].push_back(i);
	}
	blue.assign(n, true);
	cblue = n;
	dfs(0);
	for(int i = 0; i < n; i++) if(blue[i]) ans += cnt[xr ^ a[i]];
	if(!xr) ans += cblue * (cblue - 1) / 2 + (n - cblue) * (n - cblue - 1) / 2;
	cout << ans;
}