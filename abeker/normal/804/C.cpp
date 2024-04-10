#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 300005;

int N, M;
vector <int> V[MAXN];
int color[MAXN];
vector <int> E[MAXN];
int sol;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		int s;
		scanf("%d", &s);
		V[i].resize(s);
		for (int j = 0; j < s; j++)
			scanf("%d", &V[i][j]);
		sol = max(sol, s);
	}
	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
}

void dfs(int x, int p) {
	set <int> S;
	for (auto it : V[x])
		if (color[it])
			S.insert(color[it]);
	int curr = 1;
	for (auto it : V[x]) 
		if (!color[it]) {
			while (S.count(curr))
				curr++;
			color[it] = curr;
			S.insert(curr);
		}
	for (auto it : E[x])
		if (it != p)
			dfs(it, x);
}

void solve() {
	dfs(1, 0);
	
	printf("%d\n", sol ? sol : 1);
	for (int i = 1; i <= M; i++)
		printf("%d ", color[i] ? color[i] : 1);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}