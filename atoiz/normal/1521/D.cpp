/*input

*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>
#include <array>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

int N;
vector<vector<int>> G;
vector<int> del, add;

int dfs(int u, int p) {
	int x = 0;
	for (int v : G[u]) if (v != p) {
		int y = dfs(v, u);
		if (y == 0);
		else if (x == 0) x = y;
		else if (x == -1) {
			del.push_back(u);
			del.push_back(v);
			add.push_back(v);
			add.push_back(y);
		} else {
			assert(p);
			del.push_back(p);
			del.push_back(u);
			add.push_back(y);
			add.push_back(x);
			x = -1;
		}
	}
	if (x == 0) return u;
	if (x > 0) return x;	
	return 0;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		G.resize(N + 1);
		FOR(i, 1, N) G[i].clear();
		del.clear(), add.clear();

		FOR(e, 0, N - 2) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		int r = 1;
		while ((int) G[r].size() > 1) ++r;
		add.push_back(r);
		dfs(r, 0);
		add.pop_back();

		cout << add.size() / 2 << '\n';
		for (int i = 0; i < (int) add.size(); i += 2) {
			cout << del[i] << ' ' << del[i + 1] << ' ' << add[i] << ' ' << add[i + 1] << '\n';
		}
	}

	return 0;
}