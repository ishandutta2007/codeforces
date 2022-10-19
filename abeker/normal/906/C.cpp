#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 22;

int N, M;
int adj[MAXN];
int comp[MAXN];
vector <pii> bad;
vector <int> v[MAXN + 1];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--; 
		v--;
		adj[u] |= 1 << v;
		adj[v] |= 1 << u;
	}
}

void dfs(int x, int c, int sub) {
	comp[x] = c;
	for (int i = 0; i < N; i++)
		if (adj[x] >> i & 1) {
			if (comp[i] == -1 && sub >> i & 1)
				dfs(i, c, sub);
			comp[i] = c;
		}
}

bool check(int mask) {
	memset(comp, -1, sizeof comp);
	
	int tmp = 0;
	for (int i = 0; i < N; i++)
		if (comp[i] == -1 && mask >> i & 1)
			dfs(i, tmp++, mask);
	
	for (auto it : bad)
		if (comp[it.first] == -1 || comp[it.second] == -1 || comp[it.first] != comp[it.second])
			return false;
			
	return true;
}

int get(int bits) {
	for (auto it : v[bits])
		if (check(it))
			return it;
	return -1;
}

void solve() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++)
			if (!(adj[i] >> j & 1))
				bad.push_back({i, j});
				
	for (int i = 0; i < 1 << N; i++) 
		v[__builtin_popcount(i)].push_back(i);
	
	int lo = 0, hi = N + 1;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (get(mid) != -1)
			hi = mid;
		else
			lo = mid + 1;
	}
	
	printf("%d\n", lo);
	int best = get(lo);
	for (int i = 0; i < N; i++)
		if (best >> i & 1)
			printf("%d ", i + 1);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}