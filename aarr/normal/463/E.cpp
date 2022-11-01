#include <iostream>
#include <vector>
using namespace std;

const int N = 200 * 1000 + 5, A = 2000 * 1000 + 5;
int n, q;

vector <int> adj[N];
vector <int> p[A];
int a[N];
int h[N];
vector <int> vec[A];
bool mark[N];
int ans[N];

void dfs(int v) {
	mark[v] = true;
//	ans[v] = -1;
	for (auto x : p[a[v]]) {
		if (vec[x].size()) {
			int f = vec[x].back();
			if (h[f] > h[ans[v]])
				ans[v] = f;
		}
		vec[x].push_back(v);
	}
	for (auto u : adj[v]) {
		if (!mark[u]) {
			h[u] = h[v] + 1;
			dfs(u);
		}
	}
	for (auto x : p[a[v]]) {
		vec[x].pop_back();
	}
}

void build() {
	fill(mark, mark + n + 1, false);
	fill(ans, ans + n + 1, 0);
	h[1] = 1;
	dfs(1);
}

int main() {
	h[0] = -1;
	ios :: sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 2; i < A; i++) {
		if (p[i].size() == 0) {
			for (int j = i; j < A; j += i) {
				p[j].push_back(i);
			}
		}
	/*	if (i < 20) {
			for (auto k : p[i]) {
				cout << "71 " << i << " " << k << endl;
			}
		}*/
	}
	build();
//	build();
	for (int i = 0; i < q; i++) {
		int qt, v;
		cin >> qt >> v;
	//	if (n > 4)
	//	cout << "72 " << qt << " " << v << " " << h[v] << " " << a[v] << " " << ans[v] << " " << a[ans[v]] << endl;
		if (qt == 1) {
			if (ans[v] == 0)
				ans[v]--;
			cout << ans[v] << '\n';
		}
		else {
			cin >> a[v];
			build();
		}
	}
	
	return 0;
}