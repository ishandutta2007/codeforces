#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

vector<int> u;
vector<vector<int>> edge;

long long ans = 0;
int k;

long long dfs(int v, int p) {
	long long c = u[v];
	for (int i = 0; i < edge[v].size(); ++i)
		if (edge[v][i] != p) {
			long long x = dfs(edge[v][i], v);
			c += x;
			ans += min(x, (long long)2 * k - x);
		}
	return c;
}

int main() {
	int n;
	cin >> n >> k;
	edge.resize(n);
	u.resize(n);

	for (int i = 0; i < 2 * k; ++i) {
		int c;
		cin >> c;
		u[c - 1] = 1;
	}

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	dfs(0, - 1);

	cout << ans << endl;
	return 0;
}