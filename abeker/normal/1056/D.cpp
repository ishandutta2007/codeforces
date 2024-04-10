#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
int dad[MAXN];
vector <int> ch[MAXN];
int leaves[MAXN];
int sub[MAXN];
int happy[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		scanf("%d", dad + i);
		ch[dad[i]].push_back(i);
	}
}

void dfs(int x) {
	sub[x] = 1;
	leaves[x] = ch[x].empty();
	for (auto it : ch[x]) {
		dfs(it);
		sub[x] += sub[it];
		leaves[x] += leaves[it];
	}
}

void solve() {
	dfs(1);
	
	for (int i = 1; i <= N; i++) {
		happy[leaves[i]] += sub[i];
		if (i > 1)
			happy[leaves[dad[i]]] -= sub[i];
	}
	
	for (int i = 1; i <= N; i++) 
		happy[i] += happy[i - 1];
	
	int ptr = 1;
	for (int i = 1; i <= N; i++) {
		while (ptr <= N && happy[ptr] < i)
			ptr++;
		printf("%d ", ptr);
	}
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}