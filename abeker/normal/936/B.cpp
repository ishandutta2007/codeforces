#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N, M, S;
vector <int> E[MAXN];
bool bio[MAXN][2];
vector <int> path;
int clr[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		int c;
		scanf("%d", &c);
		E[i].resize(c);
		for (int j = 0; j < c; j++)
			scanf("%d", &E[i][j]);
	}
	scanf("%d", &S);
}

void finish() {
	puts("Win");
	for (auto it : path)
		printf("%d ", it);
	puts("");
	exit(0);
}

void dfs(int x, int c) {
	if (bio[x][c])
		return;
	path.push_back(x);
	bio[x][c] = true;
	if (E[x].empty() && c)
		finish();
	for (auto it : E[x])
		dfs(it, c ^ 1);
	path.pop_back();
}

void go(int x) {
	if (clr[x] == 2)
		return;
	if (clr[x] == 1) {
		puts("Draw");
		exit(0);
	}
	clr[x] = 1;
	for (auto it : E[x])
		go(it);
	clr[x] = 2;
}

void solve() {
	dfs(S, 0);
	go(S);	
	puts("Lose");
}

int main() {
	load();
	solve();
	return 0;
}