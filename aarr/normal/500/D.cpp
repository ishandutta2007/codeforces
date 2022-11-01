#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5;
long double ans = 0;
long double t;
int n;

vector <pair <int, int> > adj[N];
int s[N];
int sz[N];
int a[N];

void dfs(int v) {
	sz[v] = 1;
	for (auto p : adj[v]) {
		int u = p.first, x = p.second;
		if (sz[u] == 0) {
			a[x] = u;
			dfs(u);
			sz[v] += sz[u];
			ans += (long double) sz[u] * (sz[u] - 1) * (n - sz[u]) / t * s[x];
			ans += (long double) sz[u] * (n - sz[u] - 1) * (n - sz[u]) / t * s[x];
		//	cout << "73 " << v << " " << u << " " << x << endl;
		}
	}
}

int main() {
	cin >> n;
	t = (long double) 1ll * n * (n - 1) * (n - 2) / 6;
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
		s[i] = w;
	}
	dfs(1);
	int q;
	cin >> q;
//	cout << ans << " " << t << endl;
	cout << fixed << setprecision(7);
	for (int i = 0; i < q; i++) {
		int x, w;
		cin >> x >> w;
		int u = a[x];
		ans += (long double) sz[u] * (sz[u] - 1) * (n - sz[u]) / t * (w - s[x]);
		ans += (long double) sz[u] * (n - sz[u] - 1) * (n - sz[u]) / t * (w - s[x]);
		s[x] = w;
		cout << ans << endl;		
	}
	return 0;
}