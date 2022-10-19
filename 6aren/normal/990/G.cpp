#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, a[N], check[N];
vector<int> g[N], divv[N], needBFS[N];
queue<int> q;
long long ans[N];

int bfs(int u, int div) {
	int res = 1;
	q.push(u);
	check[u] = div;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto t : g[v]) {
			if (check[t] == div) continue;
			if (a[t] % div == 0) {
				res++;
				check[t] = div;
				q.push(t);
			}
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= 200000; i++) {
		for (int j = i; j <= 200000; j += i) {
			divv[j].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (auto u : divv[a[i]]) {
			needBFS[u].push_back(i);
		}
	}
	for (int i = 1; i <= 200000; i++) {
		for (auto u : needBFS[i]) {
			if (check[u] != i) {
				int z = bfs(u, i);
				ans[i] += 1ll * z * (z + 1) / 2;
			}
		}
	}
	for (int i = 200000; i > 0; i--) {
		for (int j = i + i; j <= 200000; j += i) {
			ans[i] -= ans[j];
		}
	}
	for (int i = 1; i <= 200000; i++) {
		if (ans[i]) cout << i << ' ' << ans[i] << '\n';
	}
	return 0;
}