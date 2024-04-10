#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
int n, bud[MAXN], bud_child[MAXN], num_children[MAXN], leaves, children_minus_1;
vector<int> adj[MAXN];
int dfs(int a, int par) {
	// returns:
	// 0 if is bud
	// 1 if leaf
	// 2 if rip
	vector<int> children;
	for (auto b : adj[a]) {
		if (b != par) children.push_back(b);
	}

	num_children[a] = children.size();

	if (children.empty()) return 1;

	int zeros = 0;
	int ones = 0;
	int twos = 0;
	for (auto b : children) {
		int res = dfs(b, a);
		if (res == 0) zeros++;
		if (res == 1) ones++;
		if (res == 2) twos++;
	}

	int bad = a == 1;
	if (twos) bad = 1;

	if (bad) {
		leaves += ones;
		return 2;
	} else if (ones) {
		children_minus_1 += ones-1;
		return 0;
	} else {
		return 1;
	}
}
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) adj[i].clear(), bud[i] = false, bud_child[i] = false;
		for (int i = 1; i < n; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		leaves = 0;
		children_minus_1 = 0;
		dfs(1, -1);
		
		int ans = max(1, leaves) + children_minus_1;
		printf("%d\n", ans);
	}
}