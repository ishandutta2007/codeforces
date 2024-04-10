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
#include <string.h>
#include <assert.h>
#include <complex>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
mt19937 rr(random_device{}());

vector<vector<int>> g;
vector<int> vis;

void dfs(int v) {
	vis[v] = 1;
	for (int u : g[v]) {
		if (!vis[u])
			dfs(u);
	}
}

int main() {
	// freopen("input.txt", "r", stdin);
	
	int n;
	cin >> n;
	vector<int> p(n);
	g.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		--p[i];
		g[i].push_back(p[i]);
		g[p[i]].push_back(i);
	}

	vis.resize(n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			dfs(i);
			++ans;
		}
	}

	cout << ans << endl;

		
	return 0;
}