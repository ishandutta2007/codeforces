#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int N, M;
vector <int> adj[MAXN], inv[MAXN];
vector <int> ans;
bool used[MAXN], in[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	while (M--) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		inv[b].push_back(a);
	}
}

void induct(int x) {
	if (x > N)
		return;
		
	if (used[x]) {
		induct(x + 1);
		return;
	}
	
	used[x] = true;
	vector <int> tmp = {x};
	for (auto it : adj[x])
		if (!used[it]) {
			used[it] = true;
			tmp.push_back(it);
		}
	
	induct(x + 1);
	
	bool has = false;
	for (auto it : inv[x])
		has |= in[it];
	
	if (!has) {
		ans.push_back(x);
		in[x] = true;
	}
	
	for (auto it : tmp)
		used[it] = false;
}

void solve() {
	induct(1);
	
	printf("%d\n", ans.size());
	for (auto it : ans)
		printf("%d ", it);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}