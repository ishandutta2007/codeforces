#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
vector<int> G[N];

int sz[N];
int get_sz(int p, int fa) {
	sz[p] = 1;
	for (auto e : G[p])
		if (e ^ fa)
			sz[p] += get_sz(e, p);
	return sz[p];
}

int res[N];
long long ans;
vector<int> vi[N], vo[N];
void dfs(int p, int fa, int id, int d) {
	vi[id].push_back(p);
	vo[id].push_back(p);
	ans += d;
	for (auto e : G[p]) {
		if (e != fa) {
			dfs(e, p, id, d + 1);
		}
	}
}

typedef class Node {
	public:
		int p;

		Node() {}
		Node(int p) : p(p) {	}

		bool operator < (Node b) const {
			if (sum() ^ b.sum())
				return sum() > b.sum();
			return p < b.p;
		}
		int sum() const {
			return vi[p].size() + vo[p].size();
		}
} Node;

set<Node> Q;
set<int> Si, So;

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	get_sz(1, 0);
	int g = 1, ng = 1;
	do {
		g = ng;
		for (auto e : G[g]) {
			if (sz[e] < sz[g] && (sz[e] << 1) > n) {
				ng = e;
			}
		}
	} while (ng ^ g);
	for (auto e : G[g]) {
		dfs(e, g, e, 1);
		Q.insert(Node(e));
		Si.insert(e);
		So.insert(e);
	}
	vi[g].push_back(g);
	vo[g].push_back(g);
	Si.insert(g);
	So.insert(g);
	Q.insert(Node(g));
	ans <<= 1;
	
	auto add = [&] (int x, int y) {
		res[vo[x].back()] = vi[y].back();
		vo[x].pop_back();
		vi[y].pop_back();
	};

	while (Q.size() >= 2u) {
		Node a = *Q.begin();
		Q.erase(Q.begin());
		Node b = *Q.begin();
		Q.erase(Q.begin());
		int x = a.p, y = b.p;
		if (Si.count(x)) Si.erase(x);
		if (So.count(x)) So.erase(x);
		if (Si.count(y)) Si.erase(y);
		if (So.count(y)) So.erase(y);
		if (vi[x].size() && vo[y].size()) {
			add(y, x);
		} else if (vo[x].size() && vi[y].size()) {
			add(x, y);
		} else if (vo[x].size() && !Si.empty()) {
			int c = *Si.begin();
			Si.erase(Si.begin());
			Q.erase(Node(c));
			add(x, c);
			if (vi[c].size()) Si.insert(c);
			if (vi[c].size() || vo[c].size()) Q.insert(Node(c));
		} else if (vi[x].size() && !So.empty()) {
			int c = *So.begin();
			So.erase(So.begin());
			Q.erase(Node(c));
			add(c, x);
			if (vo[c].size()) So.insert(c);
			if (vi[c].size() || vo[c].size()) Q.insert(Node(c));
		} else {
			assert(false);
		}
		if (vi[x].size()) Si.insert(x);
		if (vo[x].size()) So.insert(x);
		if (vi[y].size()) Si.insert(y);
		if (vo[y].size()) So.insert(y);
		if (vi[x].size() || vo[x].size()) Q.insert(a);
		if (vi[y].size() || vo[y].size()) Q.insert(b);
//		for (auto x : Q)
//			cerr << x.p << " ";
//		cerr << '\n';
	}
	assert(Q.empty());
	printf("%lld\n", ans);
	for (int i = 1; i <= n; i++) {
		printf("%d ", res[i]);
	}
	return 0;
}