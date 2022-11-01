#include <bits/stdc++.h>
using namespace std;

int n, m, was[100000], d[100000];
vector<int> a[100000], g[100000], q, lo(100000, -100000), ans;

void dfs(int v) {
	was[v] = 1;
	for(int to : g[v])
		if(was[to] == 1) { cout << "No"; exit(0); }
		else if(was[to] == 0) dfs(to);
	was[v] = 2;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int l; cin >> l; a[i].resize(l);
		for(int j = 0; j < l; j++) cin >> a[i][j], a[i][j]--;
		if(i) {
			int l0 = a[i - 1].size(), p = -1;
			for(int j = 0; j < min(l0, l); j++)
				if(a[i - 1][j] != a[i][j]) {
					p = j; break;
				}
			if(p == -1 && l0 > l) return cout << "No", 0;
			if(p != -1) g[a[i - 1][p]].push_back(a[i][p]), d[a[i][p]]++;
		}
	}
	for(int i = 0; i < m; i++) if(!was[i]) dfs(i);
	for(int i = 0; i < m; i++) if(!d[i]) q.push_back(i);
	while(!q.empty()) {
		int v = q.back();
		q.pop_back();
		if(lo[v] > v) return cout << "No", 0;
		int z = v;
		if(v - 100000 >= lo[v]) {
			ans.push_back(v);
			z -= 100000;
		}
		for(int to : g[v]) {
			lo[to] = max(lo[to], z);
			if(--d[to] == 0)
				q.push_back(to);
		}
	}
	cout << "Yes\n" << ans.size() << '\n';
	for(int y : ans) cout << y + 1 << ' ';
}