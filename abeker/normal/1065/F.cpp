#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int N, K;
vector <int> ch[MAXN];
int ord[MAXN], ret[MAXN];
int dep[MAXN];

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 2; i <= N; i++) {
		int p;
		scanf("%d", &p);
		ch[p].push_back(i);
	}
}

int dfs(int x) {
	dep[x] = N;
	for (auto it : ch[x])
		dep[x] = min(dep[x], dfs(it) + 1);
	if (ch[x].empty())
		dep[x] = 0;
	return dep[x];
}

void go(int x) {
	for (auto it : ch[x])
		go(it);
		
	for (auto it : ch[x]) 
		ret[x] += ret[it];
	
	for (auto it : ch[x])
		ord[x] = max(ord[x], ret[x] - ret[it] + ord[it]);
	
	if (dep[x] >= K)
		ret[x] = 0;
	
	if (ch[x].empty())
		ord[x] = ret[x] = 1;
}

int solve() {
	dfs(1);
	go(1);
	return ord[1];
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}