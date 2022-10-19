#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 200005;

int N;
vector <int> E[MAXN];
int color[MAXN];
vector <pii> V;

void add_edge(int u, int v) {
	E[u].push_back(v);
	E[v].push_back(u);
}

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		add_edge(a, b);
		V.push_back({a, b});
	}
}

void dfs(int x, int c) {
	if (color[x] != -1)
		return;
	color[x] = c;
	for (int nxt : E[x])
		dfs(nxt, c ^ 1);
}

void solve() {
	for (int i = 1; i <= N; i++)
		add_edge(2 * i - 1, 2 * i);
	
	memset(color, -1, sizeof color);
	for (int i = 1; i <= 2 * N; i++)
		dfs(i, 0);
	
	for (auto it : V)
		printf("%d %d\n", ++color[it.first], ++color[it.second]);
}

int main() {
	load();
	solve();
	return 0;
}