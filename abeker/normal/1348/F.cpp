#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;

int N;
int a[MAXN], b[MAXN];
vector <int> in[MAXN], out[MAXN];
int ans[MAXN], interval[MAXN];
set <int> white, gray;
stack <int> path;

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", a + i, b + i);
		in[a[i]].push_back(i);
		out[b[i]].push_back(i);
	}
}

void output() {
	for (int i = 1; i <= N; i++)
		printf("%d ", ans[i]);
	puts("");
}

void construct_matching() {
	set <pii> active;
	for (int i = 1; i <= N; i++) {
		for (auto it : in[i])
			active.insert({b[it], it});
		pii least = *active.begin();
		interval[i] = least.second;
		ans[least.second] = i;
		active.erase(least);
		for (auto it : out[i])
			active.erase({b[it], it});
	}
}

int get_first(set <int> &s, int lo, int hi) {
	if (s.empty())
		return 0;
	auto it = s.lower_bound(lo);
	if (it == s.end() || *it > hi)
		return 0;
	return *it;
}

void finish(int node) {
	puts("NO");
	output();
	vector <int> cycle;
	for (; path.top() != node; path.pop())
		cycle.push_back(path.top());
	cycle.push_back(node);
	reverse(cycle.begin(), cycle.end());
	int tmp = ans[node];
	for (int i = 0; i < (int)cycle.size() - 1; i++)
		ans[cycle[i]] = ans[cycle[i + 1]];
	ans[cycle.back()] = tmp;
	output();
	exit(0);
}

void dfs(int x) {
	path.push(x);
	white.erase(ans[x]);
	gray.insert(ans[x]);
	while (1) {
		int tmp = get_first(white, a[x], b[x]);
		if (!tmp)
			break;
		dfs(interval[tmp]);
	}
	gray.erase(ans[x]);
	int tmp = get_first(gray, a[x], b[x]);
	if (tmp)
		finish(interval[tmp]);
	path.pop();
}

void rotate_matching() {
	for (int i = 1; i <= N; i++)
		white.insert(i);
	for (int i = 1; i <= N; i++)
		if (white.count(ans[i]))
			dfs(i);
}

void solve() {
	construct_matching();
	rotate_matching();
	puts("YES");
	output();
}

int main() {
	load();
	solve();
	return 0;
}