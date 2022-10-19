#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int N;
vector <int> adj[MAXN];
vector <int> labels[2];
int sub[MAXN], num[MAXN];
bool in[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int dfs(int x, int p) {
	sub[x] = 1;
	for (auto it : adj[x])
		if (it != p)
			sub[x] += dfs(it, x);
	return sub[x];
}

void go(int x, int p, bool f) {
	num[x] = labels[f].back();
	labels[f].pop_back();
	printf("%d %d %d\n", x, p, num[x] - num[p]); 
	for (auto it : adj[x])
		if (it != p)
			go(it, x, f);
}

void construct(int root, int n) {
	int m = N - 1 - n;
	for (int i = n; i; i--)
		labels[1].push_back(i * m);
	for (int i = m; i; i--)
		labels[0].push_back(i);
	for (auto it : adj[root])
		go(it, root, in[it]);
	exit(0);
}

void check(int root) {
	dfs(root, 0);
	
	int big = 0;
	for (auto it : adj[root]) {
		if (sub[it] > N / 2)
			return;
		if (sub[it] >= N / 3)
			big = it;
	}
	
	if (big) {
		in[big] = true;
		construct(root, sub[big]);
		return;
	}

	int sum = 0;
	for (auto it : adj[root]) {
		in[it] = true;
		sum += sub[it];
		if (sum >= N / 3) {
			construct(root, sum);
			return;
		}
	}
}

void solve() {
	for (int i = 1; i <= N; i++)
		check(i);
}

int main() {
	load();
	solve();
	return 0;
}