#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 5;

int n;
int c[N];
int L[N], R[N];
vector<int> G[N];

void dfs(int p, int col) {
	if (c[p]) {
		return;
	}
	c[p] = col;
	for (auto e : G[p]) {
		dfs(e, 3 - col);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", L + i, R + i);
		G[L[i]].push_back(R[i]);
		G[R[i]].push_back(L[i]);
	}
	for (int i = 1; i <= n; i++) {
		G[2 * i - 1].push_back(2 * i);
		G[2 * i].push_back(2 * i - 1);
	}
	for (int i = 1; i <= (n << 1); i++)
		dfs(i, 1);
	for (int i = 1; i <= n; i++) {
		printf("%d %d\n", c[L[i]], c[R[i]]);
	}
	return 0;
}