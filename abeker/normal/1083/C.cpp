#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> node;
#define u first
#define v second

const int MAXN = 2e5 + 5;
const int offset = 1 << 18;
const int LOG = 18;

int N, Q;
node t[2 * offset];
int perm[MAXN];
int anc[MAXN][LOG];
vector <int> ch[MAXN];
int disc[MAXN], fin[MAXN];
int dep[MAXN];
int timer;

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) 
		scanf("%d", perm + i);
	for (int i = 2; i <= N; i++) {
		scanf("%d", anc[i]);
		ch[anc[i][0]].push_back(i);
		dep[i] = dep[anc[i][0]] + 1;
	}
}

void dfs(int x) {
	disc[x] = timer++;
	for (auto it : ch[x])
		dfs(it);
	fin[x] = timer;
}

int lca(int a, int b) {
	if (dep[a] < dep[b])
		swap(a, b);
	int diff = dep[a] - dep[b];
	for (int i = 0; i < LOG; i++)
		if (diff >> i & 1)
			a = anc[a][i];
	if (a == b)
		return a;
	for (int i = LOG - 1; i >= 0; i--)
		if (anc[a][i] != anc[b][i]) {
			a = anc[a][i];
			b = anc[b][i];
		}
	return anc[a][0];
}

inline bool sub(int x, int y) {
	return disc[y] >= disc[x] && disc[y] < fin[x];
}

node merge(node lft, node rig) {
	if (!lft.u)
		return rig;
	if (!rig.u)
		return lft;
	if (lft.u == -1 || rig.u == -1)
		return {-1, -1};
		
	vector <int> c = {lft.u, lft.v, rig.u, rig.v};
		
	if (dep[c[0]] > dep[c[1]])
		swap(c[0], c[1]);
	if (dep[c[0]] > dep[c[2]])
		swap(c[0], c[2]);
	if (dep[c[1]] > dep[c[2]])
		swap(c[1], c[2]);
		
	int l = 0;
	node path = {-1, -1};
	bool s1 = sub(c[0], c[1]);
	bool s2 = sub(c[0], c[2]);
	if (s1 && s2) {
		l = lca(c[1], c[2]);
		if (l == c[1]) {
			l = c[0];
			path = {c[0], c[2]};
		}
		else if (l == c[0])
			path = {c[1], c[2]};
		else
			return path;
	}
	else {
		if (!s1 && !s2) {
			if (!sub(c[1], c[2]))
				return path;
			path = {c[0], c[2]};
		}
		else 
			path = {c[1], c[2]};
		l = lca(path.u, path.v);
	}
	
	if (dep[path.u] > dep[path.v])
		swap(path.u, path.v);
	
	if (sub(path.u, path.v)) {
		if (!sub(path.u, c[3]) || lca(c[3], path.v) == path.u)
			return {c[3], path.v};
		if (sub(c[3], path.v))
			return path;
		if (sub(path.v, c[3]))
			return {path.u, c[3]};
		return {-1, -1};
	}
		
	if (!sub(l, c[3]))
		return {-1, -1};
	if (sub(c[3], path.u) || sub(c[3], path.v))
		return path;
	if (sub(path.u, c[3]))
		return {c[3], path.v};
	if (sub(path.v, c[3]))
		return {path.u, c[3]};
	return {-1, -1};
}

void update(int x, int val) {
	x += offset;
	t[x] = {val, val};
	for (x /= 2; x; x /= 2)
		t[x] = merge(t[2 * x], t[2 * x + 1]);
}

int query() {
	int x = 1;
	int lo = 0, hi = offset;
	node curr = {0, 0};
	while (hi - lo > 1) {
		int mid = (lo + hi) / 2;
		node nxt = merge(curr, t[2 * x]);
		if (nxt.u == -1) {
			hi = mid;
			x = 2 * x;
		}
		else {
			curr = nxt;
			lo = mid;
			x = 2 * x + 1;
		}
	}
	return min(lo, N);
}

void solve() {
	dfs(1);
	
	for (int j = 1; j < LOG; j++)
		for (int i = 1; i <= N; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
	
	for (int i = 1; i <= N; i++)
		t[perm[i] + offset] = {i, i};
	
	for (int i = offset - 1; i >= 0; i--)
		t[i] = merge(t[2 * i], t[2 * i + 1]);
	
	scanf("%d", &Q);
	while (Q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			swap(perm[x], perm[y]);
			update(perm[x], x);
			update(perm[y], y);
		}
		else
			printf("%d\n", query());
	}
}

int main() {
	load();
	solve();
	return 0;
}