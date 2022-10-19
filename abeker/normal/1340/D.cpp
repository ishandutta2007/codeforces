#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;

int N;
vector <int> adj[MAXN];
vector <pii> ans;
int maxDegree;

void load() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void add(int v, int t) {
	ans.push_back({v, t});
}

void dfs(int x, int p, int t) {
	vector <int> ch;
	for (auto it : adj[x])
		if (it != p)
			ch.push_back(it);
	int curr = t;
	add(x, curr);
	for (int i = 0; i < ch.size(); i++) {
		if (curr == maxDegree) {
			curr = t - (int)ch.size() + i - 1;
			add(x, curr);
		}
		dfs(ch[i], x, ++curr);
		add(x, curr);
	}
	if (t && curr != t - 1)
		add(x, t - 1);
}

void solve() {
	for (int i = 1; i <= N; i++)
		maxDegree = max(maxDegree, (int)adj[i].size());
	
	dfs(1, 0, 0);
	
	printf("%d\n", ans.size());
	for (auto it : ans)
		printf("%d %d\n", it.first, it.second);
}

int main() {
	load();
	solve();
	return 0;
}