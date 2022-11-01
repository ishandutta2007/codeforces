#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <map>
#include <iomanip>
#include <numeric>

#define sz(a) (int)((a).size())
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = long long;
using vi = vector<int>;

const int N = 200;
const int inf = 5e8 + 228;

struct Edge {
	int u, v, w;
};

int n, m;
int d[N][N];
vector<Edge> es;
vi ord[N];

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = (i != j) * inf;
		}
	}
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		d[u][v] = d[v][u] = w;
		es.pb({ u, v, w });
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		ord[i].resize(n);
		iota(all(ord[i]), 0);
		sort(all(ord[i]), [&](int u, int v) { return d[i][u] < d[i][v]; });
	}
	int ans = inf;
	for (auto e : es) {
		int mx = 0;
		for (int i = n - 1; i >= 0; i--) {
			int cur = d[e.u][ord[e.u][i]] + e.w + mx;
			if (2 * d[e.u][ord[e.u][i]] <= cur && 2 * mx <= cur && cur < ans) {
				ans = cur;
			}
			mx = max(mx, d[e.v][ord[e.u][i]]);
		}
	}
	cout.precision(10);
	cout << fixed << 0.5 * ans;
}