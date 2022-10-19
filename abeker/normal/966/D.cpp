#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
typedef vector <int> path;

const int MAXN = 3e5 + 5;
const int INF = 0x3f3f3f3f;

int N, M;
int a[MAXN], b[MAXN];
vector <int> E[MAXN];
queue <int> Q;
int dist[MAXN], dad[MAXN];
int adj[MAXN];
bool bio[MAXN];
vector <int> comp;
set <pii> S;
path curr;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", a + i, b + i);
		E[a[i]].push_back(b[i]);
		E[b[i]].push_back(a[i]);
	}
}

path bfs() {
	memset(dist, INF, sizeof dist);
	Q.push(1);
	dist[1] = 0;
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for (auto it : E[x])
			if (dist[it] == INF) {
				dist[it] = dist[x] + 1;
				dad[it] = x;
				Q.push(it);
			}
	}
	
	path res;
	if (!dad[N])
		return res;
		
	for (int x = N; x; x = dad[x])
		res.push_back(x);
	
	reverse(res.begin(), res.end());
	
	return res;
}

path solve4() {
	for (auto it : E[1])
		adj[it] = 1;
	
	for (int i = 0; i < M; i++) {
		if (a[i] == 1 || b[i] == 1)
			continue;
		if (adj[a[i]] < adj[b[i]])
			swap(a[i], b[i]);
		if (adj[a[i]] ^ adj[b[i]]) 
			return {1, a[i], b[i], 1, N};
	}
	
	return path();
}

void dfs(int x) {
	comp.push_back(x);
	bio[x] = true;
	for (auto it : E[x])
		if (!bio[it] && it > 1)
			dfs(it);
}

bool go(int x, int dest) {
	bio[x] = true;
	curr.push_back(x);
	if (x == dest) 
		return true;
	for (auto it : E[x])
		if (!bio[it] && it > 1 && go(it, dest))
			return true;
	curr.pop_back();
	return false;
}

bool has_edge(int u, int v) {
	return S.count({min(u, v), max(u, v)});
}

path reconstruct(int x, int y) {
	memset(bio, false, sizeof bio);
	curr.clear();
	go(x, y);
	assert(curr.size() >= 3);
	for (int i = (int)curr.size() - 2; i >= 0; i--)
		if (has_edge(x, curr[i]))
			return {1, x, curr[i], curr[i + 1], x, N};
	assert(0);
}

path find() {
	for (int i = 1; i < comp.size(); i++)
		for (int j = 0; j < i; j++)
			if (!has_edge(comp[i], comp[j]))
				return reconstruct(comp[j], comp[i]);
	return path();
}

path solve5() {
	for (int i = 0; i < M; i++) {
		if (a[i] > b[i])
			swap(a[i], b[i]);
		S.insert({a[i], b[i]});
	}
	
	for (auto it : E[1])
		if (!bio[it]) {
			comp.clear();
			dfs(it);
			path tmp = find();
			if (!tmp.empty())
				return tmp;
		}
	
	return path();
}

path better(path p, path q) {
	if (p.empty())
		return q;
	if (q.empty())
		return p;
	if (p.size() < q.size())
		return p;
	return q;
}

void solve() {
	path sol = better(bfs(), better(solve4(), solve5()));
	
	if (sol.empty()) {
		puts("-1");
		return;
	}
	
	printf("%d\n", (int)sol.size() - 1);
	for (auto it : sol)
		printf("%d ", it);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}