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
#include <unordered_set>
#include <cstring>
#include <array>
#include <variant>
#include <any>
#include <experimental/filesystem>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <numeric>

#define debug(x) cout << #x << " is " << x << endl;

using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e9 + 10;
const ll MOD = 998244353;
const ld PI = acos(-1);
const int N = 5002;

vector<int> g[N];

bool ok = true;
int color[N];

void dfs(int v, int c) {
	color[v] = c;
	for (auto u: g[v]) {
		if (color[u] == c) {
			ok = false;
			return;	
		}	
		if (!color[u]) {
			dfs(u, -c);	
		}
	}
}

bool dp[N][N];
int par[N][N];

void solve() {
	int n, m;
	cin >> n >> m;
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	for (int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;	
		g[--v].push_back(--u);
		g[u].push_back(v);
	}

	int c = 0;
	for (int i = 0; i < n; ++i) {
		if (!color[i])
			dfs(i, ++c);
	}

	if (!ok) {
		cout << "NO\n";
		return;	
	}

	unordered_map<int, int> cnt_by_c;
	for (int i = 0; i < n; ++i) {
		cnt_by_c[color[i]]++;	
	}

	dp[0][0] = true;
	for (int i = 0; i < c; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (!dp[i][j]) continue;	
			int c1 = cnt_by_c[i + 1];
			int c2 = cnt_by_c[-(i + 1)];
			if (j + c1 <= n2) {
				dp[i + 1][j + c1] = true;
				par[i + 1][j + c1] = 1;
			}
			if (j + c2 <= n2) {
				dp[i + 1][j + c2] = true;
				par[i + 1][j + c2] = -1;
			}
		}		
	}
	if (!dp[c][n2]) {
		cout << "NO" << endl;
		return;	
	}
	unordered_set<int> col2;
	int cur = n2;
	for (int i = c; i > 0; --i) {
		assert(dp[i][cur]);
		if (par[i][cur] == 1) { 
			col2.insert(i);
			cur -= cnt_by_c[i];
		} else {
			col2.insert(-i);
			cur -= cnt_by_c[-i];	
		}
	}

	vector<int> answer(n, -1);
	for (int i = 0; i < n; ++i) {
		if (col2.count(color[i])) {
			answer[i] = 2;	
		} else if (n1) {
			answer[i] = 1;
			n1--;	
		} else {
			answer[i] = 3;	
		}
	}

	cout << "YES" << endl;
	for (auto x: answer) {
		cout << x;	
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}