#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 5;

int N;
int root;
vector <int> ch[MAXN];
int smaller[MAXN];
int subtree[MAXN];
int ans[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int parent;
		scanf("%d%d", &parent, smaller + i);
		if (parent)
			ch[parent].push_back(i);
		else
			root = i;
	}
}

int calc(int x) {
	subtree[x] = 1;
	for (auto it : ch[x])
		subtree[x] += calc(it);
	return subtree[x];
}

void inc(int x, int val) {
	if (ans[x] > val)
		ans[x]++;
	for (auto it : ch[x])
		inc(it, val);
}

void shift(int x, int val) {
	ans[x] += val;
	for (auto it : ch[x])
		shift(it, val);
}

void dfs(int x) {
	for (auto it : ch[x])
		dfs(it);
	int ptr = 0;
	for (auto it : ch[x]) {
		shift(it, ptr);
		ptr += subtree[it];
	}
	if (ptr < smaller[x]) {
		puts("NO");
		exit(0);
	}
	inc(x, smaller[x]);
	ans[x] = smaller[x] + 1;
}

void solve() {
	calc(root);
	dfs(root);
	puts("YES");
	for (int i = 1; i <= N; i++)
		printf("%d ", ans[i]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}