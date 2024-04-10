#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;

int N;
vector <pii> E[MAXN];
int sz[MAXN];
int mini = MAXN, centroid;
deque <int> nodes[MAXN];
int val[MAXN], who[MAXN];
ll sol;

struct cmp1 {
	bool operator()(const int &lhs, const int &rhs) const {
		return nodes[lhs].front() < nodes[rhs].front();
	}
};

struct cmp2 {
	bool operator()(const int &lhs, const int &rhs) const {
		if (val[lhs] == val[rhs])
			return lhs < rhs;
		return val[lhs] < val[rhs];
	}
};

set <int, cmp1> S1;
set <int, cmp2> S2;

void load() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		E[a].push_back({b, c});
		E[b].push_back({a, c});
	}
}

void dfs(int x, int p) {
	sz[x] = 1;
	int mx = 0;
	for (auto it : E[x])
		if (it.first != p) {
			dfs(it.first, x);
			mx = max(mx, sz[it.first]);
			sz[x] += sz[it.first];
			sol += 2ll * it.second * min(sz[it.first], N - sz[it.first]);
		}
	mx = max(mx, N - sz[x]);
	if (mx < mini) {
		mini = mx;
		centroid = x;
	}
}

void go(int x, int p, int root) {
	nodes[root].push_back(x);
	who[x] = root;
	if (x == centroid)
		return;
	for (auto it : E[x])
		if (it.first != p)
			go(it.first, x, root);
}

void update(int x) {
	S2.erase(x);
	val[x]++;
	S2.insert(x);
}

void add(int x, int y) {
	printf("%d ", nodes[y].front());
	update(x);
	update(y);
	S1.erase(y);
	nodes[y].pop_front();
	if (!nodes[y].empty())
		S1.insert(y);
}

void connect(int x) {
	auto it = S2.begin();
	for (int i = 0; i < 2 && it != S2.end(); i++) {
		if (*it != who[x] && val[*it] == x - 1) {
			add(who[x], *it);
			return;
		}
		it++;
	}
	
	auto it1 = S1.begin();
	for (int i = 0; i < 2 && it1 != S1.end(); i++) {
		if (x == centroid || *it1 != who[x]) {
			add(who[x], *it1);
			return;
		}
		it1++;
	}
}

void solve() {
	dfs(1, 0);
	
	E[centroid].push_back({centroid, 0});
	for (auto it : E[centroid]) {
		int tmp = it.first;
		go(tmp, centroid, tmp);
		sort(nodes[tmp].begin(), nodes[tmp].end());
		val[tmp] = tmp == centroid ? MAXN : N - 2 * (int)nodes[tmp].size();
		S1.insert(tmp);
		S2.insert(tmp);
	}
		
	printf("%lld\n", sol);
	for (int i = 1; i <= N; i++)
		connect(i);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}