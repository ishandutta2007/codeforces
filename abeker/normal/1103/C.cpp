#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

int N, M, K;
vector <int> adj[MAXN], arc[MAXN];
vector <int> path, leaves;
bool bio[MAXN];
int dad[MAXN], dep[MAXN];

void dfs(int x, int p) {
	bio[x] = true;
	dad[x] = p;
	bool leaf = true;
	path.push_back(x);
	if (path.size() > (N - 1) / K) {
		printf("PATH\n%d\n", path.size());
		for (auto it : path)
			printf("%d ", it);
		puts("");
		exit(0);
	}
	for (auto it : adj[x])
		if (!bio[it]) {
			dep[it] = dep[x] + 1;
			dfs(it, x);
			leaf = false;
		}
		else if (it != p)
			arc[x].push_back(it);
	if (leaf) 
		leaves.push_back(x);
	path.pop_back();
}

vector <int> go_up(int x, int y) {
	if (dep[x] < dep[y])
		swap(x, y);
	vector <int> res;
	for (; x; x = dad[x]) {
		res.push_back(x);
		if (x == y)
			break;
	}
	return res;
}

bool finish(vector <int> cycle) {
	if (!(cycle.size() % 3)) 
		return false;
	printf("%d\n", cycle.size());
	for (auto it : cycle)
		printf("%d ", it);
	puts("");
	return true;
}

void find_cycle(int x) {
	assert(arc[x].size() >= 2);
	if (finish(go_up(x, arc[x][0])))
		return;
	if (finish(go_up(x, arc[x][1])))
		return;
	vector <int> cyc = go_up(arc[x][0], arc[x][1]);
	cyc.insert(cyc.begin(), x);
	assert(finish(cyc));
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	while (M--) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs(1, 0);
	
	assert(leaves.size() >= K);
	
	puts("CYCLES");
	for (int i = 0; i < K; i++)
		find_cycle(leaves[i]);
	
	return 0;
}