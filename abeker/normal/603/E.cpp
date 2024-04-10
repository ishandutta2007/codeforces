#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;
const int offset = 1 << 19;

struct edge {
	int a, b, weight, id;
	void input(int x) {
		scanf("%d%d%d", &a, &b, &weight);
		id = x;
	}
	bool operator <(const edge &rhs) const {
		return weight < rhs.weight;
	}
};

int N, M;
edge e[MAXN];
int cnt_parity[2];
int dad[MAXN], sz[MAXN];
vector <edge> todo[2 * offset];
vector <pair <int*, int>> ch;
int ans[offset];
int lim;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) 
		e[i].input(i);
}

void update(int x, int lo, int hi, int from, int to, edge toadd) {
	if (lo >= to || hi <= from)
		return;
	if (lo >= from && hi <= to) {
		todo[x].push_back(toadd);
		return;
	}
	int mid = (lo + hi) / 2;
	update(2 * x, lo, mid, from, to, toadd);
	update(2 * x + 1, mid, hi, from, to, toadd);
}

void revert(int sz) {
	for (; ch.size() > sz; ch.pop_back())
		*ch.back().first = ch.back().second;
}

void modify(int *ptr, int val) {
	ch.push_back({ptr, *ptr});
	*ptr = val;
}

int find(int x) {
	return dad[x] == x ? x : find(dad[x]);
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (sz[x] > sz[y])
		swap(x, y);
	for (int i = 0; i < 2; i++)
		modify(cnt_parity + i, cnt_parity[i] - (sz[x] % 2 == i) - (sz[y] % 2 == i) + ((sz[x] + sz[y]) % 2 == i));
	modify(dad + x, y);
	modify(sz + y, sz[x] + sz[y]);
}

void dfs(int x) {
	int len = ch.size();
	for (auto it : todo[x])
		join(it.a, it.b);
	if (x < offset) {
		dfs(2 * x + 1);
		dfs(2 * x);
	}
	else {
		for (; lim < M && cnt_parity[1]; lim++)
			if (e[lim].id <= x - offset) {
				update(1, 0, offset, e[lim].id, x - offset, e[lim]);
				join(e[lim].a, e[lim].b);		
			}
		ans[x - offset] = cnt_parity[1] ? -1 : e[lim - 1].weight;
	}
	revert(len);
}

void solve() {
	sort(e, e + M);
	
	cnt_parity[1] = N;
	for (int i = 1; i <= N; i++) {
		dad[i] = i;
		sz[i] = 1;
	}
		
	dfs(1);
	
	for (int i = 0; i < M; i++)
		printf("%d\n", ans[i]);
}

int main() {
	load();
	solve();
	return 0;
}