#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 5e4 + 5;

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
		void at_most_one(const vector <pii> &v) {
			int sz = v.size();
			add_variables(sz);
			for (int i = 0; i < sz; i++) {
				add_implication(v[i].first, v[i].second, n - i - 1, 0);
				if (i) {
					add_implication(n - i, 0, n - i - 1, 0);
					add_implication(n - i, 0, v[i].first, !v[i].second);
				}
			}
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
unordered_map <int, vector <pii>> byColour[MAXN];
vector <pii> adj[MAXN];
pii e[MAXN];

void add_edge(int node, int clr, int idx) {
	byColour[node][clr].push_back({idx, 1});
	adj[node].push_back({idx, 0});
}

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b, c, t;
		scanf("%d%d%d%d", &a, &b, &c, &t);
		add_edge(a, c, i);
		add_edge(b, c, i);
		e[i] = {t, i};
	}
}

bool check(int lim, bool recon) {
	TwoSat Edges(M);
	for (int i = lim; i < M; i++)
		Edges.set_variable(e[i].second, false);
	for (int i = 1; i <= N; i++) {
		Edges.at_most_one(adj[i]);
		for (auto it : byColour[i]) 
			Edges.at_most_one(it.second);
	}
	if (!Edges.solve()) {
		if (recon) 
			puts("No");
		return false;
	}
	if (recon) {
		vector <int> roads;
		for (int i = 0; i < M; i++)
			if (Edges.get(i, 0))
				roads.push_back(i);
		printf("Yes\n%d %d\n", lim ? e[lim - 1].first : 0, roads.size());
		for (auto it : roads)
			printf("%d ", it + 1);
		puts("");
	}
	return true;
}

void solve() {
	sort(e, e + M);
	int lo = 0, hi = M;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (check(mid, false))
			hi = mid;
		else
			lo = mid + 1;
	}
	check(lo, true);
}

int main() {
	load();
	solve();
	return 0;
}