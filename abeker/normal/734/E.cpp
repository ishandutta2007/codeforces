#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 200005;

int N;
int color[MAXN];
vector <int> E[MAXN];
int dad[MAXN], rnk[MAXN];
vector <pii> edges;
int best, mx;

int find(int x) {
	return dad[x] == x ? x : dad[x] = find(dad[x]);
}

void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (rnk[a] > rnk[b]) 
		swap(a, b);
	dad[a] = b;
	rnk[b] += rnk[a] == rnk[b];
}

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", color + i);
		dad[i] = i;
	}
	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (color[a] == color[b])
			join(a, b);
		else 
			edges.push_back({a, b});			
	}
}

void add_edge(int a, int b) {
	E[a].push_back(b);
	E[b].push_back(a);
}

void dfs(int x, int p, int d) {
	if (d > mx) {
		best = x;
		mx = d;
	}
	for (int nxt : E[x]) 
		if (nxt != p) 
			dfs(nxt, x, d + 1);
}
		
int solve() {
	for (pii it : edges)
		add_edge(find(it.first), find(it.second));
	
	dfs(find(1), 0, 0);
	mx = 0;
	dfs(best, 0, 0);
	return (mx + 1) / 2;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}