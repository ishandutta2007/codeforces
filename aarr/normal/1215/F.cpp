#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1600 * 1000 + 73;
int n, p, q, m, s, t;

vector <int> adj[N], adjr[N], inc[N], vec, ans;
int l[N], r[N];
bool mark[N], b[N];
int part[N];

int nt(int v) {
	if (v >= s) {
		v -= s;
	}
	else {
		v += s;
	}
	return v;
}

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
	cin >> n >> p >> q >> m;
	s = p + q + 2;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[nt(u)].push_back(v);
		adj[nt(v)].push_back(u);
	}
	for (int i = 0; i < p; i++) {
		cin >> l[i] >> r[i];
		int u = l[i] + p - 1, v = r[i] + p;
		adj[i].push_back(nt(v));
		adj[v].push_back(nt(i));
		adj[i].push_back(u);
		adj[nt(u)].push_back(nt(i));
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(nt(v));
		adj[v].push_back(nt(u));
	}
	for (int i = 0; i <= q; i++) {
		int u = i + p, v = i + p + 1;
		adj[nt(u)].push_back(nt(v));
		adj[v].push_back(u);
	}
	for (int i = 0; i < 2 * s; i++) {
		if (!mark[i]) {
			dfs(i);
		}
		for (auto u : adj[i]) {
			adjr[u].push_back(i);
		}
	}
	reverse(vec.begin(), vec.end());
	for (auto v : vec) {
		if (!part[v]) {
			t++;
			part[v] = t;
			dfsr(v);
		}
	}
	for (int i = 0; i < 2 * s; i++) {
		if (part[i] == part[nt(i)]) {
			cout << -1;
			return 0;
		}
		inc[part[i]].push_back(i);
	}
	int f = q;
	for (int i = 1; i <= t; i++) {
		for (auto u : inc[i]) {
			if (!b[nt(u)]) {
				b[u] = true;
			}
			if (u < p && !b[u]) {
				ans.push_back(u);
				f = min(f, r[u]);
			}
		}
	}
//	for (int i = 0; i < 2 * s; i++) {
//		cout << "73 " << i << " " << b[i] << " " << part[i] << endl;
//	}
	cout << ans.size() << " " << f << endl;
	for (auto u : ans) {
		cout << u + 1 << " ";
	}
	return 0;
}