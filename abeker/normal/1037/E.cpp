#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N, M, K;
int x[MAXN], y[MAXN];
unordered_set <int> adj[MAXN];
int ans[MAXN];

struct cmp {
	bool operator()(const int &lhs, const int &rhs) const {
		if (adj[lhs].size() != adj[rhs].size())
			return adj[lhs].size() < adj[rhs].size();
		return lhs < rhs;
	}
};

set <int, cmp> in;

void load() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < M; i++)
		scanf("%d%d", x + i, y + i);
}

void reduce() {
	if (in.empty())
		return;
	int x = *in.begin();
	if (adj[x].size() >= K)
		return;
	in.erase(x);
	for (auto it : adj[x]) 
		if (in.count(it)) {
			in.erase(it);
			adj[it].erase(x);
			in.insert(it);
		}
	reduce();
}

void solve() {
	for (int i = 0; i < M; i++) {
		adj[x[i]].insert(y[i]);
		adj[y[i]].insert(x[i]);
	}
	
	for (int i = 1; i <= N; i++)
		in.insert(i);
	
	reduce();
	
	for (int i = M - 1; i >= 0; i--) {
		ans[i] = in.size();
		if (in.count(x[i]) && in.count(y[i])) {
			in.erase(x[i]);
			in.erase(y[i]);
			adj[x[i]].erase(y[i]);
			adj[y[i]].erase(x[i]);
			in.insert(x[i]);
			in.insert(y[i]);
			reduce();
		}
	}
	
	for (int i = 0; i < M; i++)
		printf("%d\n", ans[i]);
}

int main() {
	load();
	solve();
	return 0;
}