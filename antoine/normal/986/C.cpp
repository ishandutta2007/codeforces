#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#undef NDEBUG
#include <assert.h>
#include <random>

using namespace std;
typedef long long ll;

int n;
bool exists[1 << 22] = { false };
bool visited[1 << 22];

void dfs1(int u, stack<int> &st) {
	assert(u >= 0 && u < (1 << n));
	visited[u] = true;
	if (exists[u]) {
		const int v = ((1 << n) - 1) ^ u;
		assert(v >= 0 && v < (1 << n));
		if (!visited[v])
			dfs1(v, st);
	}
	for (int mask = 1; mask < (1 << n); mask <<= 1)
		if (u&mask) {
			const int v = u^mask;
			assert(v >= 0 && v < (1 << n));
			if (!visited[v])
				dfs1(v, st);
		}
	st.push(u);
}

int test = 0;
bool dfs2(int u) {
	assert(u >= 0 && u < (1 << n));
	visited[u] = true;
	bool res = exists[u];
	const int v = ((1 << n) - 1) ^ u;
	assert(v >= 0 && v < (1 << n));
	if (exists[v] && !visited[v])
		res = dfs2(v) || res;
	for (int mask = 1; mask < (1 << n); mask <<= 1)
		if (!(u&mask)) {
			const int v = u^mask;
			assert(v >= 0 && v < (1 << n));
			if (!visited[v])
				res = dfs2(v) || res;
		}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a;
		cin >> a;
		exists[a] = true;
	}

	stack<int> st;
	for (int i = 0; i < (1 << n); ++i)
		if (!visited[i])
			dfs1(i, st);
	assert(st.size() == (1 << n));

	memset(visited, 0, sizeof visited);
	int ans = 0;
	while (!st.empty()) {
		const int u = st.top();
		st.pop();
		ans += !visited[u] && dfs2(u);
	}
	cout << ans;
	return 0;
}