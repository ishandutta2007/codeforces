#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 300005;
const int BASE = 3137;
const int MOD = 1000000007;

int N, M;
int a[MAXN], b[MAXN];
vector <int> E[MAXN];
int adj[MAXN];
pii val[MAXN], pot[MAXN];
vector <pii> all;
set <pii> S;
int x[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
		scanf("%d%d", a + i, b + i);
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

inline void add(pii &x, pii y) {
	x.first += y.first;
	if (x.first >= MOD)
		x.first -= MOD;
	x.second += y.second;
}

void add_edge(int u, int v) {
	u = adj[u];
	v = adj[v];
	if (u > v)
		swap(u, v);
	if (u != v && !S.count({u, v})) {
		E[u].push_back(v);
		E[v].push_back(u);
		S.insert({u, v});
	}
}

void dfs(int node, int prev, int num) {
	x[node] = num;
	for (auto it : E[node])
		if (it != prev)
			dfs(it, node, num + 1);
}

void solve() {
	pot[0] = {1, rand()};
	for (int i = 1; i <= N; i++) {
		pot[i].first = mul(pot[i - 1].first, BASE);
		pot[i].second = rand();
	}
		
	for (int i = 1; i <= N; i++)
		add(val[i], pot[i]);
	for (int i = 0; i < M; i++) {
		add(val[a[i]], pot[b[i]]);
		add(val[b[i]], pot[a[i]]);
	}
	
	for (int i = 1; i <= N; i++)
		all.push_back(val[i]);
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
		
	for (int i = 1; i <= N; i++)
		adj[i] = lower_bound(all.begin(), all.end(), val[i]) - all.begin();
		
	for (int i = 0; i < M; i++) 
		add_edge(a[i], b[i]);
			
	int start = -1;
	bool ok = true;
	for (int i = 0; i < all.size(); i++) {
		if (E[i].size() <= 1) 
			start = i;
		ok &= E[i].size() <= 2;
	}
	
	if (!ok || start == -1) {
		puts("NO");
		return;
	}
	
	dfs(start, -1, 1);
	
	puts("YES");
	for (int i = 1; i <= N; i++)
		printf("%d ", x[adj[i]]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}