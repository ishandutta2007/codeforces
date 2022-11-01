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

#define debug(x) cout << #x << " is " << x << endl;

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 10;
const int N = 1e6 + 10;

vector<int> g[N];

int color[N];

void dfs(int v, int c) {
	color[v] = c;
	for (auto u: g[v]) {
		if (!color[u]) {
			dfs(u, 3 - c);	
		}	
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int v, u;
		cin >> v >> u;
		g[--v].push_back(--u);
		g[u].push_back(v);
	}
	dfs(0, 1);
	int has1 = 0, has2 = 0;
	for (int i = 0; i < n; ++i) {
		if ((int)g[i].size() == 1) {
			if (color[i] == 1) has1 = 1;	
			if (color[i] == 2) has2 = 1;	
		}	
	}

	if (has1 + has2 == 2) {
		cout << 3 << " "; 
	} else {
		cout << 1 << " "; 
	}

	int ansmax = n - 1;
	for (int i = 0; i < n; ++i) {
		int ls = 0;	
		for (auto u: g[i]) {
			if (g[u].size() == 1u) {
				ls++;	
			}	
		}
		if (ls > 1) {
			ansmax -= (ls - 1);	
		}
	}
	cout << ansmax <<  endl;

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();	
	}
}