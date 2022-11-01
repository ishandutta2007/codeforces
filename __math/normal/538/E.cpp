#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

// #pragma comment(linker,"/STACK:36777216")

vector<int> e[ten(5) * 2];
int leaf[ten(5) * 2], depth[ten(5) * 2];
bool isl[ten(5) * 2];

int dfs1(int v, int par,int dep) {
	bool is_leaf = (v != 0 && sz(e[v]) == 1);
	isl[v] = is_leaf;
	depth[v] = dep;
	if (is_leaf) return leaf[v] = 1;
	for (auto to : e[v]) {
		if (to == par) continue;
		leaf[v] += dfs1(to, v , dep + 1);
	}
	return leaf[v];
}

int dfs2(int v, int par, bool f) {
	if (isl[v]) return 1;
	if (f) {
		int mn = ten(6);
		for (auto to : e[v]) {
			if (to == par) continue;
			mn = min(mn, dfs2(to, v, f ^ 1));
		}
		return mn;
	} else {
		int sm = 0;
		for (auto to : e[v]) {
			if (to == par) continue;
			sm += dfs2(to, v, f ^ 1);
		}
		return sm;
	}
}

int main() {
	int n; scanf("%d", &n);
	FOR(i, n - 1) {
		int u, v; scanf("%d%d", &u, &v);
		u--, v--;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	if (n <= 2) {
		puts("1 1");
		return 0;
	}

	int m = dfs1(0, -1 , 0);
	int ans1 = m + 1 - dfs2(0, -1, true);
	int ans2 = dfs2(0, -1, false);

	cout << ans1 << " " << ans2 << endl;

}