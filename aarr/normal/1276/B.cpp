#include <iostream>
#include <vector>
using namespace std;

int n, m, a, b, p;
const int N = 200 * 1000 + 5;

int part[N];
bool mark1[N];
bool mark2[N];
vector <int> adj[N];


void dfs(int v) {
	for (auto u : adj[v]) {
		if (part[u] == 0 && u != a && u != b) { 
			part[u] = part[v];
			dfs(u);
		}
	}
}
int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		cin >> n >> m >> a >> b;
		for (int i = 1; i <= n; i++) {
			part[i] = 0;
			mark1[i] = false;
			mark2[i] = false;
			adj[i].clear();
		}
		p = 0;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) {
			if (i != a && i != b && part[i] == 0) {
				p++;
				part[i] = p;
				dfs(i);
			}
		//	cout << "73 " << part[i] << endl;
		}
		for (auto u : adj[a]) {
			mark1[part[u]] = true;
		}
		for (auto u : adj[b]) {
			mark2[part[u]] = true;
		}
		int x = 0, y = 0;
		for (int i = 1; i <= n; i++) {
			if (i == a || i == b) {
				continue;
			}
		//	cout << "49 " << part[i] << " " << mark1[part[i]] << endl;
			if (!mark1[part[i]]) {
				x++;
			}
			if (!mark2[part[i]]) {
				y++;
			}
		}
	//	x -= 2;
	//	y -= 2;
		cout << 1ll * x * y << endl;
	}
	return 0;
}