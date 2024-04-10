#include <bits/stdc++.h>
using namespace std;

const int N = 200 * 1000 + 5;

bool mark1[N];
bool mark2[N];
vector <int> adj[N], adjr[N], vec1;
int o[N];
string s;

void dfs(int v) {
	if (mark1[v]) {
		return;
	}
	mark1[v] = true;
	for (auto u : adj[v]) {
		dfs(u);
	}
	vec1.push_back(v);
	o[v] = vec1.size();
}

void dfsr(int v) {
	if (mark2[v]) {
		return;
	}
	mark2[v] = true;
	for (auto u : adjr[v]) {
		dfsr(u);
	}
}

int main() {
	ios :: sync_with_stdio(false);
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adjr[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!mark1[i] && !mark2[i]) {
			ans++;
			s += 'A';
		}
		else {
			s += 'E';
		}
		dfs(i);
		dfsr(i);
	}
	for (int i = 1; i <= n; i++) {
		for (auto u : adj[i]) {
			if (o[u] > o[i]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans << endl;
	cout << s;
	return 0;
}