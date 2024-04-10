#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;
const int offset = 1 << 18;

struct node {
	int lazy, mx, occ;
};

int N, Q;
node t[2 * offset];
vector <int> adj[MAXN];
vector <pii> ch[MAXN];
int disc[MAXN], fin[MAXN];
map <pii, bool> in;
int timer, cnt;

void load() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void dfs(int x, int p) {
	disc[x] = timer++;
	for (auto it : adj[x])
		if (it != p) {
			dfs(it, x);
			ch[x].push_back({fin[it], it});
		}
	fin[x] = timer;
}

node merge(node l, node r) {
	return {l.lazy + r.lazy, max(l.mx, r.mx), (l.mx >= r.mx) * l.occ + (r.mx >= l.mx) * r.occ};
}

void prop(int x) {
	t[x].mx += t[x].lazy;
	if (x < offset) {
		t[2 * x].lazy += t[x].lazy;
		t[2 * x + 1].lazy += t[x].lazy;
	}
	t[x].lazy = 0;
}

void update(int x, int lo, int hi, int from, int to, int val) {
	prop(x);
	if (lo >= to || hi <= from)
		return;
	if (lo >= from && hi <= to) {
		t[x].mx += val;
		if (x < offset) {
			t[2 * x].lazy += val;
			t[2 * x + 1].lazy += val;
		}
		return;
	}
	int mid = (lo + hi) / 2;
	update(2 * x, lo, mid, from, to, val);
	update(2 * x + 1, mid, hi, from, to, val);
	t[x] = merge(t[2 * x], t[2 * x + 1]);
}

void update(int from, int to, int val) {
	update(1, 0, offset, from, to, val);
}

bool subtree(int x, int y) {
	return disc[x] >= disc[y] && disc[x] < fin[y];
}

void add(int u, int v, int c) {
	if (subtree(v, u))
		swap(u, v);
	update(disc[u], fin[u], c);
	if (subtree(u, v)) {
		v = lower_bound(ch[v].begin(), ch[v].end(), pii(disc[u] + 1, 0)) -> second;
		update(0, disc[v], c);
		update(fin[v], N, c);
	}
	else 
		update(disc[v], fin[v], c);
	cnt += c;
}

void solve() {
	dfs(1, 0);
	
	for (int i = 0; i < offset; i++)
		t[i + offset] = {0, (i < N) - 1, 1};
	
	for (int i = offset - 1; i >= 0; i--)
		t[i] = merge(t[2 * i], t[2 * i + 1]);
		
	while (Q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (u > v)
			swap(u, v);
		add(u, v, in[{u, v}] ? -1 : 1);
		in[{u, v}] ^= 1;
		printf("%d\n", t[1].mx < cnt ? 0 : t[1].occ);
	}
}

int main() {
	load();
	solve();
	return 0;
}