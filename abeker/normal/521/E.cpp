#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;

int N, M;
vector <int> adj[MAXN];
int disc[MAXN], low[MAXN];
stack <pii> stk;
bool bio[MAXN];
int dad[MAXN];
int pos[MAXN];
int timer;

void add_edge(int a, int b) {
	adj[a].push_back(b);
	adj[b].push_back(a);
}

void load() {
	scanf("%d%d", &N, &M);
	while (M--) {
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
	}
}

void find_cycle(int x, int p, vector <int> &v) {
	if (!v.empty())
		return;
	bio[x] = true;
	dad[x] = p;
	for (auto it : adj[x])
		if (!bio[it])
			find_cycle(it, x, v);
		else if (it != p && v.empty()) {
			int curr = x;
			while (1) {
				v.push_back(curr);
				if (curr == it)
					break;
				curr = dad[curr];
			}
			return;
		}
}

void remove(vector <int> &v, int val) {
	for (int i = 0; i < v.size(); i++) 
		if (v[i] == val) {
			v.erase(v.begin() + i);
			return;
		}
	assert(false);
}

void output(const vector <int> &v) {
	printf("%d", v.size());
	for (auto it : v)
		printf(" %d", it);
	puts("");
}

void find_path(int x, int p, vector <int> &v) {
	if (!v.empty())
		return;
	bio[x] = true;
	dad[x] = p;
	if (pos[x] && p) {
		for (int curr = x; curr; curr = dad[curr])
			v.push_back(curr);
		return;
	}
	for (auto it : adj[x])
		if (!bio[it])
			find_path(it, x, v);
}

void finish(const vector <pii> &comp) {
	unordered_set <int> nodes;
	for (auto it : comp) {
		nodes.insert(it.first);
		nodes.insert(it.second);
	}
	
	if (nodes.size() >= comp.size())
		return;
	
	for (int i = 1; i <= N; i++)
		adj[i].clear();
	for (auto it : comp)
		add_edge(it.first, it.second);
	
	vector <int> cycle;
	find_cycle(*nodes.begin(), 0, cycle);
	
	int len = cycle.size();
	for (int i = 0; i < len; i++) {
		remove(adj[cycle[i]], cycle[(i + 1) % len]);
		remove(adj[cycle[(i + 1) % len]], cycle[i]); 
		pos[cycle[i]] = i + 1;
	}
	
	memset(bio, false, sizeof bio);
	
	vector <int> path;
	for (auto it : cycle) {
		find_path(it, 0, path);
		if (!path.empty())
			break;
	}
	
	puts("YES");
	output(path);
	
	int s = path[0];
	int t = path.back();
	for (int i = 0; i < 2; i++) {
		vector <int> ans;
		int curr = pos[s] - 1;
		while (1) {
			ans.push_back(cycle[curr]);
			if (curr == pos[t] - 1)
				break;
			curr = (curr + 2 * i - 1 + len) % len;
		}
		output(ans);
	}
	
	exit(0);
}

void dfs(int x, int p) {
	disc[x] = low[x] = ++timer;
	for (auto it : adj[x])
		if (!disc[it]) {
			stk.push({x, it});
			dfs(it, x);
			low[x] = min(low[x], low[it]);
			if (low[it] >= disc[x]) {
				vector <pii> bicon;
				while (1) {
					bicon.push_back(stk.top());
					stk.pop();
					if (bicon.back() == pii(x, it))
						break;
				}
				finish(bicon);
			}
		}
		else if (it != p) {
			low[x] = min(low[x], disc[it]);
			if (disc[it] < disc[x])
				stk.push({x, it});
		}
}

void solve() {
	for (int i = 1; i <= N; i++)
		if (!disc[i])
			dfs(i, 0);
	puts("NO");
}

int main() {
	load();
	solve();
	return 0;
}