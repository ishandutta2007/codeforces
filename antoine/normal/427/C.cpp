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

using namespace std;

const int mod = (int)1e9 + 7;
enum Color { white, grey, black };
const int MAX_NODES = (int)1e5;
Color color[MAX_NODES + 1] = { white };

int n;
int cost[MAX_NODES + 1];
vector<int> adj[MAX_NODES + 1];
int low[MAX_NODES + 1];
stack<int> st;

long long ans1 = 0, ans2 = 1;

void dfs(const int &u) {
	color[u] = grey;

	int disc = low[u] = st.size();
	st.push(u);

	for (int &v : adj[u]) {
		if (color[v] == white)
			dfs(v);
		if (color[v] == grey)
			low[u] = min(low[u], low[v]);
	}

	if (low[u] == disc) {
		int minCost = cost[u];
		int occ = 1;
		for (;;) {
			int v = st.top();
			st.pop();
			color[v] = black;
			if (v == u)
				break;
			if (cost[v] < minCost) {
				minCost = cost[v];
				occ = 1;
			}
			else if(cost[v] == minCost)
				++occ;
		}
		ans1 += minCost;
		ans2 = (ans2 * occ) % mod;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> cost[i];

	int m;
	cin >> m;
	for (; m > 0; --m) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; ++i)
		if (color[i] == white)
			dfs(i);
	cout << ans1 << ' ' << ans2;
	return 0;
}