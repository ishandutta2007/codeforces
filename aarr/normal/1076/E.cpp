#include <iostream>
#include <vector>
using namespace std;

const int N = 300 * 1000 + 5;

vector <int> adj[N];
vector <pair <int, int> > t[N];
int h;
long long sm, a[N], ans[N];
bool mark[N];


void dfs(int v) {
	mark[v] = true;
	for (auto p : t[v]) {
		sm += p.second;
		a[min(h + p.first, N - 1)] += p.second;
	}
	ans[v] = sm;
//	cout << "73 " << v << " " << h << " " << sm << endl;
	sm -= a[h];
	h++;
	for (auto u : adj[v]) {
		if (!mark[u]) {
			dfs(u);
		}
	}
	h--;
	sm += a[h];
//	cout << "48 " << v << " " << h << " " << sm << endl;
	for (auto p : t[v]) {
		sm -= p.second;
		a[min(h + p.first, N - 1)] -= p.second;
	}
	
}
int main() {
	ios :: sync_with_stdio(false);
	int n, q;
	cin >> n;	
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int v, d, x;
		cin >> v >> d >> x;
		t[v].push_back({d, x});
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}