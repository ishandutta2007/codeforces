#include <bits/stdc++.h>
using namespace std;

const int N = 10 * 1000 + 5, inf = 1000 * 1000 * 1000 + 7;
int n, m, k, s1, s2, t;

vector <pair <int, int> > adj[N];
vector <pair <int, int> > adj2[N];
int l[N], r[N];
long long d1[N], d2[N];
bool mark[N];


set <pair <int, int> > s;

void dij(int st, long long* d) {
	fill(d, d + n + 1, 1ll * inf * N);
	d[st] = 0;
	s.insert({0, st});
	while (s.size()) {
		int v = (*s.begin()).second;
		s.erase(s.begin());
		for (auto p : adj[v]) {
			int u = p.first, w = p.second;
			if (d[v] + w < d[u]) {
				s.erase({d[u], u});
				d[u] = d[v] + w;
				s.insert({d[u], u});
			}
		}
		for (auto p : adj2[v]) {
			int u = p.first, w = r[p.second];
			if (mark[p.second]) {
				w = l[p.second];
			}
			if (d[v] + w < d[u]) {
				s.erase({d[u], u});
				d[u] = d[v] + w;
				s.insert({d[u], u});
			}		
		}
	}
}

int main() {
	cin >> n >> m >> k >> s1 >> s2 >> t;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v >> l[i] >> r[i];
		adj2[u].push_back({v, i});
	}
	for (int ii = 0; ii < k; ii++) {
		dij(s1, d1);
		dij(s2, d2);
	//	for (int i = 1; i <= n; i++) {
	//		cout << "73 " << i << " " << d1[i] << " " << d2[i] << endl;
	//	}
		for (int i = 1; i <= n; i++) {
			if (d1[i] < d2[i]) {
				for (auto p : adj2[i]) {
					mark[p.second] = true;
				}
			}
		}
	}
	if (d1[t] > d2[t]) {
		cout << "LOSE";
	}
	else {
		if (d1[t] == d2[t]) {
			cout << "DRAW\n";
		}
		else {
			cout << "WIN\n";
		}
		for (int i = 0; i < k; i++) {
			if (mark[i]) {
				cout << l[i] << endl;
			}
			else {
				cout << r[i] << endl;
			}
		}
	}
	return 0;
}