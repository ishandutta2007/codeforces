#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;
const int offset = 1 << 17;
const int LOG = 17;

class TwoSat {
	int n;
	vector <int> sol;
	vector <bool> bio;
	vector <int> comp;
	vector <vector <int>> adj, rev;
	stack <int> order;
	public:
		void add_variables(int vars) {
			n += vars;
			for (int i = 0; i < 2 * vars; i++) {
				sol.push_back(0);
				bio.push_back(false);
				comp.push_back(0);
				adj.push_back(vector <int> ());
				rev.push_back(vector <int> ());
			}
		}
		TwoSat(int _n) {
			n = 0;
			add_variables(_n);
		}
		TwoSat(){}
		void add_edge(int u, int v) {
			adj[u].push_back(v);
			rev[v].push_back(u);
		}
		void add_implication(int u1, int neg1, int u2, int neg2) {
			add_edge(2 * u1 + neg1, 2 * u2 + neg2);
			add_edge(2 * u2 + !neg2, 2 * u1 + !neg1);
		}
		void set_variable(int u, bool val) {
			add_implication(u, val, u, !val);
		}
		int at_most_one(const vector <pii> &v) {
			int sz = v.size();
			add_variables(sz);
			for (int i = 0; i < sz; i++) {
				add_implication(v[i].first, v[i].second, n - i - 1, 0);
				if (i) {
					add_implication(n - i, 0, n - i - 1, 0);
					add_implication(n - i, 0, v[i].first, !v[i].second);
				}
			}
			return n - sz;
		}
		void dfs_forward(int x) {
			bio[x] = true;
			for (auto it : adj[x])
				if (!bio[it])
					dfs_forward(it);
			order.push(x);
		}
		void dfs_backward(int x, int c) {
			comp[x] = c;
			for (auto it : rev[x])
				if (!comp[it])
					dfs_backward(it, c);
		}
		bool solve() {
			for (int i = 0; i < 2 * n; i++)
				if (!bio[i])
					dfs_forward(i);
			int ptr = 0;
			for (; !order.empty(); order.pop())
				if (!comp[order.top()])
					dfs_backward(order.top(), ++ptr);
			for (int i = 0; i < 2 * n; i++) {
				if (comp[i] == comp[i ^ 1])
					return false;
				sol[i] = comp[i] > comp[i ^ 1];
			}
			return true;
		}
		int get(int u, int neg) {
			return sol[2 * u + neg];
		}
};

int N, M;
TwoSat Edges;
int anc[MAXN][LOG];
int dep[MAXN], subtree[MAXN];
vector <int> adj[MAXN], ch[MAXN];
int head[MAXN], idx[MAXN], pos[MAXN];
vector <pii> toDo[2 * offset];
vector <pii> toRoot;
int chain, ptr;

void load() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int dfs_prep(int x, int p) {
	anc[x][0] = p;
	for (int i = 1; i < LOG; i++)
		anc[x][i] = anc[anc[x][i - 1]][i - 1];
	subtree[x] = 1;
	for (auto it : adj[x])
		if (it != p) {
			dep[it] = dep[x] + 1;
			subtree[x] += dfs_prep(it, x);
			ch[x].push_back(it);
		}
	return subtree[x];
}

void dfs_hld(int x) {
	if (!head[chain])
		head[chain] = x;
	idx[x] = chain;
	pos[x] = ptr++;
	int heavy = 0;
	for (auto it : ch[x])
		if (subtree[it] > subtree[heavy])
			heavy = it;
	if (heavy)
		dfs_hld(heavy);
	for (auto it : ch[x])
		if (it != heavy) {
			chain++;
			dfs_hld(it);
		}
}

void update(int x, int lo, int hi, int from, int to, pii var) {
	if (lo >= to || hi <= from)
		return;
	if (lo >= from && hi <= to) {
		toDo[x].push_back(var);
		return;
	}
	int mid = (lo + hi) / 2;
	update(2 * x, lo, mid, from, to, var);
	update(2 * x + 1, mid, hi, from, to, var);
}

void update(int from, int to, pii var) {
	update(1, 0, offset, from, to, var);
}

void dfs_tour(int x) {
	if (!toDo[x].empty())
		toRoot.push_back({Edges.at_most_one(toDo[x]), 0});
	if (x >= offset) 
		Edges.at_most_one(toRoot);
	else {
		dfs_tour(2 * x);
		dfs_tour(2 * x + 1);
	}
	if (!toDo[x].empty())
		toRoot.pop_back();
}

int lca(int x, int y) {
	if (dep[x] < dep[y])
		swap(x, y);
	int diff = dep[x] - dep[y];
	for (int i = 0; i < LOG; i++)
		if (diff >> i & 1)
			x = anc[x][i];
	if (x == y)
		return x;
	for (int i = LOG - 1; i >= 0; i--)
		if (anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	return anc[x][0];
}

void go_up(int x, int y, pii var) {
	while (1) {
		if (idx[x] == idx[y]) {
			update(pos[y] + 1, pos[x] + 1, var);
			break;
		}
		update(pos[head[idx[x]]], pos[x] + 1, var);
		x = anc[head[idx[x]]][0];
	}
}

void add_path(int p, int q, pii var) {
	int l = lca(p, q);
	go_up(p, l, var);
	go_up(q, l, var);
}

void solve() {
	dfs_prep(1, 0);
	dfs_hld(1);
	
	scanf("%d", &M);
	Edges = TwoSat(M);
	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		add_path(a, b, {i, 0});
		add_path(c, d, {i, 1});
	}
	
	dfs_tour(1);
	
	if (!Edges.solve()) {
		puts("NO");
		return;
	}
	puts("YES");
	for (int i = 0; i < M; i++)
		printf("%d\n", Edges.get(i, 1) + 1);
}

int main() {
	load();
	solve();
	return 0;
}