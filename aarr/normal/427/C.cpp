#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1000 * 1000 + 5, mod = 1000 * 1000 * 1000 + 7;
int t = 0;

vector <int> adj[N];
vector <int> adjr[N];
vector <int> vec;
int a[N];
int part[N];
bool mark[N];
int mn[N];
int cnt[N];

void dfs(int v) {
	mark[v] = true;
	for (auto u : adj[v]) {
		if (!mark[u]) {
			dfs(u);
		}
	}
	vec.push_back(v);
}

void dfsr(int v) {
	for (auto u : adjr[v]) {
		if (!part[u]) {
			part[u] = part[v];
			dfsr(u);
		}
	}
}

int main() {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v;
		adj[u].push_back(v);
		adjr[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!mark[i]) {
			dfs(i);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		int v = vec[i];
		if (!part[v]) {
			t++;
			part[v] = t;
			dfsr(v);
		}
	}
//	cout << 41 << endl;
//	for (int i = 1; i <= n; i++) {
//		cout << part[i] << " ";
//	}
	fill(mn + 1, mn + t + 1, mod);
	for (int i = 1; i <= n; i++) {
		if (a[i] < mn[part[i]]) {
			mn[part[i]] = a[i];
			cnt[part[i]] = 0;
		}
		if (a[i] == mn[part[i]]) {
			cnt[part[i]]++;
		}
	}
	long long ans1 = 0, ans2 = 1;
	for (int i = 1; i <= t; i++) {
		ans1 += mn[i];
		ans2 *= cnt[i];
		ans2 %= mod;
	}
	cout << ans1 << " " << ans2;
	return 0; 
}