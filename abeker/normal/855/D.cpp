#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int LOG = 18;

int N, Q;
int anc[MAXN][LOG];
int rel[MAXN];
int depth[MAXN];
vector <int> ch[MAXN];
int disc[MAXN], fin[MAXN];
int jmp[MAXN][2];
int timer;

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", anc[i], rel + i);
		if (anc[i][0] == -1)
			anc[i][0] = 0;
		ch[anc[i][0]].push_back(i);
	}
}

void dfs(int x) {
	depth[x] = depth[anc[x][0]] + 1;
	disc[x] = timer++;
	for (int i = 0; i < 2; i++)
		if (i == rel[x])
			jmp[x][i] = jmp[anc[x][0]][i];
		else
			jmp[x][i] = depth[x];
	for (auto it : ch[x])
		dfs(it);
	fin[x] = timer;
}

int lca(int x, int y) {
	if (depth[x] < depth[y])
		swap(x, y);
	int diff = depth[x] - depth[y];
	for (int i = 0; i < LOG; i++)
		if (diff >> i & 1)
			x = anc[x][i];
	if (x == y)
		return x;
	for (int i = LOG - 1; i >= 0; i--)
		if (anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	return anc[x][0];
}

bool check(int x, int y, int t) {
	return disc[x] >= disc[y] && disc[x] < fin[y] && depth[y] >= jmp[x][t];
}

bool query(int t, int u, int v) {
	if (u == v)
		return false;
	if (t == 1)
		return check(v, u, 0);
	int l = lca(u, v);
	return check(u, l, 0) && check(v, l, 1) && v != l;
}

void solve() {
	dfs(0);
			
	for (int j = 1; j < LOG; j++)
		for (int i = 1; i <= N; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
	
	scanf("%d", &Q);			
	while (Q--) {
		int t, u, v;
		scanf("%d%d%d", &t, &u, &v);
		puts(query(t, u, v) ? "YES" : "NO");
	}
}

int main() {
	load();
	solve();
	return 0;
}