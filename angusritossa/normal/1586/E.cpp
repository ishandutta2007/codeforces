#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
#define MAXN 300010
vector<int> adj[MAXN];
vector<int> treeAdj[MAXN];
int n, m, seen[MAXN], upto = 2;
void dfs(int a) {
	seen[a] = 1;
	for (auto b : adj[a]) {
		if (!seen[b]) {
			dfs(b);
			treeAdj[a].push_back(b);
			treeAdj[b].push_back(a);
		}
	}
}
vector<int> path;
bool findPath(int a, int target) {
	seen[a] = upto;
	path.push_back(a);
	if (a == target) return true;
	for (auto b : treeAdj[a]) {
		if (seen[b] != upto) {
			if (findPath(b, target)) return true;
		}
	}
	path.pop_back();
	return false;
}
int tot[MAXN], numOdd, u[MAXN], v[MAXN];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &u[i], &v[i]);
		tot[u[i]]++;
		tot[v[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		numOdd += tot[i] % 2;
	}
	if (numOdd) {
		printf("NO\n%d\n", numOdd/2);
	} else {
		printf("YES\n");
		for (int i = 0; i < q; i++) {
			path.clear();
			upto++;
			findPath(u[i], v[i]);
			printf("%lu\n", path.size());
			for (auto a : path) printf("%d ", a);
			printf("\n");
		}
	}
}