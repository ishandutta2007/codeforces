#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int N = 100 * 1000 + 5;
int t;

int d1[N], d2[N], d3[N], part[N], sz[N], diam[N];
bool mark[N];
vector <int> adj[N], vec[N], cnt[N];
vector <long long> sm[N];
map <pair <int, int>, long double> mp;

int bfs(int v, int d[]) {
	d[v] = 0;
	queue <int> q;
	q.push(v);
	sz[part[v]] = 0;
	vec[part[v]].clear();
	while (q.size()) {
		int v = q.front();
		diam[part[v]] = max(diam[part[v]], d[v]);
		vec[part[v]].push_back(v);
		sz[part[v]]++;
		mark[v] = true;
		q.pop();
		for (auto u : adj[v]) {
			if (d[u] == N) {
				d[u] = d[v] + 1;
				part[u] = part[v];
				q.push(u);
			}
		}
		if (q.empty()) {
			return v;
		}
	}
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	fill(d1, d1 + n + 1, N);
	fill(d2, d2 + n + 1, N);
	fill(d3, d3 + n + 1, N);
	for (int i = 1; i <= n; i++) {
		if (!part[i]) {
			t++;
			part[i] = t;
			int v = bfs(i, d1);
			int u = bfs(v, d2);
			bfs(u, d3);
		}
	}
	for (int i = 1; i <= t; i++) {
		for (int j = 0; j <= sz[i]; j++) {
			sm[i].push_back(0);
			cnt[i].push_back(0);
		}
		for (auto x : vec[i]) {
			cnt[i][max(d2[x], d3[x])]++;
			sm[i][max(d2[x], d3[x])] += max(d2[x], d3[x]);
		}
		for (int j = 1; j < sm[i].size(); j++) {
			sm[i][j] += sm[i][j - 1];
			cnt[i][j] += cnt[i][j - 1];
		}
	}
	cout << fixed << setprecision(7);
	for (int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		u = part[u], v = part[v];
		if (u == v) {
			cout << "-1" << endl;
		}
		else {
			if (sz[u] > sz[v]) {
				swap(u, v);
			}
			if (mp[{u, v}] - 0 >= 0.0005) {
				cout << mp[{u, v}] << endl;
			}
			else {
				long double ans = 0;
				int k = max(diam[u], diam[v]);
			//	cout << "72 " << u << " " << v << " " << k << endl;
				for (auto x : vec[u]) {
					int ecc = max(d2[x], d3[x]);
					if (k == ecc) {
						ans += (long double) sm[v].back() / sz[u] / sz[v];
						ans += (long double) (k + 1) / sz[u];
				//		cout << "75\n";
					}
					else {
						int f;
						long long g;
						if (k - ecc - 1 < sm[v].size()) {
							f = cnt[v][k - ecc - 1];
							g = sm[v][k - ecc - 1];							
						}
						else {
							cout << "76\n";
							f = g = 0;
						}
						ans += (long double) f * k / sz[u] / sz[v];
						ans += (long double) (sz[v] - f) * (ecc + 1) / sz[u] / sz[v];
						ans += (long double) (sm[v].back() - g) / sz[u] / sz[v];
					}
				}
				mp[{u, v}] = ans;
				cout << ans << endl;
			}
		}
	}
	
	return 0;
}