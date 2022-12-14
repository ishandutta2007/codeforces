#include <bits/stdc++.h>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int maxn = 3e5 + 4;
int n, m, k;
ll dp[maxn], par[maxn];
vector <pair <pii, int> > g[maxn];

void dijkstra (int v) {
	memset (dp, 63, sizeof dp);
	dp[v] = 0;
	set <pair <ll, int> > s;
	for (int i = 1; i <= n; i++)
		s.insert ({dp[v], v});
	while (!s.empty()) {
		if (k == 0)
			exit (0);
		auto it = s.begin();
		s.erase (s.begin());
		v = (*it).S;
		if (par[v] != 0) {
			cout << par[v] << " ";
			k --;
		}
		for (auto e : g[v]) {
			int u = e.F.F, w = e.F.S;
			if (dp[u] > dp[v] + w) {
				s.erase ({dp[u], u});
				dp[u] = dp[v] + w;
				s.insert ({dp[u], u});
				par[u] = e.S;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio (false);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int v, u, w;
		cin >> v >> u >> w;
		g[v].PB ({{u, w}, i});
		g[u].PB ({{v, w}, i});
	}
	cout << min (k, n - 1) << endl;
	dijkstra (1);
}