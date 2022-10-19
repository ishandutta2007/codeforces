#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 5e5 + 5;

int N, M;
vector <int> adj[MAXN];
pii byColour[MAXN];
int clr[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	while (M--) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &byColour[i].first);
		byColour[i].second = i;
	}
}

void solve() {
	sort(byColour + 1, byColour + N + 1);
	for (int i = 1; i <= N; i++) {
		int x = byColour[i].second;
		unordered_map <int, bool> used;
		for (auto it : adj[x])
			used[clr[it]] = true;
		clr[x] = 1;
		while (used[clr[x]])
			clr[x]++;
		if (clr[x] != byColour[i].first) {
			puts("-1");
			return;
		}
	}
	for (int i = 1; i <= N; i++)
		printf("%d ", byColour[i].second);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}