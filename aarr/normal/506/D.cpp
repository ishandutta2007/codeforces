#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int N = 100 * 1000 + 5, SQ = 257;
int nparts = 0;

map <pair <int, int>, vector <int> > adj;
map <pair <int, int>, bool> mark;
pair < pair <int, int>, int> inc[N];
//vector <int> parts[N];
vector <int> in[N];
pair <int, int> ss[N];
int pos[N];
int b[SQ + 5][N];
int itr[SQ + 5][N];


void dfs(int v, int c) {
	mark[{v, c}] = true;
	in[v].push_back(nparts);
	for (auto u : adj[{v, c}]) {
		if (!mark[{u, c}]) {
			dfs(u, c);
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		inc[i] = {{u, v}, c};
		adj[{u, c}].push_back(v);
		adj[{v, c}].push_back(u);
	}
//	cout << 41 << endl;
	for (int i = 0; i < m; i++) {
		int u = inc[i].first.first, v = inc[i].first.second, c = inc[i].second;
		if (!mark[{u, c}]) {
			nparts++;
			dfs(u, c);
		}
	}
//	cout << 42 << endl;
	for (int i = 1; i <= n; i++) {
		ss[i] = {-in[i].size(), i};
	}
	sort(ss + 1, ss + n + 1);
	for (int i = 1; i <= n; i++) {
		pos[ss[i].second] = i;
	}
//	cout << 43 << endl;
	for (int i = 1; i <= n && i <= SQ; i++) {
		for (auto x : in[ss[i].second]) {
			b[i][x]++;
		}
	}
//	cout << 44 << endl;
	for (int i = 1; i <= n && i <= SQ; i++) {
		for (int j = 1; j <= n; j++) {
			for (auto x : in[ss[j].second]) {
				itr[i][j] += b[i][x];
			}
		}
	}
//	cout << 45 << endl;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		if (pos[u] > pos[v]) {
			swap(u, v);
		}
		if (pos[u] <= SQ) {
			cout << itr[pos[u]][pos[v]] << endl;
		}
		else {
			int p1 = 0, p2 = 0, ans = 0;
			while (p1 < in[u].size() && p2 < in[v].size()) {
				if (in[u][p1] < in[v][p2]) {
					p1++;
				}
				else {
					if (in[v][p2] < in[u][p1]) {
						p2++;
					}
					else {
						p1++;
						p2++;
						ans++;
					}
				}
				
			}
			cout << ans << endl;
		}
	}
	return 0;
}