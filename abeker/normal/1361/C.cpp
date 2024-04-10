#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 5e5 + 5;
const int LOG = 20;

int N;
int a[MAXN], b[MAXN];
vector <pii> adj[1 << LOG];
multiset <pii> graph[1 << LOG];
bool bio[1 << LOG];
vector <int> ans;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", a + i, b + i);
}

void add_edge(int u, int v, int id, bool sets) {
	adj[u].push_back({v, 2 * id + 1});
	adj[v].push_back({u, 2 * id});
	if (sets) {
		graph[u].insert({v, 2 * id + 1});
		graph[v].insert({u, 2 * id});
	}
}

void build_graph(int val, bool sets) {
	for (int i = 0; i < 1 << val; i++)
		adj[i].clear();
	for (int i = 0; i < N; i++)
		add_edge(a[i] & (1 << val) - 1, b[i] & (1 << val) - 1, i, sets);
}

void dfs(int x) {
	bio[x] = true;
	for (auto it : adj[x])
		if (!bio[it.first])
			dfs(it.first);
}

bool check(int val) {
	build_graph(val, false);
	for (int i = 0; i < 1 << val; i++)
		bio[i] = false;
	int cnt = 0;
	for (int i = 0; i < 1 << val; i++) {
		if (adj[i].size() % 2) 
			return false;
		if (!adj[i].empty() && !bio[i]) {
			dfs(i);
			if (++cnt > 1) 
				return false;
		}
	}
	return true;
}

void euler(int x, int which) {
	while (!graph[x].empty()) {
		pii curr = *graph[x].begin();
		graph[x].erase(graph[x].find(curr));
		graph[curr.first].erase(graph[curr.first].find({x, curr.second ^ 1}));
		euler(curr.first, curr.second);
	}
	if (which != -1) {
		ans.push_back(which);
		ans.push_back(which ^ 1);
	}
}

void construct(int val) {
	build_graph(val, true);
	int st = -1;
	for (int i = 0; i < 1 << val; i++)
		if (!adj[i].empty()) {
			st = i;
			break;
		}
	assert(st != -1);
	euler(st, -1);
}

void solve() {
	int lo = 0, hi = LOG;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (check(mid))
			lo = mid;
		else
			hi = mid - 1;
	}
	printf("%d\n", lo);
	construct(lo);
	for (auto it : ans)
		printf("%d ", it + 1);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}