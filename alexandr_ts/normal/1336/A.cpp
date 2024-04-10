#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <type_traits>
#include <queue>
#include <cassert>
#include <utility>
#include <functional>
#include <set>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <vector>
#include <memory>
#include <string>
#include <optional>
#include <ostream>
#include <iterator>
#include <new>
#include <cstdlib>
#include <tuple>
#include <unordered_map>
#include <cstring>
#include <array>
#include <variant>
#include <any>
#include <experimental/filesystem>
#include <fstream>
#include <numeric>

#define debug(x) cout << #x << " is " << x << endl;

using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;

vector<int> g[N];
int h[N], sz[N];

void dfs(int v, int par = -1, int he = 0) {
	h[v] = he;
	sz[v] = 1;
	for (auto u: g[v]) {
		if (u != par) {
			dfs(u, v, he + 1);	
			sz[v] += sz[u];
		}	
	}
}


bool tour[N];
ll ans = 0;
void dfs2(int v, int par = -1, int h = 0) {
	if (!tour[v]) ans += h;	
	for (auto u: g[v]) {
		if (u != par) {
			dfs2(u, v, h + tour[v]);	
		}	
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		g[--v].push_back(--u);
		g[u].push_back(v);
	}
	dfs(0);
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i) {
		v[i] = {h[i] - sz[i], i};	
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n - k; ++i) {
		tour[v[i].second] = true;	
	}
	dfs2(0);
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();	
	}
}