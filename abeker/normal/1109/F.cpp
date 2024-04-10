#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1e3 + 5;
const int MAXS = 2e5 + 5;
const int offset = 1 << 18;

struct node {
	int mini, occ, lazy;
};

int N, M, S;
int f[MAXN][MAXN];
node tour[2 * offset];
vector <pii> todo[2 * offset];
vector <int> lft[offset], rig[offset];
stack <pair <int*, int>> ch;
int dad[MAXS], rnk[MAXS];
int cycle[offset];
int curr;

void add_edge(int x, int y) {
	if (x > y)
		swap(x, y);
	rig[x].push_back(y);
	lft[y].push_back(x);
}

void load() {
	scanf("%d%d", &N, &M);
	curr = S = N * M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", f[i] + j);
			if (i)
				add_edge(f[i][j], f[i - 1][j]);
			if (j)	
				add_edge(f[i][j], f[i][j - 1]);
		}
}

void insert(int x, int lo, int hi, int from, int to, pii edge) {
	if (lo >= to || hi <= from)
		return;
	if (lo >= from && hi <= to) {
		todo[x].push_back(edge);
		return;
	}
	int mid = (lo + hi) / 2;
	insert(2 * x, lo, mid, from, to, edge);
	insert(2 * x + 1, mid, hi, from, to, edge);
}

void revert(int sz) {
	for (; ch.size() > sz; ch.pop())
		*ch.top().first = ch.top().second;
}

void modify(int *ptr, int val) {
	ch.push({ptr, *ptr});
	*ptr = val;
}

int find(int x) {
	return dad[x] == x ? x : find(dad[x]);
}

bool join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return false;
	if (rnk[x] > rnk[y])
		swap(x, y);
	modify(dad + x, y);
	if (rnk[x] == rnk[y])
		modify(rnk + y, rnk[y] + 1);
	return true;
}

void dfs(int x) {
	int len = ch.size();
	for (auto it : todo[x])
		join(it.first, it.second);
	if (x < offset) {
		dfs(2 * x + 1);
		dfs(2 * x);
	}
	else {
		for (; curr; curr--) {
			bool ok = true;
			int tmp = ch.size();
			for (auto it : rig[curr])
				if (it <= x - offset)
					ok &= join(curr, it);
			if (!ok) {
				revert(tmp);
				break;
			}
			for (auto it : rig[curr])
				if (it <= x - offset) 
					insert(1, 0, offset, it, x - offset, {curr, it});
		}
		cycle[x - offset] = curr;
	}
	revert(len);
}

node merge(node l, node r) {
	return {min(l.mini, r.mini), (l.mini <= r.mini ? l.occ : 0) + (r.mini <= l.mini ? r.occ : 0), 0};
}

void prop(int x) {
	tour[x].mini += tour[x].lazy;
	if (x < offset) {
		tour[2 * x].lazy += tour[x].lazy;
		tour[2 * x + 1].lazy += tour[x].lazy;
	}
	tour[x].lazy = 0;
}

void update(int x, int lo, int hi, int from, int to, int val) {
	prop(x);
	if (lo >= to || hi <= from)
		return;
	if (lo >= from && hi <= to) {
		tour[x].mini += val;
		if (x < offset) {
			tour[2 * x].lazy += val;
			tour[2 * x + 1].lazy += val;
		}
		return;
	}
	int mid = (lo + hi) / 2;
	update(2 * x, lo, mid, from, to, val);
	update(2 * x + 1, mid, hi, from, to, val);
	tour[x] = merge(tour[2 * x], tour[2 * x + 1]);
}

void update(int from, int to, int val) {
	update(1, 0, offset, from, to, val);
}

node query(int x, int lo, int hi, int from, int to) {
	prop(x);
	if (lo >= to || hi <= from)
		return {offset, 1, 0};
	if (lo >= from && hi <= to)	
		return tour[x];
	int mid = (lo + hi) / 2;
	return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

ll solve() {
	for (int i = 1; i <= S; i++)
		dad[i] = i;
		
	dfs(1);
	
	for (int i = 0; i < offset; i++)
		tour[i + offset] = {0, 1, 0};
	for (int i = offset - 1; i >= 0; i--)
		tour[i] = merge(tour[2 * i], tour[2 * i + 1]);
			
	ll sol = 0;
	for (int i = 1; i <= S; i++) {
		update(1, i + 1, 1);
		for (auto it : lft[i])
			update(1, it + 1, -1);
		node tmp = query(1, 0, offset, cycle[i] + 1, i + 1);
		if (tmp.mini == 1)
			sol += tmp.occ;
	}
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}