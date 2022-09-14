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
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

const ll INF = 1e9 + 10;

vector<vector<int>> g;
vector<vector<int>> cost;
vector<int> col;

bool ok = true;

void dfs(int v, int c) {
	col[v] = c;
	for (int i = 0; i < sz(g[v]); ++i) {
		int u = g[v][i];
		if (col[u] == -1) {
			dfs(u, (col[v] + cost[v][i]) & 1);
		} else {
			if ((col[u] + col[v] + cost[v][i]) & 1) {
				ok = false;
			}
		}

	}
}

int main() {
	// freopen("arithmetic.in", "r", stdin);
	// freopen("arithmetic.out", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> r(n);
	for (int i = 0; i < n; ++i) {
		cin >> r[i];
		r[i] = !r[i];
	}

	vector<vector<int>> gg(n);
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int u;
			cin >> u;
			--u;
			gg[u].push_back(i);
		}
	}

	g.resize(m);
	cost.resize(m);
	for (int i = 0; i < n; ++i) {
		g[gg[i][0]].push_back(gg[i][1]);
		cost[gg[i][0]].push_back(r[i]);
		g[gg[i][1]].push_back(gg[i][0]);
		cost[gg[i][1]].push_back(r[i]);
	}

	col.resize(m, - 1);
	for (int i = 0; i < m; ++i) {
		if (col[i] == -1) {
			dfs(i, 1);
		}
	}

	cout << (ok ? "YES" : "NO") << endl;


}