#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 500005;
const int LOG = 19;

int N;
vector <int> ch[MAXN];
vector <pii> nodes[MAXN];
vector <int> imp[MAXN];
vector <int> S[MAXN];
int anc[MAXN][LOG];
int depth[MAXN];
int disc[MAXN], fin[MAXN];
ll curr[MAXN], sol[MAXN];
int timer;

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", anc[i]);
		ch[anc[i][0]].push_back(i);
	}
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

void dfs(int x) {
	depth[x] = depth[anc[x][0]] + 1;
	disc[x] = timer++;
	nodes[depth[x]].push_back({disc[x], x});
	for (auto it : ch[x])
		dfs(it);
	fin[x] = timer;
}

int get(int d, int x) {
	return lower_bound(nodes[d].begin(), nodes[d].end(), pii(x, 0)) - nodes[d].begin();
}

int cnt(int x, int d) {
	return get(d, fin[x]) - get(d, disc[x]);
}

void go(int x) {
	for (auto it : imp[x]) {
		curr[it] += (ll)(depth[x] - S[it].back()) * cnt(x, it);
		S[it].push_back(depth[x]);
	}
	
	sol[x] = sol[anc[x][0]] + curr[depth[x]] - 1;
	for (auto it : ch[x])
		go(it);
		
	for (auto it : imp[x]) {
		S[it].pop_back();
		curr[it] -= (ll)(depth[x] - S[it].back()) * cnt(x, it);
	}
}

void solve() {
	for (int j = 1; j < LOG; j++)
		for (int i = 1; i <= N; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
	
	int root = ch[0][0];
	dfs(root);	
	
	for (int i = 1; i <= N; i++) {
		S[i].push_back(0);
		for (int j = 0; j < nodes[i].size(); j++) {
			imp[nodes[i][j].second].push_back(i);
			if (j)
				imp[lca(nodes[i][j - 1].second, nodes[i][j].second)].push_back(i);
		}
	}
	
	go(root);
	
	for (int i = 1; i <= N; i++)
		printf("%lld ", sol[i]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}