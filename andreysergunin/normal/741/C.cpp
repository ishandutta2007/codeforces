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
typedef long double ld;

vector<int> res;
vector<vector<int>> g;


void dfs(int v, int c) {
	res[v] = c;
	for (auto u : g[v]) {
		if (res[u] == -1)
			dfs(u, 1 - c);
	}
}

int main() {

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector<int> u(n), v(n);
	g.resize(2 * n);

	for (int i = 0; i < n; ++i) {
		cin >> u[i] >> v[i];
		--u[i]; --v[i];
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}

	for (int i = 0; i < n; ++i) {
		g[2 * i].push_back(2 * i + 1);
		g[2 * i + 1].push_back(2 * i);
	}

	res.resize(2 * n, -1);
	for (int i = 0; i < 2 * n; ++i) {
		if (res[i] == -1)
			dfs(i, 0);
	}


	for (int i = 0; i < n; ++i) 
		cout << res[u[i]] + 1 << " " << res[v[i]] + 1 << endl;
 	
}