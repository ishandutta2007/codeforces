#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 200005;
const int LOG = 18;

int N, M;
int depth[MAXN];
int disc[MAXN], fin[MAXN];
int anc[MAXN][LOG];
vector <int> ch[MAXN];
vector <int> paths[MAXN];
int u[MAXN], v[MAXN], cost[MAXN];
ll f[MAXN];
int timer;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 2; i <= N; i++) {
		scanf("%d", anc[i]);
		ch[anc[i][0]].push_back(i);
	}
}

void update(int x, int val) {
	for (x++; x < MAXN; x += x & -x)
		f[x] += val;
}

ll get(int x) {
	ll res = 0;
	for (x++; x; x -= x & -x)
		res += f[x];
	return res;
}

ll ask(int x) {
	return get(disc[x]);
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

void dfs(int x, int d) {
	depth[x] = d;
	disc[x] = timer++;
	for (auto it : ch[x])
		dfs(it, d + 1);
	fin[x] = timer;
}

int go(int x) {
	int res = 0;
	for (auto it : ch[x])
		res += go(it);
	ll diff = 0;
	for (auto it : paths[x])
		diff = max(diff, ask(u[it]) + ask(v[it]) - 2 * ask(x) + cost[it]); 
	update(disc[x], -diff);
	update(fin[x], diff);
	return res + diff;
}

int solve() {
	dfs(1, 0);
	
	for (int j = 1; j < LOG; j++)
		for (int i = 1; i <= N; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
	
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", u + i, v + i, cost + i);
		paths[lca(u[i], v[i])].push_back(i);
	}
	
	return go(1);
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}