#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <cassert>

using namespace std;

const int MAXN = 500007, LOG = 20;
int N, A[MAXN], anc[LOG][MAXN], dep[MAXN];
int64_t cost[MAXN];
vector<int> G[MAXN];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> A[i];
	int root = (int) (min_element(A + 1, A + N + 1) - A);
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		cin >> u >> v;
		if (A[u] > A[v]) swap(u, v);
		assert(A[u] < A[v]);
		assert(anc[0][v] == 0);
		anc[0][v] = u;
		G[u].push_back(v);
	}
	for (int j = 1; j < LOG; ++j) for (int u = 1; u <= N; ++u) anc[j][u] = anc[j - 1][anc[j - 1][u]];

	priority_queue<pair<int64_t, int>> pq;
	pq.emplace(cost[root] = 0, root);
	assert(anc[0][root] == 0);
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		for (int v : G[u]) {
			dep[v] = dep[u] + 1;
			cost[v] = A[root] + A[v] + (int64_t) A[root] * (dep[v] == 1 ? 0 : __lg(dep[v] - 1) + 1);
			for (int j = 0; j < LOG && anc[j][v]; ++j) {
				cost[v] = min(cost[v], A[anc[j][v]] + A[v] + (int64_t) A[anc[j][v]] * j);
			}
			pq.emplace(-cost[v], v);
		}
	}

	cout << accumulate(cost + 1, cost + N + 1, 0ll) << endl;
}