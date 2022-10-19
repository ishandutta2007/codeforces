/*input
3 3
2 2 2
1 2
2 3
1 3

*/

// https://codeforces.com/group/sd4r2IvEfL/contest/289090/problem/D

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstring>

using namespace std;

const int N = 100006;
int n, m, e[N][2], prv[N];
bool d[N], vis[N], used[N];
vector<int> g[N];
int64_t c[N], w[N];

void color(int u)
{
	vis[u] = 1;
	for (int i : g[u]) {
		int v = u ^ e[i][0] ^ e[i][1];
		if (vis[v]) continue;
		used[i] = true;
		d[v] = !d[u];
		color(v);
	}
}

int64_t solve(int u)
{
	vis[u] = 1;
	for (int i : g[u]) if (used[i]) {
		int v = u ^ e[i][0] ^ e[i][1];
		if (vis[v]) continue;
		prv[v] = i;
		int64_t cur = solve(v);
		w[i] += cur, c[u] -= cur, c[v] -= cur;
	}
	return c[u];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	for (int i = 1; i <= m; ++i) {
		cin >> e[i][0] >> e[i][1];
		g[e[i][0]].push_back(i);
		g[e[i][1]].push_back(i);
	}

	color(1);

	int64_t diff = 0;
	int r = 0;
	for (int u = 1; u <= n; ++u) {
		if (d[u]) diff += c[u];
		else diff -= c[u];
		for (int i : g[u]) if (d[u] == d[u ^ e[i][0] ^ e[i][1]]) r = u;
	}

	if (r) {
		memset(vis, 0, sizeof(vis[0]) * (n + 1));
		int64_t cur = solve(r);
		assert(cur % 2 == 0);
		cur /= 2;

		int id = 0;
		for (int i : g[r]) if (d[r] == d[r ^ e[i][0] ^ e[i][1]]) id = i;
		assert(id);
		w[id] += cur;
		for (int u = r ^ e[id][0] ^ e[id][1]; u != r; u = u ^ e[prv[u]][0] ^ e[prv[u]][1]) {
			cur = -cur;
			w[prv[u]] += cur;
		}
	} else {
		if (diff) return cout << "NO" << endl, 0;
		memset(vis, 0, sizeof(vis[0]) * (n + 1));
		int64_t cur = solve(1);
		assert(cur == 0);
	}

	cout << "YES" << endl;
	for (int i = 1; i <= m; ++i) cout << w[i] << '\n';
}