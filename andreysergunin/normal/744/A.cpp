#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<vector<int>> g;
vector<int> vis;

int dfs(int v) {
	vis[v] = 1;
	int ans = 1;
	for (auto u : g[v]) {
		if (!vis[u])
			ans += dfs(u);
	}
	return ans;
}

int main() {
	
	int n, m, k;
	cin >> n >> m >> k;
	g.resize(n);
	vector<int> c(k);
	for (int i = 0; i < k; ++i) {
		cin >> c[i];
		--c[i];
	}


	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	vector<int> w(k);
	vis.resize(n);
	for (int i = 0; i < k; ++i) {
		w[i] = dfs(c[i]);
	}

	int l = 0;
	int s = 0;
	for (int i = 0; i < k; ++i) {
		s += w[i];
		if (w[i] > w[l])
			l = i;
	}


	w[l] += n - s;

	ll ans = 0;
	for (int i = 0; i < k; ++i)
		ans += (ll)w[i] * (ll)(w[i] - 1) / 2;

	ans -= m;

	cout << ans << endl;

	return 0;
}