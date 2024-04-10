#include <bits/stdc++.h>

using namespace std;

int n, a[200000], ans[200000], cnt[200001];
vector<int> g[200000], del[200001];

void dfs(int v, int p, int len, int gcd) {
	ans[v] = gcd;
	for(int x : del[a[v]]) {
		cnt[x]++;
		if(cnt[x] >= len - 1) ans[v] = max(ans[v], x);
	}
	for(int to : g[v])
		if(to != p)
			dfs(to, v, len + 1, __gcd(gcd, a[v]));
	for(int x : del[a[v]]) cnt[x]--;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for(int i = 1; i <= 200000; i++)
		for(int j = i; j <= 200000; j += i) del[j].push_back(i);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, -1, 1, 0);
	for(int i = 0; i < n; i++) cout << ans[i] << ' ';
}