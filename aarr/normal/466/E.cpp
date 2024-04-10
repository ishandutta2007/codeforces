#include <iostream>
#include <vector>
using namespace std;



const int N = 100 * 1000 + 5, LG = 20;

vector <pair <int, int> > chld[N];
vector <pair < pair <int, int>, int> > q3;
vector <pair <int, int> > q2;
int par[N][LG], dp[N][LG];
int h[N], indeg[N];

void dfs(int v) {
	for (auto p : chld[v]) {
		int u = p.first, w = p.second;
		h[u] = h[v] + 1;
		par[u][0] = v;
		dp[u][0] = w;
		dfs(u);
	}
}

int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int u, v;
			cin >> u >> v;
			chld[v].push_back({u, i});
			indeg[u]++;
		}
		if (t == 2) {
			int v;
			cin >> v;
			q2.push_back({v, i});
		}
		if (t == 3) {
			int v, k;
			cin >> v >> k;
			k--;
			q3.push_back({{v, k}, i});
		}
	}
	for (int i = 1; i <= n; i++) {
		par[i][0] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (!indeg[i]) {
			dfs(i);
		}
	}
	for (int j = 1; j < LG; j++) {
		for (int i = 1; i <= n; i++) {
			int v = par[i][j - 1];
			par[i][j] = par[v][j - 1];
			dp[i][j] = max(dp[i][j - 1], dp[v][j - 1]);
		}
	}
//	for (int i = 1; i <= n; i++) {
//		cout << dp[i][0] << " ";
//	}
//	cout << endl;
	for (auto p : q3) {
		int u = p.first.first, k = p.first.second, s = p.second;
		int v = q2[k].first, mx = 0;
	//	cout << "72 " << k << " " << v << endl;
		for (int i = LG - 1; i >= 0; i--) {
			if (h[v] - (1 << i) >= h[u] && dp[v][i] < q2[k].second) {
				mx = max(mx, dp[v][i]);
				v = par[v][i];
			}
		}
	//	cout << "73 " << u << " " << v << " " << s << " " << mx << endl;
		if (u != v) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}
	return 0;
}