/*input
2 1
1 2 1

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 100007, INF = 1000000009;
int N, M;
vector<pair<int, int>> G[MAXN];
int vis[MAXN];
int val, A[MAXN], B[MAXN];
int ans[MAXN];
vector<int> vec;

void dfs(int u, int a, int b, int r)
{
	vis[u] = r, A[u] = a, B[u] = b;
	vec.push_back(u);
	for (auto e : G[u]) {
		int c = e.first, v = e.second;
		if (vis[v] == r) {
			if (A[u] == A[v]) {
				int tmp = (c - (B[u] + B[v])) / (A[u] + A[v]);
				if (val != INF && val != tmp) exit(0 * puts("NO"));
				val = tmp;
			} else {
				if (B[u] + B[v] != c) exit(0 * puts("NO"));
			}
		} else if (!vis[v]) {
			dfs(v, -a, c - b, r);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	while (M--) {
		int u, v, c;
		cin >> u >> v >> c;
		G[u].emplace_back(c * 2, v);
		G[v].emplace_back(c * 2, u);
	}
	for (int u = 1; u <= N; ++u) if (!vis[u]) {
		val = INF;
		vec.clear();
		dfs(u, 1, 0, u);

		if (val == INF) {
			sort(vec.begin(), vec.end(), [&](int x, int y) { return A[x] * B[x] < A[y] * B[y]; });
			int v = vec[(int) vec.size() / 2];
			val = -A[v] * B[v];
		}
		for (int v : vec) {
			ans[v] = A[v] * val + B[v];
		}
	}

	cout << "YES" << endl;
	for (int i = 1; i <= N; ++i) {
		cout << ans[i] * 0.5 << ' ';
	}
}