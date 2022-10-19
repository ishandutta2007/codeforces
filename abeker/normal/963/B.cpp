#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
vector <int> E[MAXN];
int sub[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		if (x) {
			E[x].push_back(i);
			E[i].push_back(x);
		}
	}
}

int calc(int x, int p) {
	sub[x] = 1;
	for (auto it : E[x])
		if (it != p)
			sub[x] += calc(it, x);
	return sub[x];
}

void dfs(int x, int p) {
	for (auto it : E[x])
		if (it != p && !(sub[it] % 2))
			dfs(it, x);
	printf("%d\n", x);
	for (auto it : E[x])
		if (it != p && sub[it] % 2)
			dfs(it, x);
}
	
void solve() {
	if (!(N % 2)) {
		puts("NO");
		return;
	}
	
	calc(1, 0);
	
	puts("YES");
	
	dfs(1, 0);
}

int main() {
	load();
	solve();
	return 0;
}