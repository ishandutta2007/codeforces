#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
vector <int> adj[MAXN], ch[MAXN];
int dad[MAXN], dep[MAXN];
bool used[MAXN], good[MAXN];

struct cmp {
	bool operator()(const int &lhs, const int &rhs) const {
		if (dep[lhs] != dep[rhs])
			return dep[lhs] > dep[rhs];
		return lhs > rhs;
	}
};

set <int, cmp> S;

void load() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

void dfs(int x, int p) {
	for (auto it : adj[x])
		if (it != p) {
			ch[x].push_back(it);
			dep[it] = dep[x] + 1;
			dad[it] = x;
			dfs(it, x);
		}
}

int solve() {
	dfs(1, 0);
	
	for (int i = 1; i <= N; i++)
		S.insert(i);
		
	int sol = 0;
	while (!S.empty()) {
		int x = *S.begin();
		if (good[x]) {
			S.erase(x);
			continue;
		}
		int p = dad[x];
		if (dep[p] <= 1)
			break;
		if (!used[p]) {
			used[p] = true;
			good[dad[p]] = true;
			sol++;
		}
		for (auto it : ch[p])
			if (S.count(it))
				S.erase(it);
		S.erase(p);
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}