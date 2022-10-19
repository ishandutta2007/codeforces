#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;

int N, M;
int x[MAXN], y[MAXN];
vector <pii> adj[MAXN], ch[MAXN];
char part[MAXN];
int label[MAXN];
int clr[MAXN];
int ans[MAXN];

void load() {
	scanf("%d%d%s", &N, &M, part);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", x + i, y + i);
		adj[x[i]].push_back({y[i], i});
		adj[y[i]].push_back({x[i], i});
	}
}

pii dfs(int x, int p, int c) {
	clr[x] = c;
	pii res = {-1, -1};
	for (auto it : adj[x])
		if (clr[it.first] == -1) {
			ch[x].push_back(it);
			pii tmp = dfs(it.first, x, c ^ 1);
			if (tmp.first != -1)
				res = tmp;
		}
		else if (clr[it.first] == clr[x])
			res = {x, it.second};
	return res;
}

void add(int &x, int y) {
	x += y;
	if (x >= 3)
		x -= 3;
	else if (x < 0)
		x += 3;
}

int calc(int x) {
	int curr = label[x];
	for (auto it : ch[x]) {
		int tmp = calc(it.first);
		ans[it.second] = tmp;
		add(curr, -tmp);
	}
	return curr;
}

void finish() {
	vector <int> sum(N, 0);
	for (int i = 0; i < M; i++) {
		if (!ans[i])
			ans[i] = 3;
		printf("%d %d %d\n", x[i], y[i], ans[i]);
		sum[x[i]] += ans[i];
		sum[y[i]] += ans[i];
	}
	
	for (int i = 0; i < M; i++)
		assert(sum[x[i]] != sum[y[i]]);
	
	exit(0);
}

void bipartite() {
	vector <int> v[2];
	for (int i = 0; i < N; i++)
		v[clr[i]].push_back(i);
	
	int big = v[0].size() > v[1].size() ? 0 : 1;
	int sz = v[big].size();
	int twos = sz % 2 ? (sz - 3) / 2 : sz / 2;
	for (int i = 0; i < sz; i++)
		label[v[big][i]] = (i < twos) + 1;
	
	assert(!calc(0));
	
	finish();
}

void solve() {
	for (int i = 0; i < N; i++)
		label[i] = part[i] - 'X';
		
	memset(clr, -1, sizeof clr);
	pii edge = dfs(0, -1, 0);
	
	if (edge.first == -1) 
		bipartite();
	
	for (int i = 0; i < 3; i++) {
		ans[edge.second] = i;
		int u = edge.first;
		int v = x[edge.second] ^ y[edge.second] ^ u;
		add(label[u], -i);
		add(label[v], -i);
		if (!calc(0))
			finish();
		add(label[u], i);
		add(label[v], i);	
	}
	
	assert(false);
}

int main() {
	load();
	solve();
	return 0;
}