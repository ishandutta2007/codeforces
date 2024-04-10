#include <iostream>
#include <set>
#include <vector>
using namespace std;
 
const int N = 50 * 1000 + 5, Q = 250 * 1000 + 5, SQ = 305;
 
set <int> adj[N];
int mark[N];
int pos[N];
int cnt[N];
int md[N];
vector <pair <int, int> > vec;
vector <pair <char, pair <int, int> > > qs;
vector <int> big;
bool b[N][5 * SQ + 10];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	int x;
	cin >> x;
	for (int i = 0; i < x; i++) {
		int v;
		cin >> v;
		mark[v] = 1;
	//	b[v] = true;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		md[u]++;
		md[v]++;
		adj[u].insert(v);
		adj[v].insert(u);
	}
/*	for (int i = 1; i <= n; i++) {
		for (auto u : adj[i]) {
			if (mark[u]) {
				cnt[i]++;
			}
		}
	//	cout << "47 " << i << " " << cnt[i] << endl;
	}*/
	for (int i = 0; i < q; i++) {
		char c;
		cin >> c;
		if (c == 'A') {
			int u, v;
			cin >> u >> v;
			md[u]++;
			md[v]++;
			qs.push_back({c, {v, u}});
		}
		if (c == 'D') {
			int u, v;
			cin >> u >> v;
			qs.push_back({c, {v, u}});
		}
		if (c == 'O') {
			int v;
			cin >> v;
			qs.push_back({c, {v, v}});
		}
		if (c == 'F') {
			int v;
			cin >> v;
			qs.push_back({c, {v, v}});
		}
		if (c == 'C') {
			int v;
			cin >> v;
			qs.push_back({c, {v, v}});
		}
	//	cout << "73 " << i << endl;
	}
	for (int i = 1; i <= n; i++) {
		if (md[i] > SQ) {
			pos[i] = (int) big.size();
			big.push_back(i);
			for (auto u : adj[i]) {
			//	cout << "73 " << i << " " << u << endl;
				b[u][pos[i]] = true;
			}
		}
		for (auto u : adj[i]) {
			if (md[u] <= SQ) {
				cnt[i] += mark[u];
			}
		}
	}
//	cout << big.size() << endl;
	for (auto p : qs) {
		char c = p.first;
		int v = p.second.first, u = p.second.second;
		if (c == 'A') {
			if (md[u] <= SQ) {
				cnt[v] += mark[u];
			}
			else {
				b[v][pos[u]] = true;
			}
			if (md[v] <= SQ) {
				cnt[u] += mark[v];
			}
			else {
				b[u][pos[v]] = true;
			}
			adj[v].insert(u);
			adj[u].insert(v);
		}
		if (c == 'D') {
			if (md[u] <= SQ) {
				cnt[v] -= mark[u];
			}
			else {
				b[v][pos[u]] = false;
			}
			if (md[v] <= SQ) {
				cnt[u] -= mark[v];
			}
			else {
				b[u][pos[v]] = false;
			}
			adj[v].erase(u);
			adj[u].erase(v);
		}
		if (c == 'O') {
			mark[v] = 1;
			if (md[v] <= SQ) {
				for (auto u : adj[v]) {
					cnt[u]++;
				}
			}
		}
		if (c == 'F') {
			mark[v] = 0;
			if (md[v] <= SQ) {
				for (auto u : adj[v]) {
					cnt[u]--;
				}
			}
		}
		if (c == 'C') {
			int ans = cnt[v];
			for (int j = 0; j < big.size(); j++) {
				int u = big[j];
			//	cout << v << " " << j << " " << u << " " << b[v][j] << endl;
				if (mark[u] && b[v][j]) {
					ans++;
				}
			}
			cout << ans << '\n';
		}
	//	cout << "73 " << i << endl;
	}
	return 0;
}