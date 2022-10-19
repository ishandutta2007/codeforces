#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 5;

int N, M;
bitset <MAXN> part[MAXN];
unordered_set <int> subset[MAXN], group[MAXN];
unordered_set <int> all;
int parent[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		part[i].reset();
		subset[i].clear();
	}
	all.clear();
	for (int i = 0; i < M; i++) {
		char buff[MAXN];
		scanf("%s", buff);
		group[i].clear();
		for (int j = 0; j < N; j++)
			if (buff[j] - '0') {
				part[j].set(i);
				group[i].insert(j);
				all.insert(j);
			}
	}
}

bool is_subset(int x, int y) {
	return x != y && (part[x] & part[y]) == part[x];
}

void update(int x, int y) {
	if (is_subset(x, y)) 
		subset[x].insert(y);
	else
		subset[x].erase(y);
}

void remove_singleton(int x) {
	int who = *group[x].begin();
	group[x].erase(who);
	part[who].reset(x);
	for (auto it : all) {
		update(who, it);
		update(it, who);
	}
}

int find_leaf() {
	for (auto it : all)
		if (!subset[it].empty())
			return it;
	return -1;
}

void remove_node(int x) {
	for (int i = 0; i < M; i++)
		group[i].erase(x);
	for (auto it : all)
		subset[it].erase(x);
	all.erase(x);
}

void output() {
	for (auto it : all) {
		printf("%d: ", it);
		for (int j = 0; j < M; j++)
			printf("%d", part[it].test(j));
		puts("");
	}
	puts("------------");
}

void solve() {
	memset(parent, -1, sizeof parent);
	
	for (int i = 0; i < N; i++)
		if (!all.count(i))
			parent[i] = *all.begin();
	
	for (auto i : all)
		for (auto j : all)
			update(i, j);
	
	while (all.size() > 1) {
		for (int i = 0; i < M; i++)
			if (group[i].size() == 1)
				remove_singleton(i);
		int leaf = find_leaf();
		if (leaf == -1) {
			puts("NO");
			return;
		}
		parent[leaf] = *subset[leaf].begin();
		remove_node(leaf);
	}
	
	puts("YES");
	for (int i = 0; i < N; i++)
		if (parent[i] != -1)
			printf("%d %d\n", i + 1, parent[i] + 1);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		solve();
	}
	return 0;
}