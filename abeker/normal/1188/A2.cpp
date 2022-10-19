#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e3 + 5;

struct triple {
	int a, b, c;
	void output() const {
		printf("%d %d %d\n", a, b, -c);
	}
};

int N;
vector <pii> adj[MAXN], ch[MAXN];
vector <triple> ops;
bool in[MAXN], leaf[MAXN];
int dad[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
}

void dfs(int x, int p) {
	dad[x] = p;
	for (auto it : adj[x])
		if (it.first != p) {
			ch[x].push_back(it);
			dfs(it.first, x);
		}
}

void add(int x, int y, int z) {
	ops.push_back({x, y, z});
}

void go() {
	for (int i = 1; i <= N; i++)
		leaf[i] = in[i] && ch[i].empty();
		
	int node = 0;
	for (int i = 1; i <= N; i++) {
		bool ok = in[i] && !leaf[i];
		for (auto it : ch[i])
			ok &= leaf[it.first];
		if (ok) {
			node = i;
			break;
		}
	}
	
	if (!node)
		return;
	
	int other = 0;
	for (int i = 1; i <= N; i++)
		if (leaf[i] && dad[i] != node) {
			other = i;
			break;
		}
		
	vector <pii> memo = ch[node];
	ch[node].clear();
	for (auto it : memo)
		in[it.first] = false;
		
	go();
	
	ch[node] = memo;
	for (auto it : memo)
		in[it.first] = true;
	
	pii &child = memo[0];
	for (auto &it : ops) {
		if (it.a == node) {
			it.a = child.first;
			child.second += it.c;
		}
		if (it.b == node) {
			it.b = child.first;
			child.second += it.c;
		}
	}
	
	if (other) 
		for (int i = 0; i < memo.size(); i++) {
			pii curr = memo[i];
			pii nxt = memo[(i + 1) % memo.size()];
			add(other, curr.first, -curr.second / 2);
			add(other, nxt.first, curr.second / 2);
			add(curr.first, nxt.first, -curr.second / 2);
		}
	else {
		for (int i = 3; i < memo.size(); i++) { 
			add(memo[0].first, memo[i].first, -memo[i].second);
			memo[0].second -= memo[i].second;
		}
		int sum = 0;
		for (int i = 0; i < 3; i++)
			sum += memo[i].second;
		for (int i = 0; i < 2; i++)
			for (int j = i + 1; j < 3; j++)
				add(memo[i].first, memo[j].first, sum / 2 - memo[i].second - memo[j].second);
	}
}

void solve() {
	if (N == 2) {
		printf("YES\n1\n%d %d %d\n", 1, 2, adj[1][0].second);
		return;
	}
	
	int root = 0;
	for (int i = 1; i <= N; i++) {
		if (adj[i].size() == 2) {
			puts("NO");
			return;
		}
		if (adj[i].size() > 1)
			root = i;
	}
	
	dfs(root, 0);
	
	for (int i = 1; i <= N; i++)	
		in[i] = true;
		
	go();
	
	puts("YES");
	printf("%d\n", ops.size());
	for (auto it : ops)
		it.output();
}

int main() {
	load();
	solve();
	return 0;
}